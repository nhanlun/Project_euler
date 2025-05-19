#include <iostream>

auto numDivisors(long long n) -> long long {
  long long res = 0;
  for (long long i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      res += 2; // i and n/i
      if (i * i == n) {
        res--;
      }
    }
  }
  return res;
}

int main() {
  long long sum = 0;
  for (long long i = 1; i <= 1'000'000; i++) {
    sum += i;
    if (numDivisors(sum) >= 500) {
      std::cout << sum << '\n';
      break;
    }
  }
  return 0;
}