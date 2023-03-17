#include <iostream>
#include <vector>

using namespace std;

// 岗位：运维部-平台研发工程师
// 题目：最多子数组和
// 姓名：赵红帅
// 时间：2022-02-10

// 1 2 -3 4 5
int MaxSubArray(vector<int> nums) {
  if (nums.size() == 0) {
    return 0;
  }

  vector<int> dp(nums.size());
  int result = nums[0];
  dp[0] = nums[0];
  for (int i = 1; i < nums.size(); i++) {
    dp[i] = max(dp[i - 1] + nums[i], nums[i]);
    result = max(dp[i], result);
  }

  return result;
};

int main() {

  vector<int> nums = {1, 2, -3, 4, 5};
  cout << MaxSubArray(nums) << endl;
  nums = {1, 2, 2, -3, 4, 5};
  cout << MaxSubArray(nums) << endl;

  return 0;
}