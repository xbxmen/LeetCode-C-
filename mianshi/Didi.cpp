#include <iostream>

// 单例模式
class SingleIns {
 private:
  static SingleIns* ptr;

 protected:
  SingleIns(/* args */);
  ~SingleIns();

 public:
  static SingleIns* getInstance();
};

SingleIns::SingleIns(/* args */) {}

SingleIns::~SingleIns() {}

SingleIns* SingleIns::getInstance() {
  if (ptr == nullptr) {
    ptr = new SingleIns();
  }

  return ptr;
}

// 懒汉式

// 饿汉式

// LRUCache
LRuCache {
  // hashmap
  // 双向链表
  struct ListNode {
    /* data */
  };

 private:
  ListNode *l, r;
  unordered_map<int, ListNode*> hash;

  int n;
}

// 基类 指针
// 派生类的对象

// Father* a;
// a = new ChildA();
// a = new ChildB();
// a == ?

// 归并排序
// 1 2 3 4 5 6

merge(vector<int>, int left, int mid, int right) {}
mergesort(vector<int> num, int left, int right) {
  mergesort(num, 0, mid);
  mergesort(num, mid, right);
  merge(num, left, mid, right);
}

// 动态
// 定义每个元素的初始化状态
// 找到每个元素的一个状态转移公式
// 分别对每个元素进行状态转移

// 斐波那契额数列
// 1 2 3 4 5 6 7
// f(n) = f(n - 1) + f(n - 2);

// 初始化
dp[1] = 1;
dp[2] = 2;

// 公式
// f(n) = f(n - 1) + f(n - 2);

// 分别对每个元素进行状态转移，穷举
for (int i = 3; i < length; i++) {
  dp[] = dp[i - 1] + dp[i - 2]
}

// Redis
