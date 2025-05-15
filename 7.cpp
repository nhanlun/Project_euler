#include <iostream>
#include <vector>

auto sieve(int n) -> std::vector<int> {
  std::vector<int> primes;
  std::vector<bool> isPrime(n, true);
  for (int i = 2; i < n; ++i) {
    if (isPrime[i]) {
      primes.push_back(i);
    }
    for (int64_t j = 1LL * i * i; j < n; j += i) {
      isPrime[j] = false;
    }
  }
  return primes;
}

int main() {
  std::cout << sieve(1000000)[10000] << '\n';
  return 0;
}