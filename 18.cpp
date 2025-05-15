#include <array>
#include <iostream>
#include <sstream>

int main() {
  std::string inp = R"(75
95 64
17 47 82
18 35 87 10
20 04 82 47 65
19 01 23 75 03 34
88 02 77 73 07 63 67
99 65 04 28 06 16 70 92
41 41 26 56 83 40 80 70 33
41 48 72 33 47 32 37 16 94 29
53 71 44 65 25 43 91 52 97 51 14
70 11 33 28 77 73 17 78 39 68 17 57
91 71 52 38 17 14 91 43 58 50 27 29 48
63 66 04 68 89 53 67 30 73 16 69 87 40 31
04 62 98 27 23 09 70 98 73 93 38 53 60 04 23)";
  std::istringstream iss(inp);
  std::string s;
  std::array<std::array<int, 100>, 100> arr{};
  std::array<std::array<int, 100>, 100> f{};
  int cnt = 0;
  while (std::getline(iss, s)) {
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
  for (int i = 0; i < cnt; ++i) {
    for (int j = 0; j < cnt; ++j) {
      std::cout << f[i][j] << ' ';
    }
    std::cout << '\n';
  }
  return 0;
}