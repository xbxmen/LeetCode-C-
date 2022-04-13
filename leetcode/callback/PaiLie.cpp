#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> res;

  void dfs(vector<int>& num, vector<bool>& used, vector<int>& path, int cur_index) {
    int count = num.size();
    if (cur_index == count) {
      res.push_back(path);
      return;
    }

    for (int i = 0; i < count; i++) {
      if (!used[i]) {
        path.push_back(num[i]);
        used[i] = true;
        dfs(num, used, path, cur_index + 1);

        used[i] = false;
        path.pop_back();
      }
    }
  }

  vector<vector<int>> permute(vector<int>& num) {
    int count = num.size();
    if (count == 0) {
      return res;
    }

    vector<int> path;
    vector<bool> used(num.size(), false);

    int cur_index = 0;
    dfs(num, used, path, cur_index);

    return res;
  }
};

int main() {}