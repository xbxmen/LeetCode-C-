#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(){};
  ListNode(int value) : val(value){};
};

// 1 2 3 4 5
// 2
void DeleteList(ListNode *head, int n) {

  if (head == nullptr) {
    return;
  }

  ListNode *pre = new ListNode(-1);
  pre->next = head;

  ListNode *fast = head;
  while (n > 0 && fast != nullptr) {
    fast = fast->next;
    n--;
  }

  if (n > 0) {
    return;
  }

  while (fast != nullptr) {
    pre = pre->next;
    fast = fast->next;
  }
  pre->next = pre->next->next;
}

int main() {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);

  DeleteList(head, 2);

  while (head != nullptr) {
    cout << head->val << " ";
    head = head->next;
  }

  return 0;
}