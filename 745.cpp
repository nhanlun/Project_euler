#include <iostream>

long long mul(long long a, long long b, long long mod) {
  if (b == 1)
    return a % mod;
  auto tmp = mul(a, b / 2, mod);
  return b & 1 ? (tmp * 2 + a) % mod : (tmp * 2) % mod;
}

long long add(long long a, long long b, long long mod) { return (a + b) % mod; }

int main() {
  // const long long N = 100'000'000'000'000LL;
  const long long N = 10LL; 
  const long long MOD = 1000000007LL;
  long long cnt = 0;
  long long res = 0;
  // for (long long i = 10'000'000; i > 0; --i) {
  for (long long i = 10; i > 0; --i) {
    // if (N % i == 0) {
    // }
    long long x = N / (i * i);
    res = add(res, mul(x - cnt, i * i, MOD), MOD);
    cnt += x;
    std::cout << i << ' ' << cnt << ' ' << res << std::endl;
  }
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