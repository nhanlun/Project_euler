#include <iostream>
#include <vector>

auto sieve() -> std::vector<long long> {
  const long long N = 10'000'000;
  std::vector<bool> is_prime(N + 1, true);
  std::vector<long long> primes;
  is_prime[0] = is_prime[1] = false;

  for (long long i = 2; i <= N; ++i) {
    if (is_prime[i]) {
      for (long long j = i * i; j <= N; j += i) {
        is_prime[j] = false;
      }
      primes.push_back(i);
    }
  }
  return primes;
}

auto power(long long a, long long b) -> long long {
  if (b == 0) {
    return 1;
  }
  auto tmp = power(a, b / 2);
  return (b % 2 == 0) ? tmp * tmp : a * tmp * tmp;
}

auto mul(long long a, long long b, long long mod) -> long long {
  if (b == 1) {
    return a % mod;
  }
  auto tmp = mul(a, b / 2, mod);
  return b & 1 ? (tmp * 2 + a) % mod : (tmp * 2) % mod;
}

auto powmod(long long a, long long b, long long mod) -> long long {
  if (b == 0) {
    return 1;
  }
  auto tmp = powmod(a, b / 2, mod);
  return (b % 2 == 0) ? mul(tmp, tmp, mod) : mul(a, mul(tmp, tmp, mod), mod);
}

int main() {
  auto primes = sieve();
  int pos = 0;
  std::vector<long long> p(primes.size(), 1);
  for (int i = 500499; i > 0; --i) {
  // for (int i = 4; i >= 0; --i) {
    bool found = false;
    for (int j = 0; j < i; ++j) {
      auto tmp1 = power(primes[j], p[j] + 1);
      auto tmp2 = power(primes[j + 1], p[j + 1] + 1);
      if (tmp1 < tmp2 && tmp1 < primes[i]) {
        p[j] = p[j] * 2 + 1;
        found = true;
        break;
      }
    }
    if (!found) {
      pos = i;
      break;
    }
  }
  const long long MOD = 500'500'507;
  long long res = 1;
  for (int i = 0; i <= pos; ++i) {
    res = mul(res, powmod(primes[i], p[i], MOD), MOD);
    // std::cout << i << ' ' << primes[i] << " " << p[i] << std::endl;
  }
  std::cout << res << '\n';
  return 0;
}