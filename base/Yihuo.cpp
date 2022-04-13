#include <iostream>

using namespace std;

int main() {
  //   int res = 3;
  //   int qwe = res ^ 3;
  //   cout << qwe;

  int cr = 0;
  cr <<= 1;
  cout << cr << endl;
  cr <<= 1;
  cout << cr << endl;

  cout << (1 & 2) << endl;

  if (1 & 2) {
    cout << "123" << endl;
  } else {
    cout << "qwe" << endl;
  }
}