#include <iostream>
#include <map>
#include <set>
#include <vector>

auto sieve() -> std::pair<std::vector<long long>, std::vector<long long>> {
  int n = 100'000'000;
  std::vector<long long> prevPrimes(n + 1);
  std::vector<long long> primes;
  prevPrimes[0] = prevPrimes[1] = 1;

  for (long long i = 2; i <= n; ++i) {
    if (prevPrimes[i] == 0) {
      primes.push_back(i);
      prevPrimes[i] = i;
      for (long long j = i * i; j <= n; j += i) {
        if (prevPrimes[j] == 0) {
          prevPrimes[j] = i;
        }
      }
    }
  }
  return {primes, prevPrimes};
}

auto checkLegendre(
    long long m, const std::vector<std::pair<long long, long long>> &factors) {
  for (auto [p, e] : factors) {
    long long cur = p;
    long long curE = 0;
    for (int i = 1; cur <= m; ++i, cur *= p) {
      curE += m / cur;
    }
    if (curE < e) {
      return false;
    }
  }
  return true;
};

auto s(long long x, const std::vector<std::pair<long long, long long>> &factors)
    -> long long {
  long long res = 0;
  long long l = 1, r = x;
  while (l <= r) {
    long long mid = (l + r) / 2;
    if (checkLegendre(mid, factors)) {
      res = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  return res;
}

auto factorize(long long n, const std::vector<long long> &prevPrime)
    -> std::vector<std::pair<long long, long long>> {
  std::vector<std::pair<long long, long long>> factors;
  std::map<long long, long long> factorCount;
  while (n > 1) {
    factorCount[prevPrime[n]]++;
    n /= prevPrime[n];
  }
  for (const auto &[p, e] : factorCount) {
    factors.emplace_back(p, e);
  }
  return factors;
}

int main() {
  int n = 100'000'000;
  // int n = 100;
  auto [primes, prevPrime] = sieve();
  long long res = 0;
  for (int i = 2; i <= n; ++i) {
    if (prevPrime[i] == i) {
      res += i;
    } else {
      auto factors = factorize(i, prevPrime);
      if (factors.back().first > 1000) {
        for (long long j = 1, candidate = factors.back().first;;
             ++j, candidate += factors.back().first) {
          if (checkLegendre(candidate, factors)) {
            res += candidate;
            break;
          }
        }
      } else {
        res += s(i, factors);
      }
    }
    if (i % 1000000 == 0) {
      std::cout << i << " " << res << '\n';
    }
  }
  std::cout << res << '\n';
  return 0;
}

/*
s(2) = 2
s(3) = 3
s(4) = 4
s(5) = 5
s(6) = 3
s(7) = 7
s(8) = 4
s(9) = 6
s(10) = 5
s(11) = 11
s(12) = 4
s(13) = 13
s(14) = 7



*/
