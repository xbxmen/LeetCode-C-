#include <iostream>
#include <vector>

using namespace std;

// 【回溯】【leetcode】找出所有相加之和为 n 的 k 个数的组合

/**
题目：
找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9
的正整数，并且每种组合中不存在重复的数字。

说明：
所有数字都是正整数。
解集不能包含重复的组合。
例:
输入: k = 3, n = 7
输出: [[1,2,4]]
*/
class Solution {
public:
  vector<vector<int>> res;
  vector<int> path;

  void dfs(int target, int current, int k, int start) {
    if (target == current && path.size() == k) {
      res.push_back(path);
      return;
    }

    for (int i = start; i <= 9; i++) {
      if (current + i > target) {
        break;
      }
      path.push_back(i);
      current += i;
      dfs(target, current, k, i + 1);
      current -= i;
      path.pop_back();
    }
  }
};

int main() {
  Solution s;

  s.dfs(7, 0, 3, 0);
  vector<vector<int>> res = s.res;

  for (size_t i = 0; i < res.size(); i++) {
    vector<int> tmp = res[i];
    for (auto j = tmp.begin(); j < tmp.end(); j++) {
      cout << *j << " ";
    }
    cout << endl;
  }

  return 0;
}