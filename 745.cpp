#include <cmath>
#include <iostream>
#include <map>
#include <vector>

long long mul(long long a, long long b, long long mod) {
  if (b == 1)
    return a % mod;
  auto tmp = mul(a, b / 2, mod);
  return b & 1 ? (tmp * 2 + a) % mod : (tmp * 2) % mod;
}

long long add(long long a, long long b, long long mod) { return (a + b) % mod; }

int main() {
  const long long N = 100'000'000'000'000LL;
  // const long long N = 100LL;
  const long long MOD = 1'000'000'007LL;
  long long cnt = 0;
  long long res = 0;
  long long n = sqrt(N);
  std::vector<long long> num(n + 1, 0);
  for (long long i = n; i > 1; --i) {
    if (i % 100'000 == 0) {
      std::cout << i << ' ' << cnt << ' ' << res << std::endl;
    }
    long long x = N / (i * i);
    for (long long j = i * 2; j <= n; j += i) {
      x -= num[j];
    }
    num[i] = x;
    cnt += x;
    res = add(res, mul(x, i * i, MOD), MOD);
  }
  res = add(res, N - cnt, MOD);
  std::cout << res << std::endl;
  return 0;
}
/*
1 1
2 1
3 1
4 4
5 1
6 1
7 1
8 4
9 9
10 1
*/