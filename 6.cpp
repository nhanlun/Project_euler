#include <iostream>

int main() {
  int res = 0;
  const int N = 100;
  for (int i = 1; i <= N; ++i) {
    for (int j = i + 1; j <= N; ++j) {
      res += 2 * i * j;
    }
  }
  std::cout << res << '\n';
  return 0;
}