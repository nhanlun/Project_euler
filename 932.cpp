#include <cmath>
#include <iostream>
#include <sstream>

auto calc(long long a, long long b) -> long long {
  std::stringstream ss;
  ss << a << b;
  long long res;
  ss >> res;
  return res;
}

auto getPow(long long n) -> long long {
  long long res = 1;
  while (n) {
    res *= 10;
    n /= 10;
  }
  return res;
}

int main() {
  long long res = 0;
  for (long long i = 1; i < 100'000'000; i++) {
    if (i % 1000000 == 0) {
      std::cerr << i << std::endl;
    }
    long long a = 1;
    long long b = i * 2 - getPow(i);
    long long c = i * (i - 1);
    long long delta = b * b - 4 * a * c;

    if (delta < 0) {
      continue;
    }
    if (delta == 0) {
      long long x = -b / (2 * a);
      auto tmp = calc(x, i);
      if (tmp == (x + i) * (x + i) && x > 0) {
        res += tmp;
        std::cerr << "Found: " << x << " " << i << std::endl;
      }
    } else {
      long long sqrt_delta = std::sqrt(delta);
      if (sqrt_delta * sqrt_delta != delta) {
        continue;
      }
      long long x1 = (-b + sqrt_delta) / (2 * a);
      long long x2 = (-b - sqrt_delta) / (2 * a);
      auto tmp1 = calc(x1, i);
      if (tmp1 == (x1 + i) * (x1 + i) && x1 > 0) {
        res += tmp1;
        std::cerr << "Found: " << x1 << " " << i << std::endl;
      }
      auto tmp2 = calc(x2, i);
      if (tmp2 == (x2 + i) * (x2 + i) && x2 > 0) {
        res += tmp2;
        std::cerr << "Found: " << x2 << " " << i << std::endl;
      }
    }
  }
  std::cout << res << std::endl;
  return 0;
}

/*

(a + b) ^ 2 = a^2 + b^2 + 2ab

__
ab = a * 100 + b = a^2 + b^2 + 2ab
0 = a^2 - 100a + b^2 - b + 2ab
b^2 - b = 100a - a^2 - 2ab
b - 1 = 100a/b - a^2/b - 2a

24 = 120 - 36 - 60

=> 100a and a^2 is divisible by b


b^2 - b = 100a - a^2 - 2ab

a^2 - 100a + 2ab + b^2 - b = 0
a^2 + a(2b - 100) + b^2 - b = 0

30 25


delta = b^2 - 4ac

x1 = (-b + sqrt(delta)) / 2a

*/