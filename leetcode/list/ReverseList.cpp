#include <iosteam>

#include <stack>

#include "ListNode.h"

using namespace std;

// 双指针
ListNode* Reverse(ListNode* head) {
  ListNode* cur = nullptr;

  while (head != nullptr) {
    ListNode* next = head->next;
    head->next = cur;

    cur = head;
    head = next;
  }

  return cur;
}

// 递归
ListNode* Reverse2(ListNode* head) {
  ListNode* next = head->next;
  if (head == nullptr || head->next == nullptr) {
    return head;
  }

  ListNode* new_node = Reverse2(head->next);
  head->next->next = head;
  head->next = nullptr;

  return new_node;
}

// 栈
ListNode* Reverse3(ListNode* head) {
  stack<ListNode*> st;

  while (head != nullptr) {
    st.push(head);
    head = head->next;
  }

  if (!st.empty()) {
    head = st.pop();
  }
  ListNode* reverse = head;
  while (!st.empty()) {
    reverse->next = st.pop();
    reverse = reverse->next;
  }

  return head;
}

int main() {}