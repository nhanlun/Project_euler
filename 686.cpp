#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

long long p(int cnt) {
  double pre1 = 1.23;
  double pre2 = 1.24;
  double l = std::log(pre1) / std::log(10);
  double r = std::log(pre2) / std::log(10);
  double magic = std::log(2) / std::log(10);
  double it = 90;
  double constArr[] = {196, 289, 485};
  --cnt;
  while (true) {
    for (auto i : constArr) {
      double cal = (it + i) * magic;
      double tmp = cal - std::floor(cal);
      if (tmp >= l && tmp < r) {
        std::cout << "it: " << it << " i: " << i << " tmp: " << tmp  << " cnt: " << cnt << std::endl;
        --cnt;
        it += i;
        break;
      }
    }
    if (cnt == 0) {
      return it;
    }
  }
}

int main() {
  // std::cout << std::fixed << std::setprecision(10) << p(100) << std::endl;
  std::cout << std::fixed << std::setprecision(10) << p(678910) << std::endl;
  return 0;
}

/*
196: 2 4 6 8 10 12
289: 1 3 7 9 11
485: 5 13 21 29 30 36 37 43 44 50 51 59 67



12 * 10^1 <= 2^m < 13 * 10^1

log(10, 1.2) + n <= m*log(10, 2) < log(10, 1.3) + n

0.079181246047625 + n <= m* 0.30102999566398 < 0.11394335230684 + n
2.079181246047625 <= m * 0.30102999566398 < 2.11394335230684



log(10, 1.23) = 0.089905111439398
log(10, 1.24) = 0.093421685162235
log(10, 2) =    0.30102999566398
0.00351657372


0.00102999566398


193060223

log(10, 1.2) = 0.079181246047625
log(10, 1.3) = 0.11394335230684
*/