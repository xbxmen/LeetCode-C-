#include <iostream>
#include <mutex>
#include <thread>
using namespace std;
mutex m;  //实例化m对象，不要理解为定义变量
void proc1(int a) {
  m.lock();
  cout << "proc1函数正在改写a" << endl;
  cout << "原始a为" << a << endl;
  cout << "现在a为" << a + 2 << endl;
  m.unlock();
}

void proc2(int a) {
  m.lock();
  cout << "proc2函数正在改写a" << endl;
  cout << "原始a为" << a << endl;
  cout << "现在a为" << a + 1 << endl;
  m.unlock();
}
int main() {
  int a = 0;
  thread proc1(proc1, a);
  thread proc2(proc2, a);
  proc1.join();
  proc2.join();
  return 0;
}
