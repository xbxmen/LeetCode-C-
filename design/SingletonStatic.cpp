#include <iostream>

using namespace std;

class Singleton {
protected:
  // 禁止外部构造
  Singleton();

  // 禁止外部析构
  ~Singleton();

  // 禁止外部复制构造
  Singleton(const Single &signal);

  // 禁止外部赋值操作
  const Singleton &operator=(const Single &signal);

public:
  static Singleton &getIns();
  /* data */
};

Singleton::Singleton(/* args */) { std::cout << "构造函数" << std::endl; }

Singleton::~Singleton() { std::cout << "析构函数" << std::endl; }

Singleton &Singleton::getIns() {
  static Singleton ins;
  return ins;
}

void Singleton::Print() {
  std::cout << "我的实例内存地址是:" << this << std::endl;
}

int main() { Singleton s = Singleton::getIns(); }