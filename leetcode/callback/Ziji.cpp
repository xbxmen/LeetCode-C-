#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> res;

  void dfs(vector<int> &nums, vector<int> &path, int cur_index) {
    int count = nums.size();
    res.push_back(path);

    for (int i = cur_index; i < count; i++) {
      if (i > cur_index && nums[i] == nums[i - 1]) //剪枝去重
        continue;
      path.push_back(nums[i]);
      cur_index++;
      dfs(nums, path, cur_index);
      path.pop_back();
    }
  }

  vector<vector<int>> subsets(vector<int> &nums) {
    vector<int> path;
    int cur_index = 0;
    dfs(nums, path, cur_index);

    return res;
  }
};

int main() {
  Solution s;
  vector<vector<int>> res;

  vector<int> nums = {1, 2, 3, 4, 5};
  // res = s.subsets(nums);

  res.push_back({});
  // 递增处理
  // 0 01 | 02 012 | 03 013 023 0123
  for (int i = 0; i < nums.size(); i++) {
    int count = res.size();
    for (int j = 0; j < count; j++) {
      vector<int> tmp = res[j];
      tmp.push_back(nums[i]);
      res.push_back(tmp);
    }
  }

  for (size_t i = 0; i < res.size(); i++) {
    vector<int> tmp = res[i];
    for (auto j = tmp.begin(); j < tmp.end(); j++) {
      cout << *j << " ";
    }
    cout << endl;
  }
}

/**
1 2 3 4
*/