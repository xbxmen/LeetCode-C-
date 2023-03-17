#include <iostream>
#include <vector>

using namespace std;

/**
题目：合成数

描述：
给定20个正整数Ai（1<=i<=20）
若 正整数n = 1 * K1 + 2 * K2 + 3 * K3 + ...... + 20 * K20 (0 <= Ki <=
Ai且Ki为整数)， 则称n为合成数

输入：20个正整数Ai，正整数n
输出：n是否为合成数
 */
bool dfs(vector<int> nums, int target) {
  if (target == 0) {
    return true;
  }

  int index = 0;
  while (index < 20) {
    int cur = index + 1;

    if (nums[index] > 0 && target - cur >= 0) {
      nums[index] -= 1;
      if (dfs(nums, target - cur)) {
        return true;
      }

      nums[index] += 1;
    }

    index++;
  }

  return false;
}

void IsCombination(vector<int> nums, int target) {
  cout << "target: " << target << ", result: " << dfs(nums, target) << endl;
}

int main() {
  // 测试用例
  vector<int> nums(20, 0);
  nums[4] = 1;
  nums[5] = 1;
  nums[9] = 1;

  cout << "nums：" << endl;
  for (auto v : nums) {
    cout << v << " ";
  }

  cout << endl;
  cout << "case：" << endl;
  IsCombination(nums, 2);
  IsCombination(nums, 3);
  IsCombination(nums, 5);
  IsCombination(nums, 6);
  IsCombination(nums, 8);
  IsCombination(nums, 9);
  IsCombination(nums, 11);
  IsCombination(nums, 19);
}