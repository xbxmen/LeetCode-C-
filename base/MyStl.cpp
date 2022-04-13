#include <iostream>
#include <queue>
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
}