#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> res;

  void dfs(vector<int>& nums, vector<int>& path, int cur_index) {
    int count = nums.size();
    res.push_back(path);

    for (int i = cur_index; i < count; i++) {
      if (i > cur_index && nums[i] == nums[i - 1])  //剪枝去重
        continue;
      path.push_back(nums[i]);
      dfs(nums, path, cur_index + 1);
      path.pop_back();
    }
  }

  vector<vector<int>> subsets(vector<int>& nums) {
    vector<int> path;
    int cur_index = 0;
    dfs(nums, path, cur_index);

    return res;
  }
};

int main() {}