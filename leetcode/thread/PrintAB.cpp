// https://zhuanlan.zhihu.com/p/374037023
// C++ 多线程（二）：两个线程轮流（交替）打印 A 和 B

#include <iostream>
#include <thread>

std::mutex mtx;
std::condition_variable cv;
std::string flag("A");

void PrintA() {
  while (true) {
    std::unique_lock<std::mutex> lck(mtx);
    while (flag == "B") {
      cv.wait(lck);
    }
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "A" << std::endl;
    flag = "B";
    cv.notify_all();
  }
}

void PrintB() {
  while (true) {
    std::unique_lock<std::mutex> lck(mtx);
    while (flag == "A") {
      cv.wait(lck); // cv.wait(lck, lambda)
    }
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "B" << std::endl;
    flag = "A";
    cv.notify_all();
  }
}

/*
解释：
std::mutex 是 C++ 中最基本的互斥量，提供了独占所有权的特性
std::unique_lock 是对 std::mutex 类型的互斥量的上锁和解锁进行管理
std::condition_variable
是条件变量，所有等待(wait)某个条件的线程都必须使用相同的mutex，且必须使用
unique_lock 绑定 mutex，并且让 wait() 等待在 unique_lock
上，否则会发生不明确的行为 notify_one()（随机唤醒一个等待的线程）和
notify_all()（唤醒所有等待的线程）
*/

int main() {

  std::thread mt1(PrintA);
  std::thread mt2(PrintB);

  mt1.join();
  mt2.join();

  std::cin.get();
}