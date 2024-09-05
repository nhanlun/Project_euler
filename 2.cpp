#include <iostream>

int main() {
  int fib[50];
  fib[0] = 1;
  fib[1] = 1;
  int sum = 0;
  for (int i = 2; i < 40; ++i) {
    fib[i] = fib[i - 1] + fib[i - 2];
    if (fib[i] > 4'000'000) {
      break;
    }
    if (fib[i] % 2 == 0) {
      sum += fib[i];
    }
  }
  std::cout << sum << '\n';
  return 0;
}