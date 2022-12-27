//代码实例（线程不安全）
template <typename T> class Singleton {
public:
  static T &getInstance() {
    if (!value_) {
      value_ = new T();
    }
    return *value_;
  }

private:
  Singleton();
  ~Singleton();
  static T *value_;
};
template <typename T> T *Singleton<T>::value_ = NULL;

//代码实例（线程安全）
emplate<typename T> class Singleton {
public:
  static T &getInstance() {
    if (!value_) {
      value_ = new T();
    }
    return *value_;
  }

private:
  class CGarbo {
  public:
    ~CGarbo() {
      if (Singleton::value_)
        delete Singleton::value_;
    }
  };
  static CGarbo Garbo;
  Singleton();
  ~Singleton();
  static T *value_;
};
template <typename T> T *Singleton<T>::value_ = NULL;

//代码实例（线程安全）
#include <iostream>
#include <string>
using namespace std;
class Log {
public:
  static Log *GetInstance() {
    static Log oLog;
    return &oLog;
  }
  void Output(string strLog) { cout << strLog << (*m_pInt) << endl; }

private:
  Log() : m_pInt(new int(3)) {}
  ~Log() {
    cout << "~Log" << endl;
    delete m_pInt;
    m_pInt = NULL;
  }
  int *m_pInt;
};
class Context {
public:
  static Context *GetInstance() {
    static Context oContext;
    return &oContext;
  }
  ~Context() { Log::GetInstance()->Output(__FUNCTION__); }
  void fun() { Log::GetInstance()->Output(__FUNCTION__); }

private:
  Context() {}
  Context(const Context &context);
};
int main(int argc, char *argv[]) {
  Context::GetInstance()->fun();
  return 0;
}
