#include <iostream>


int main() {
  int64_t inp = 600'851'475'143;
  int64_t Max = 0;
  for (int64_t i = 3; i * i <= inp; i += 2) {
    while (inp % i == 0) {
      inp /= i;
      Max = i;
    }
  }
  if (inp > Max) {
    Max = inp;
  }
  std::cout << Max << '\n';
  return 0;
}