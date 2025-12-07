#include <iostream>

using namespace std;

long long arr[105][105];

int main() {
  arr[0][0] = 1;
  for (int i = 1; i <= 100; ++i) {
    arr[i][0] = 1;
  }
  int res = 0;
  for (int i = 1; i <= 100; ++i) {
    for (int j = 1; j <= 100; ++j) {
      arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
      if (arr[i][j] > 2e9) {
        arr[i][j] = 2e9;
      }
      if (arr[i][j] > 1000000) {
        ++res;
      }
    }
  }
  cout << res;
  return 0;
}