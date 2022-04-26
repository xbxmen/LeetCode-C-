#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
  priority_queue<int, vector<int>, greater<int>> que;
  que.push(3);
  que.push(5);
  que.push(1);

  while (!que.empty()) {
    cout << que.top() << ' ';
    que.pop();
  }

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
}