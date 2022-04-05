// 剑指 Offer 27. 二叉树的镜像
// https://leetcode-cn.com/problems/er-cha-shu-de-jing-xiang-lcof/
#include <iostream>
#include <vector>

#include "TreeNode.h"

class Solution {
 public:
  TreeNode* mirrorTree(TreeNode* root) {
    if (root == nullptr) {
      return root;
    }

    TreeNode* left = mirrorTree(root->left);
    TreeNode* right = mirrorTree(root->right);

    root->left = right;
    root->right = left;

    return root;
  }
};
