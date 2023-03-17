#include <iostream>
#include <mutex>
#include <string>
#include <thread>

using namespace std;

// 如何实现一个死锁？
// https://www.cnblogs.com/linuxAndMcu/p/14620987.html
class LogFile {
public:
  LogFile() { f.open("log.txt"); }
  ~LogFile() { f.close(); }
  void shared_print(string msg, int id) {
    std::lock_guard<std::mutex> guard(_mu);
    std::lock_guard<std::mutex> guard2(_mu2);
    f << msg << id << endl;
    cout << msg << id << endl;
  }
  void shared_print2(string msg, int id) {
    std::lock_guard<std::mutex> guard(_mu2);
    std::lock_guard<std::mutex> guard2(_mu);
    f << msg << id << endl;
    cout << msg << id << endl;
  }

private:
  std::mutex _mu;
  std::mutex _mu2;
  ofstream f;
};

void function_1(LogFile &log) {
  for (int i = 0; i > -100; i--)
    log.shared_print2(string("From t1: "), i);
}

int main() {
  LogFile log;
  std::thread t1(function_1, std::ref(log));

  for (int i = 0; i < 100; i++)
    log.shared_print(string("From main: "), i);

  t1.join();
  return 0;
}
