
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <stack>

#include "TreeNode.h"

using namespace std;
// 二叉树遍历

/**
 * 前序遍历
 */
// 递归遍历
vector<int> preorderTraversal(TreeNode* root) {
  vector<int> vec;
  preOrder(root, vec);

  return vec;
}

void preOrder(TreeNode* root, vector<int>& vec) {
  if (root == nullptr) {
    return;
  }

  vec.push_back(root->val);
  preOrder(root->left, vec);
  preOrder(root->right, vec);
}

// 非递归遍历
vector<int> preorderTraversal2(TreeNode* root) {
  vector<int> vec;
  if (root == nullptr) {
    return vec;
  }

  stack<TreeNode*> st;
  st.push(root);
  while (!st.empty()) {
    TreeNode* tmp = st.top();
    st.pop();
    vec.push_back(tmp->val);

    if (tmp->right != nullptr) {
      st.push(tmp->right);
    }

    if (tmp->left != nullptr) {
      st.push(tmp->left);
    }
  }

  return vec;
}

/**
 * 中序遍历
 */
// 递归遍历
vector<int> inorderTraversal(TreeNode* root) {
  vector<int> vec;
  inOrder(root, vec);

  return vec;
}

void inOrder(TreeNode* root, vector<int>& vec) {
  if (root == nullptr) {
    return;
  }
  inOrder(root->left, vec);
  vec.push_back(root->val);
  inOrder(root->right, vec);
}

// 非递归遍历
vector<int> inorderTraversal2(TreeNode* root) {
  vector<int> vec;
  stack<TreeNode*> st;

  TreeNode* cur = root;
  while (cur != nullptr || !st.empty()) {
    while (cur != nullptr) {
      st.push(cur);
      cur = cur->left;
    }

    if (!st.empty()) {
      cur = st.top();
      st.pop();
      vec.push_back(cur->val);
    }
    cur = cur->right;
  }

  return vec;
}

/**
 * 后序遍历
 */
// 递归遍历
vector<int> postorderTraversal(TreeNode* root) {
  vector<int> vec;
  postOrder(root, vec);

  return vec;
}

void postOrder(TreeNode* root, vector<int>& vec) {
  if (root == nullptr) {
    return;
  }

  postOrder(root->left, vec);
  postOrder(root->right, vec);
  vec.push_back(root->val);
}

// 非递归遍历
// 将前序遍历 逆转
// 中左右 -> 中右左 -> 左右中
vector<int> postorderTraversal2(TreeNode* root) {
  vector<int> vec;
  if (root == nullptr) {
    return vec;
  }

  stack<TreeNode*> st;
  st.push(root);
  while (!st.empty()) {
    TreeNode* tmp = st.top();
    st.pop();
    vec.push_back(tmp->val);

    if (tmp->left != nullptr) {
      st.push(tmp->left);
    }

    if (tmp->right != nullptr) {
      st.push(tmp->right);
    }
  }

  reverse(vec.begin(), vec.end());

  return vec;
}

/**
 * 层序遍历
 */
vector<int> levelTraverasal(TreeNode* root) {
  vector<int> vec;
  if (root == nullptr) {
    return vec;
  }

  queue<TreeNode*> que;

  que.push(root);
  while (!que.empty()) {
    TreeNode* tmp = que.front();
    que.pop();
    vec.push_back(tmp->val);

    if (tmp->left != nullptr) {
      que.push(tmp->left);
    }

    if (tmp->right != nullptr) {
      que.push(tmp->right);
    }
  }

  return vec;
}

int main() {
  cout << abs(3 - 8);

  cout << max(1, 3);
  return 0;
}