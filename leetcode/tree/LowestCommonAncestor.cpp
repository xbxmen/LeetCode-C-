// 二叉树的最近公共祖先
// https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/

#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <stack>

#include "TreeNode.h"

using namespace std;

class Solution {
 public:
  // 1、查看当前root是否等于p 或 q
  // 2、如果不是，分别查看左节点是否有祖先、右节点是否有祖先
  // 3、如果左节点没有祖先，那肯定在右边节点
  // 4、如果右节点没有祖先，那肯定在左边节点
  // 5、如果两个都有祖先，那说明当前root是祖先
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr || root->val == p->val || root->val == q->val) {
      return root;
    }

    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);

    if (left == nullptr) {
      return right;
    }

    if (right == nullptr) {
      return left;
    }

    return root;
  }
};
int main() {}