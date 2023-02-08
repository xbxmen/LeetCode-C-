#include <iostream>
#include <ostream>
#include <string>
#include <vector>

using namespace std;

bool CheckAB(std::string str_a, std::string str_b) {
  vector<int> bit_map(26, 0);
  for (int i = 0; i < str_a.length(); i++) {
    bit_map[str_a[i]] = 1;

    cout << "111111111111111" << endl;
    cout << str_a[i] << endl;
    cout << int(str_a[i]) << endl;
    cout << bit_map[str_a[i]] << endl;
  }

  // for (int i = 0; i < bit_map.size(); i++) {
  //   cout << i << ":" << bit_map[i] << endl;
  // }

  cout << bit_map.size() << endl;
  for (int j = 0; j < str_b.length(); j++) {
    if (bit_map[str_b[j] % 26] != 1) {
      return false;
    }
  }

  return true;
}

int main() {

  std::string aa = "qwe";
  cout << aa[0] << endl;
  cout << int(aa[0]) << endl;

  vector<int> bit_map(26, 1);

  cout << bit_map[123] << endl;

  cout << CheckAB("qweee", "wwaw") << endl;

  return 0;
}
