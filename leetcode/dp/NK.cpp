// 剑指 Offer 60. n 个骰子的点数（动态规划，清晰图解）
// https://leetcode.cn/problems/nge-tou-zi-de-dian-shu-lcof/solution/jian-zhi-offer-60-n-ge-tou-zi-de-dian-sh-z36d/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// 输入: 2
// 输出:
// [0.02778,0.05556,0.08333,0.11111,0.13889,0.16667,0.13889,0.11111,0.08333,0.05556,0.02778]
// 来源：力扣（LeetCode）
// 链接：https://leetcode.cn/problems/nge-tou-zi-de-dian-shu-lcof
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

/**
 * @brief NK问题
 *
 * @param n
 * @return vector<double>
 */
vector<double> NToK(int n) {
  vector<double> dp(6, 1.0 / 6.0);
  for (int i = 2; i <= n; i++) {
    vector<double> tmp(n * 5 + 1, 0.0);

    for (int j = 0; j < dp.size(); j++) {
      for (int k = 0; k < 6; k++) {
        tmp[j + k] += dp[j] / 6.0;
      }
    }

    dp = tmp;
  }

  return dp;
}

int main() {

  vector<double> dp = NToK(2);
  for (auto dd : dp) {
    cout << dd << " ";
  }

  return 0;
}