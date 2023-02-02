// 199. 二叉树的右视图
// https://leetcode-cn.com/problems/binary-tree-right-side-view/
#include <iostream>
#include <queue>
#include <vector>

#include "TreeNode.h"

using namespace std;

class Solution {
public:
  vector<int> rightSideView(TreeNode *root) {
    vector<int> ret;
    if (root == nullptr) {
      return ret;
    }

    deque<TreeNode *> que;
    que.push_back(root);
    while (!que.empty()) {
      deque<TreeNode *> que_tmp;
      while (!que.empty()) {
        TreeNode *tmp = que.front();
        que.pop_front();
        if (que.empty()) {
          ret.push_back(tmp->val);
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

    return ret;
  }
};

/**
  1
2   3
*/