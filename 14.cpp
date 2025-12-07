#include <iostream>
#include <map>

auto dfs(long long x, std::map<long long, long long> &visited) -> int {
  std::cout << x << std::endl;
  if (x == 1) {
    return visited[x] = 1;
  }
  if (visited[x] != 0) {
    return visited[x];
  }
  if (x & 1) {
    return visited[x] = dfs(x * 3 + 1, visited) + 1;
  } else {
    return visited[x] = dfs(x / 2, visited) + 1;
  }
}

int main() {
  int n = 1'000'000;
  long long res1 = 0;
  long long res2 = 0;
  // std::vector<int> visited(n * 1000 + 1, 0);
  std::map<long long, long long> visited;
  for (int i = 1; i <= n; ++i) {
    if (visited[i] == 0) {
      std::cout << "START " << i << ' ' << res1 << std::endl;
      auto tmp = dfs(i, visited);
      if (tmp > res1) {
        res1 = tmp;
        res2 = i;
      }
    }
  }
  std::cout << "res: " << res1 << ' ' << res2 << '\n';
  return 0;
}
/*
*/