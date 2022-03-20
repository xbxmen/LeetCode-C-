#include <iostream>
#include <map>
#include <vector>
using namespace std;

// 两数之和
// https://leetcode-cn.com/problems/two-sum/

// 复杂度 O(n2)
vector<int> twoSum1(vector<int>& nums, int target) {
  vector<int> result = {};

  for (int i = 0; i < nums.size(); i++) {
    for (int j = i + 1; j < nums.size(); j++) {
      if (nums[i] + nums[j] == target) {
        result = {i, j};
      }
    }
  }

  return result;
}

// 复杂度 O(n)
vector<int> twoSum2(vector<int>& nums, int target) {
  vector<int> result = {};
  map<int, int> numsMap;

  for (int i = 0; i < nums.size(); i++) {
    if (numsMap.count(target - nums[i]) > 0) {
      result = {numsMap[target - nums[i]], i};
      break;
    }

    numsMap[nums[i]] = i;
  }

  return result;
}

int main() {
  vector<int> nums = {1, 2, 3, 4, 7};
  vector<int> result = twoSum1(nums, 8);
  for (auto i : result) {
    cout << i << endl;
  }

  result = twoSum2(nums, 8);
  for (auto i : result) {
    cout << i << endl;
  }
  return 0;
}