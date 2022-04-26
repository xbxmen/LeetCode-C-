#include <iostream>
using namespace std;
#include <stdlib.h>

#include <fstream>
#include <iostream>
#include <vector>

int main() {
  int a = 10;

  int* p;
  p = &a;  //指针指向数据a的地址
  int* pr = p;
  if (pr == p) {
    cout << 123;
  }

  // cout << *p << endl;  //* 解引用
  // cout << sizeof(p) << endl;
  // cout << sizeof(char*) << endl;
  // cout << sizeof(float*) << endl;
  // cout << sizeof(double*) << endl;

  const int aa = 8;
  int* pa = (int*)&aa;
  *pa = 4;
  printf("*pa = %d, a = %d", *pa, aa);

  return 0;
}