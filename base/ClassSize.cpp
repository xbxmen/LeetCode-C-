#include <iostream>
using namespace std;

class A {
 public:
  A() {}
  int Hellon();
};

class A1 {
 public:
  A1() {}

 private:
  int a;
};

class A2 {
 public:
  A2() {}

 private:
  int a;
  int b;
};

class A3 {
 public:
  A3() {}

 private:
  int a;
  static int b;
};

class A4 {
 public:
  A4() {}
  virtual int qwe();

  int qqq;
  int www;
  int eee;
};

int main() {
  A a;
  cout << "A: " << sizeof(A) << endl;
  cout << "a: " << sizeof(A) << endl;

  A1 a1;
  cout << "A1: " << sizeof(A1) << endl;
  cout << "a1: " << sizeof(A1) << endl;

  A2 a2;
  cout << "A2: " << sizeof(A2) << endl;
  cout << "a2: " << sizeof(A2) << endl;

  A3 a3;
  cout << "A3: " << sizeof(A3) << endl;
  cout << "a3: " << sizeof(A3) << endl;

  cout << "A4: " << sizeof(A4) << endl;
  return 0;
}