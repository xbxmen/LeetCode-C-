#include <iostream>
#include <string>
#include <thread>

// 单例模式
// 线程不安全
class Singleton {
 private:
  /* data */
  std::string value_;

  static Singleton* singleton_;

 public:
  Singleton(const std::string value) : value_(value) {}
  ~Singleton();

  Singleton(Singleton& other) = delete;
  void operator=(const Singleton&) = delete;

  static Singleton* GetInstance(const std::string& value);

  void SomeBusinessLogic() {
    // ...
  }

  std::string value() const { return value_; }
};

Singleton* Singleton::singleton_ = nullptr;

/**
 * Static methods should be defined outside the class.
 */
Singleton* Singleton::GetInstance(const std::string& value) {
  /**
   * This is a safer way to create an instance. instance = new Singleton is
   * dangeruous in case two instance threads wants to access at the same time
   */
  if (singleton_ == nullptr) {
    singleton_ = new Singleton(value);
  }
  return singleton_;
}

void ThreadFoo() {
  // Following code emulates slow initialization.
  std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  Singleton* singleton = Singleton::GetInstance("FOO");
  std::cout << singleton->value() << "\n";
}

void ThreadBar() {
  // Following code emulates slow initialization.
  std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  Singleton* singleton = Singleton::GetInstance("BAR");
  std::cout << singleton->value() << "\n";
}

Singleton::~Singleton() {}

int main() {
  std::cout << "If you see the same value, then singleton was reused (yay!\n"
            << "If you see different values, then 2 singletons were created (booo!!)\n\n"
            << "RESULT:\n";
  std::thread t1(ThreadFoo);
  std::thread t2(ThreadBar);
  t1.join();
  t2.join();

  return 0;
}
