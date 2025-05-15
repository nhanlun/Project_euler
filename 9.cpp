#include <iostream>

int main() {
  const int N = 500;
  for (int i = 2; i <= N; ++i) {
    if (N % i == 0) {
      auto j = N / i - i;
      if (i > j && j > 0) {
        std::cout << i << ' ' << j << ' '
                  << (i * i * i * i - j * j * j * j) * 2 * i * j << '\n';
      }
    }
  }
  return 0;
}
/*
a = m^2 - n^2
b = 2mn
c = m^2 + n^2
m > n > 0

a + b + c = 2m^2 + 2mn = 1000
<=> m(m + n) = 500

abc = (m^2 - n^2)(m^2 + n^2)*2mn = (m^4 - n^4) * 2mn
*/