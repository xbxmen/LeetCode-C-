// 199. 二叉树的右视图
// https://leetcode-cn.com/problems/binary-tree-right-side-view/
#include <iostream>
#include <queue>
#include <vector>

#include "TreeNode.h"

class Solution {
 public:
  vector<int> rightSideView(TreeNode* root) {
    vector<int> vec;
    if (root == nullptr) {
      return vec;
    }

    deque<TreeNode*> que;
    que.push_back(root);
    while (!que.empty()) {
      deque<TreeNode*> que_tmp;
      while (!que.empty()) {
        TreeNode* tmp = que.front();
        que.pop_front();
        if (que.empty()) {
          vec.push_back(tmp->val);
        }
        if (tmp->left != nullptr) {
          que_tmp.push_back(tmp->left);
        }
        if (tmp->right != nullptr) {
          que_tmp.push_back(tmp->right);
        }
      }

      que = que_tmp;
    }

    return vec;
  }
};

/**
  1
2   3



*/