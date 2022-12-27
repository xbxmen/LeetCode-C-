/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include "TreeNode.h"
#include <algorithm>

class Solution {
public:
  bool isBalanced(TreeNode *root) {
    if (root == nullptr) {
      return true;
    }

    return isBalanced(root->left) && isBalanced(root->right) &&
           abs(hight(root->left) - hight(root->right)) <= 1;
  }

  int hight(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }

    return std::max(hight(root->left), hight(root->right)) + 1;
  }
};