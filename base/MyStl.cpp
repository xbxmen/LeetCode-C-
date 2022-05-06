#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

void display(vector<int>& array) {
  for (auto v : array) {
    cout << v << " ";
  }
  cout << endl;
}

int main() {
  priority_queue<int, vector<int>, greater<int>> que;
  // priority_queue<int, vector<int>, less<int>> que;
  que.push(3);
  que.push(5);
  que.push(1);
  while (!que.empty()) {
    cout << que.top() << ' ';
    que.pop();
  }
  cout << endl;

  unordered_map<int, int> ok;
  ok[123] = 123;
  ok[12] = 12;
  for (auto iter = ok.begin(); iter != ok.end(); iter++) {
    cout << "<" << iter->first << ", " << iter->second << ">" << endl;
  }

  ok.erase(12);
  for (auto iter = ok.begin(); iter != ok.end(); iter++) {
    cout << "<" << iter->first << ", " << iter->second << ">" << endl;
  }

  vector<int> values = {3, 6, 8, 1, 2, 3, 4, 9};
  make_heap(values.begin(), values.end());
  display(values);

  cout << "添加元素：\n";
  values.push_back(5);
  display(values);
  push_heap(values.begin(), values.end());
  display(values);

  //移除元素
  cout << "移除元素：\n";
  pop_heap(values.begin(), values.end());  //{4,2,3,1,5}
  display(values);
  values.pop_back();
  display(values);
}