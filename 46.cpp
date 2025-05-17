#include <cmath>
#include <iostream>

auto isComposite(int n) -> bool {
  if (n < 2) {
    return false;
  }
  for (int i = 2; i <= sqrt(n); ++i) {
    if (n % i == 0) {
      return true;
    }
  }
  return false;
}

int main() {
  for (int i = 9; i <= 10000; i += 2) {
    if (!isComposite(i)) {
      continue;
    }
    bool found = false;
    for (int j = 1; j * j < i; ++j) {
      auto tmp = i - j * j * 2;
      if (tmp < 0) {
        break;
      }
      if (!isComposite(tmp)) {
        found = true;
        break;
      }
    }
    if (!found) {
      std::cout << i << std::endl;
      break;
    }
  }
  return 0;
}