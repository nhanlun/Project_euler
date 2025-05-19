#include <iostream>
#include <queue>
#include <set>

long long mul(long long a, long long b, long long mod) {
  if (b == 1) {
    return a % mod;
  }
  auto tmp = mul(a, b / 2, mod);
  return b & 1 ? (tmp * 2 + a) % mod : (tmp * 2) % mod;
}

int main() {
  long long n = 1504170715041707LL;
  long long base = 1504170715041707LL;
  long long MOD = 4503599627370517LL;
  // std::set<long long> m;
  // m.insert(n);
  // long long sum = n;
  // long long Min = n;
  // while (true) {
  //   n = (n + base) % MOD;
  //   if (m.find(n) == m.end()) {
  //     m.insert(n);
  //   } else {
  //     break;
  //   }
  //   if (n < Min) {
  //     Min = n;
  //     sum += n;
  //     std::cout << n << ' ' << Min << ' ' << sum << ' ' << m.size() <<
  //     std::endl;
  //   }
  //   if (Min < 1) {
  //     break;
  //   }
  //   if (m.size() % 1000000 == 0) {
  //     std::cout << n << ' ' << Min << ' ' << sum << ' ' << m.size() <<
  //     std::endl;
  //   }
  //   // std::cout << n << ' ' << Min << ' ' << sum << ' ' << m.size() <<
  //   std::endl;
  // }

  // 15806432 1517926220024813
  // modulo inverse = 3451657199285664
  long long inverse = 3451657199285664LL;
  long long cur = inverse;
  long long sum = 1517926220024813LL;
  for (long long i = 2; i < 15806432LL; ++i) {
    auto pos = mul(inverse, i, MOD);
    if (pos < cur) {
      std::cout << i << ' ' << pos << ' ' << cur << ' ' << sum << std::endl;
      cur = pos;
      sum += i;
    }
  }
  std::cout << sum + 1 << std::endl;
  return 0;
}