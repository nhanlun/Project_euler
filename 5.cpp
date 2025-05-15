#include <iostream>

int gcd(int x, int y) {
  if (y == 0) {
    return x;
  }
  return gcd(y, x % y);
}

int lcm(int x, int y) { return x / gcd(x, y) * y; }

int main() {
  int res = 1;
  for (int i = 1; i <= 20; ++i) {
    res = lcm(res, i);
  }
  std::cout << res << '\n';
  return 0;
}