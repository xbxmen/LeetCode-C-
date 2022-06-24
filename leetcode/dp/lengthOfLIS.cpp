#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// 300. 最长递增子序列
// https://leetcode.cn/problems/longest-increasing-subsequence/

int lengthOfLIS(vector<int>& nums) {
  int n = (int)nums.size();
  if (n == 0) {
    return 0;
  }

  vector<int> dp(n, 0);
  for (int i = 0; i < n; i++) {
    dp[i] = 1;
    for (int j = 0; j < i; j++) {
      if (nums[i] > nums[j]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
  }

  return *max_element(dp.begin(), dp.end());
}

int main() {
  vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

  cout << lengthOfLIS(nums);

  return 0;
}