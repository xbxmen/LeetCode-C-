#include <iostream>
#include <string>
using namespace std;
#include <stdlib.h>

#include <fstream>
#include <iostream>
#include <vector>

int main() {
  // cout << *p << endl;  //* 解引用
  // cout << sizeof(p) << endl;
  // cout << sizeof(char*) << endl;
  // cout << sizeof(float*) << endl;
  // cout << sizeof(double*) << endl;

  // int *ptr;
  // ptr = (int *)0x122606800;
  // *ptr = 1111111;
  // cout << *ptr << endl;

  int *my = (int *)malloc(sizeof(int));
  *my = 123;
  cout << 111111111111111 << endl;
  cout << sizeof(my) << endl;
  cout << my << endl;
  cout << *my << endl;
  my++;
  cout << my << endl;
  cout << *my << endl;

  int &qwe = *my;
  qwe++;
  cout << qwe << endl;
  cout << *my << endl;
  cout << 111111111111111 << endl;

  std::string *qq = (string *)malloc(100);
  *qq = "1234567890qwertyuiop1234";
  cout << *qq << endl;

  return 0;

  const int aa = 8;
  int *pa = (int *)&aa;
  *pa = 4;
  printf("*pa = %d, a = %d", *pa, aa);

  int *p = nullptr; //定义一个指针p 类型为 int;
  int *q;
  int b[2] = {3, 4};

  p = &b[0]; //将 p 指向 b;
  q = b;     // 指针 q 指向数组 b 的第一个元素
  cout << "变量 p 的地址为 " << p << endl;
  cout << "指针变量 p 指向的值为 " << *p << endl;
  cout << endl;
  cout << "指针变量 q 指向的值为 " << *q << endl;

  cout << endl;
  cout << endl;
  cout << "变量 p 的地址为" << p << endl;
  cout << "变量 p+1 的地址为" << p + 1 << endl;
  cout << "指针变量 p+1 指向的值为" << *(p + 1)
       << endl; // *p 表示指针p中存储的值；
  cout << endl;
  cout << "指针变量 q+1 指向的值为" << *(q + 1)
       << endl; // *p 表示指针p中存储的值；

  return 0;
}