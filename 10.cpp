#include <bitset>
#include <execution>
#include <iostream>
#include <vector>

constexpr int64_t N = 100'000'000;
// constexpr int64_t N = 50'000;
std::bitset<N> isPrime;

auto sieve() -> std::vector<int64_t> {
  std::vector<int64_t> primes;
  isPrime.set();
  for (int64_t i = 2; i < N; i = isPrime._Find_next(i)) {
    primes.push_back(i);
    for (int64_t j = i * i; j < N; j += i) {
      isPrime[j] = false;
    }
  }
  return primes;
}

int main() {
  const int64_t inp = 2'000'000'000;
  auto primes = sieve();
  auto res = std::reduce(std::execution::par, primes.begin(), primes.end());
  std::cout << "primes size: " << primes.size() << '\n';
  std::cout << "init res: " << res << '\n';
  for (int64_t i = primes.back() + 2; i < inp; i += 2) {
    bool check = true;
    for (size_t j = 0; j < primes.size() && primes[j] * primes[j] <= i; ++j) {
      if (i % primes[j] == 0) {
        check = false;
        break;
      }
    }
    if (check) {
      res += i;
    }
  }
  std::cout << res << '\n';
  return 0;
}