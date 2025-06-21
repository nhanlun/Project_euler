#include <iostream>
#include <sstream>

bool check(int x) {
  std::stringstream ss;
  ss << x;
  std::string s = ss.str();

  bool isIncreasing = true;
  for (int i = 1; i < s.size(); ++i) {
    if (s[i] < s[i - 1]) {
      isIncreasing = false;
      break;
    }
  }
  bool isDecreasing = true;
  for (int i = 1; i < s.size(); ++i) {
    if (s[i] > s[i - 1]) {
      isDecreasing = false;
      break;
    }
  }
  return !isIncreasing && !isDecreasing;
}

int main() {
  long long cnt = 0;
  for (long long i = 101; i < 2000'000'000; ++i) {
    if (check(i)) {
      ++cnt;
      // std::cout << i << " " << cnt << std::endl;
    }
    if (i * 99 / 100 == cnt && cnt * 100 / 99 == i) {
      std::cout << i << " " << cnt << std::endl;
      return 0;
    }
    if (i * 90 / 100 == cnt && cnt * 100 / 90 == i) {
      std::cout << i << " " << cnt << std::endl;
    }
  }
  return 0;
}