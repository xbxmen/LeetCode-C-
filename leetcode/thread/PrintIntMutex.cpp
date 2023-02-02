#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

// C++使用多线程交替打印1~10
// https://blog.csdn.net/qq_34039018/article/details/103165183

int number;
mutex token;

const int MAX_NUMBER = 10;

void add_1() {
  while (1) {
    token.lock();
    if (number >= MAX_NUMBER) {
      token.unlock();
      break;
    }

    if (number % 2 == 0) {
      number++;
      cout << "mythread_1: " << number << endl; // 输出
    }

    token.unlock();
  }
  cout << "mythread_1 finish" << endl; // mythread_1完成
}

void add_2() {
  while (1) {
    token.lock();
    if (number >= MAX_NUMBER) {
      token.unlock();
      break;
    }

    if (number % 2 == 1) {
      number++;
      cout << "mythread_2: " << number << endl; // 输出
    }

    token.unlock();
  }
  cout << "mythread_2 finish" << endl; // mythread_1完成
}

int main() {
  number = 0;

  thread mt1(add_1);
  thread mt2(add_2);

  mt1.join();
  mt2.join();

  return 0;
}