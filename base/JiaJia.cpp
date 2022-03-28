#include <stdlib.h>

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int a = 10;
  int b = 1;

  int c = a++ + b;

  cout << c;

  return 0;
}