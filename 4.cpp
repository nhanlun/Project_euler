#include <iostream>
#include <sstream>

int main() {
  auto check = [](int x){
    std::stringstream ss;
    ss << x;
    auto s = ss.str();
    for (size_t i = 0; i < s.size(); ++i) {
      if (s[i] != s[s.size() - i - 1]) {
        return false;
      }
    }
    return true;
  };
  int res = 0;
  for (int i = 100; i < 1000; ++i) {
    for (int j = 100; j < 1000; ++j) {
      int tmp = i * j;
      if (check(tmp)) {
        res = std::max(res, tmp);
      }
    }
  }
  std::cout << res << '\n';
  return 0;
}