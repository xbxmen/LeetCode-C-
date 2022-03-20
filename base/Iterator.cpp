#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> vectr{9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
  for (int i = 0; i < vectr.size(); i++) {
    cout << vectr[i] << " \n";
  }

  return 0;
}