#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
  string str;
  vector<int> numsA;

  string strA;
  getline(cin, strA);
  std::stringstream ss(strA);
  while (getline(ss, str, ',')) {
    int tmp = stoi(str);
    numsA.push_back(tmp);
  }

  for (auto v : numsA) {
    cout << v;
  }

  return 0;
}