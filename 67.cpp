#include <array>
#include <fstream>
#include <iostream>
#include <sstream>

int main() {
  std::ifstream file("67.input");
  std::string s;
  std::array<std::array<int, 100>, 100> arr{};
  std::array<std::array<int, 100>, 100> f{};
  int cnt = 0;
  while (std::getline(file, s)) {
    std::istringstream iss2(s);
    for (int i = 0; i <= cnt; ++i) {
      iss2 >> arr[cnt][i];
    }
    ++cnt;
  }
  f[0][0] = arr[0][0];
  for (int i = 1; i < cnt; ++i) {
    f[i][0] = f[i - 1][0] + arr[i][0];
    for (int j = 1; j < cnt; ++j) {
      f[i][j] = std::max(f[i - 1][j], f[i - 1][j - 1]) + arr[i][j];
    }
  }
  int res = 0;
  for (int i = 0; i < cnt; ++i) {
    res = std::max(res, f[cnt - 1][i]);
  }
  std::cout << res << '\n';
  return 0;
}