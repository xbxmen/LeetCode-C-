struct ListNode {
  int value;
  ListNode* next;

  //构造函数
  ListNode(int value_l, ListNode* next_ptr = nullptr) {
    value = value_l;
    next = next_ptr;
  }
};