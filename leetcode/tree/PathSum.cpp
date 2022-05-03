// 剑指 Offer 34. 二叉树中和为某一值的路径
// https://leetcode-cn.com/problems/er-cha-shu-zhong-he-wei-mou-yi-zhi-de-lu-jing-lcof/

#include <iostream>
#include <vector>

#include "TreeNode.h"

// 思路
class Solution {
 public:
  vector<vector<int>> ret;
  vector<int> path;

  Solution() {
    ret = {};
    path = {};
  }

  // 深度优先遍历
  // 遍历到叶子节点停止，如果到当前叶子节点的和为target，则将整体路径放入到结果中
  void dfs(TreeNode* root, int target) {
    if (root == nullptr) {
      return;
    }
    
    path.emplace_back(root->val);
    target -= root->val;
    if (root->left == nullptr && root->right == nullptr && target == 0) {
      ret.emplace_back(path);
    }
    dfs(root->left, target);
    dfs(root->right, target);
    path.pop_back();
  }

  vector<vector<int>> pathSum(TreeNode* root, int target) {
    dfs(root, target);
    return ret;
  }
};