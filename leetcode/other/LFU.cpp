#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>
using namespace std;

/**
 * LFU (Least frequently used)
 * 最不经常使用，如果一个数据在最近一段时间内使用次数很少，那么在将来一段时间内被使用的可能性也很小。
 */

// 双链表节点
struct Node {
  int key, value;
  int frequency = 1;
  Node(int _key, int _value) : key(_key), value(_value) {}
};

class LFU {
private:
  /* data */
  int capacity; // 容量限制
  int size;     // 当前数据个数
  int minFreq;  // 当前最小频率

  unordered_map<int, Node *> keyMaps;
  unordered_map<int, list<Node *>> freqMaps;

  // 访问次数+1
  void freqPlus(Node *node);
  // 删除
  void remove();

public:
  LFU(const int &cap);
  ~LFU();

  int get(const int &key);

  void put(const int &key, const int &value);
};

LFU::LFU(const int &cap) {
  capacity = cap;
  size = 0;
  minFreq = 1;
}

LFU::~LFU() {}

// 获取某个key值
int LFU::get(const int &key) {
  Node *node = keyMaps[key];
  if (node == nullptr) {
    return -1;
  }

  freqPlus(node);
  return node->value;
}

// 添加元素
void LFU::put(const int &key, const int &value) {
  if (capacity <= 0) {
    return;
  }

  cout << "put: key=%d" << key << endl;
  cout << "size=%d" << size << endl;

  Node *node = keyMaps[key];
  if (node != nullptr) {
    node->value = value;
    freqPlus(node);
  } else {
    node = new Node(key, value);
    // 淘汰一个数据
    remove();

    // 新增数据并放到freq=1的队列里面
    keyMaps[key] = node;

    list<Node *> li = freqMaps[1];
    li.push_back(node);
    minFreq = 1;
    size++;

    freqMaps[minFreq] = li;
  }

  for (auto iter = keyMaps.begin(); iter != keyMaps.end(); iter++) {
    cout << "<" << iter->first << ", " << iter->second->value << ">" << endl;
  }
}

// 剔除元素
void LFU::remove() {
  if (size < capacity) {
    return;
  }

  list<Node *> li = freqMaps[minFreq];
  Node *del = li.front();
  li.pop_front();
  keyMaps.erase(del->key);
  size--;
}

void LFU::freqPlus(Node *node) {
  int freq = node->frequency;
  list<Node *> oldList = freqMaps[freq];
  oldList.remove_if([node](Node *val) { return (val->key == node->key); });
  if (minFreq == freq && oldList.empty()) {
    minFreq++;
  }
  freqMaps[freq] = oldList;

  // 把节点加到新的freq下面
  node->frequency++;
  list<Node *> newList = freqMaps[node->frequency];
  newList.push_back(node);
  freqMaps[node->frequency] = newList;
}

void bianli(const list<Node *> li) {
  cout << "bianli start" << endl;
  for (auto it = li.begin(); it != li.end(); ++it) {
    Node *ok = *it;
    std::cout << ' ' << ok->key;
  }
  cout << endl;
  cout << "bianli end" << endl;
}

int main() {
  LFU lfu(2);

  int key = 111;
  int value = 111;
  lfu.put(key, value);

  cout << "-------------" << endl;

  key = 222;
  value = 222;
  lfu.put(key, value);
  cout << "-------------" << endl;

  lfu.get(111);
  lfu.get(111);

  cout << "-------------" << endl;

  key = 33;
  value = 33;
  lfu.put(key, value);

  return 0;
}