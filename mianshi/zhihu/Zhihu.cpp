#include <cstddef>
using namespace std;

struct ListNode {
  int val;
  ListNode *left, *right;
  ListNode(){};
  ListNode(int v) : val(v){};
};

class DList {

private:
  ListNode *head, *tail;

public:
  DList() {
    head = new ListNode();
    tail = new ListNode();
    head->right = tail;
    tail->left = head;
    tail->right = nullptr;
  }
  ~DList() {}

  void add(int val) {
    ListNode *n = new ListNode(val);

    n->right = tail;
    tail->left->right = n;
    tail = tail->right;
  };

  void del(int val) {
    ListNode *tmp = head->right;
    while (tmp != nullptr) {
      if (tmp->val == val) {
        tmp->left->right = tmp->right;
        break;
      }

      tmp = tmp->right;
    }
  };
};