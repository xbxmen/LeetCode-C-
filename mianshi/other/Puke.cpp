#include <iostream>
#include <list>
#include <vector>

using namespace std;

vector<int> res;

void puke(list<int>& p, bool flag) {
  if (p.empty()) {
    return;
  }

  if (flag) {
    res.push_back(p.front());
    p.pop_front();
  } else {
    p.push_back(p.front());
    p.pop_front();
  }

  puke(p, !flag);
}

int main() {
  list<int> p = {1, 2, 3, 4, 5};
  puke(p, true);
  for (auto val : res) {
    cout << val << " ";
  }
}