#include <iostream>
#include <mutex>
#include <vector>

using namespace std;

/**
题目：共享变量

描述：
有一个变量a，需要保证变量只能被设置（写入）一次，再次设置会触发异常
在变量未设置前进行读取操作将返回默认值0

如何设计？
 */
class ShareVariable {
private:
  int a;
  bool is_set_;
  mutex *mutex_;

public:
  ShareVariable() {
    a = 0;
    mutex_ = new mutex();
    is_set_ = false;
  }

  ~ShareVariable() { delete mutex_; }

  /**
   * @brief 查询变量A
   *
   * @return int
   */
  int getA() { return a; }

  /**
   * @brief 设置变量A
   *
   * @param val
   * @return true
   * @return false
   */
  bool setA(int val) {
    if (is_set_) {
      return false;
    }

    mutex_->lock();
    a = val;
    is_set_ = true;
    mutex_->unlock();

    return true;
  }

  /**
   * @brief 释放变量A
   *
   * @return true
   * @return false
   */
  void delA() {
    mutex_->unlock();
    a = 0;
    is_set_ = false;
  }
};

int main() {

  ShareVariable s;

  cout << "-----------------------" << endl;
  cout << "current a:" << endl;
  cout << s.getA() << endl;

  cout << "set a=100:" << endl;
  cout << s.setA(100) << endl;
  cout << "current a:" << endl;
  cout << s.getA() << endl;
  cout << "-----------------------" << endl;

  // 二次set出错
  cout << "set a=200:" << endl;
  cout << s.setA(200) << endl;
  cout << "current a:" << endl;
  cout << s.getA() << endl;
  cout << "-----------------------" << endl;

  cout << "del a" << endl;
  s.delA();
  cout << "current a:" << endl;
  cout << s.getA() << endl;

  cout << "set a=300:" << endl;
  cout << s.setA(300) << endl;
  cout << "current a:" << endl;
  cout << s.getA() << endl;

  return 0;
}