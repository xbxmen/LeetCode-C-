#include <iostream>
using namespace std;
#include <stdlib.h>

#include <fstream>
#include <iostream>
#include <vector>

class staticClass {
 private:
  /* data */
 public:
  staticClass(/* args */);
  ~staticClass();

  static void hello() { cout << "123" << endl; }
};

staticClass::staticClass(/* args */) {}

staticClass::~staticClass() {}

int main() {
  int a = 10;
  staticClass::hello();

  int i = 1;
  printf("%d,%d\n", ++i, ++i);  // 3,3
  printf("%d,%d\n", ++i, i++);  // 5,3
  printf("%d,%d\n", i++, i++);  // 6,5
  printf("%d,%d\n", i++, ++i);  // 8,9
  return 0;
}