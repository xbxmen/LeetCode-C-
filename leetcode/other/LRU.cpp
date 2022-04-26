#include <unordered_map>

using namespace std;

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

class LRUCache {
 private:
  //定义双向链表
  struct Node {
    int key, value;
    Node *left, *right;
    Node(int _key, int _value) : key(_key), value(_value), left(nullptr), right(nullptr) {}
  } * L, *R;  //双链表的最左和最右节点，不存贮值。

  // 容量
  int n;

  // 无须关联容器
  unordered_map<int, Node*> hash;

  void remove(Node* p) {
    p->right->left = p->left;
    p->left->right = p->right;
  }

  void insert(Node* p) {
    p->right = L->right;
    p->left = L;
    L->right->left = p;
    L->right = p;
  }

 public:
  LRUCache(int capacity) {
    n = capacity;
    L = new Node(-1, -1), R = new Node(-1, -1);
    L->right = R;
    R->left = L;
  }

  int get(int key) {
    if (hash.count(key) == 0) return -1;  //不存在关键字 key
    auto p = hash[key];
    remove(p);
    insert(p);  //将当前节点放在双链表的第一位
    return p->value;
  }

  void put(int key, int value) {
    if (hash.count(key))  //如果key存在，则修改对应的value
    {
      auto p = hash[key];
      p->value = value;
      remove(p);
      insert(p);
    } else {
      if (hash.size() == n)  //如果缓存已满，则删除双链表最右侧的节点
      {
        auto p = R->left;
        remove(p);
        hash.erase(p->key);  //更新哈希表
        delete p;            //释放内存
      }
      //否则，插入(key, value)
      auto p = new Node(key, value);
      hash[key] = p;
      insert(p);
    }
  }
};

int main() {}