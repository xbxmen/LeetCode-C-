// 剑指 Offer 28. 对称的二叉树
// https://leetcode-cn.com/problems/dui-cheng-de-er-cha-shu-lcof/

#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <stack>

#include "TreeNode.h"

struct TreeNo {
  int val;

  TreeNo* left;

  TreeNo* right;
  TreeNo() : val(0), left(nullptr), right(nullptr);
  TreeNo(int v, TreeNo* left, TreeNo* right) : val(v), left(left), right(right);
};

using namespace std;

class Solution {
 public:
  bool isSymmetric(TreeNode* root) {
    if (root == nullptr) {
      return true;
    }

    return isOk(root->left, root->right);
  }

  bool isOk(TreeNode* left, TreeNode* right) {
    if (left == nullptr && right == nullptr) {
      return true;
    }

    if (left == nullptr && right != nullptr) {
      return false;
    }

    if (left != nullptr && right == nullptr) {
      return false;
    }

    if (left->val != right->val) {
      return false;
    }

    bool bLeft = isOk(left->left, right->right);
    bool bRight = isOk(left->right, right->left);

    if (bLeft && bRight) {
      return true;
    } else {
      return false;
    }
  }
};