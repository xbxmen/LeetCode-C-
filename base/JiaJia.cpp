#include <stdlib.h>

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int a = 10;
  int b = 1;

  int c = a++ + b;

  cout << c << endl;

  int i = 1;
  printf("%d,%d\n", ++i, ++i);  // 2,3
  printf("%d,%d\n", ++i, i++);  // 4,4
  printf("%d,%d\n", i++, i++);  // 5,6
  printf("%d,%d\n", i++, ++i);  // 7,9

  return 0;
}