#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

vector<int> shuffle(vector<int>& a, vector<int>& b) {
  sort(a.begin(), a.end());
  for (auto i = a.begin(); i < a.end(); i++) {
    cout << *i << " ";
  }

  int count = a.size();

  map<int, int> index_map;
  for (int i = 0; i < count; i++) {
    index_map[b[i]] = i;
  }
  sort(b.begin(), b.end());

  vector<int> res(count);
  int left_b = 0;
  int right_b = count - 1;

  for (int i = 0; i < count; i++) {
    if (a[i] > b[left_b]) {
      res[index_map[b[left_b]]] = a[i];
      left_b++;
    } else {
      res[index_map[b[right_b]]] = a[i];
      right_b--;
    }
  }

  return res;
}

int main() {
  vector<int> a = {3, 9, 11, 5, 1};
  vector<int> b = {6, 4, 10, 8, 2};

  vector<int> res = shuffle(a, b);

  for (auto i = res.begin(); i < res.end(); i++) {
    cout << *i << " ";
  }

  return 0;
}
