#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

/**
 * @brief 剑指 Offer 14- I. 剪绳子
 * https://leetcode.cn/problems/jian-sheng-zi-lcof/
 * @param n
 * @return int
 */
int CuttingRope(int n) {
  int result = 0;

  std::vector<int> dp(n + 1);
  dp[2] = 1;
  for (int i = 3; i <= n; i++) {
    for (int j = 1; j < i; j++) {
      int tmp = std::max(dp[i - j] * j, (i - j) * j);
      dp[i] = std::max(dp[i], tmp);
    }
  }

  return dp[n];
}

int main() {
  cout << "3: " << CuttingRope(3) << endl;
  cout << "4: " << CuttingRope(4) << endl;
  cout << "5: " << CuttingRope(5) << endl;
  cout << "6: " << CuttingRope(6) << endl;

  return 0;
}