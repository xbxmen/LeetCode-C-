// （1）饿汉模式实现一：直接定义静态对象
//代码实例（线程安全） //.h文件
class Singleton {
public:
  static Singleton &GetInstance();

private:
  Singleton() {}
  Singleton(const Singleton &);
  Singleton &operator=(const Singleton &);

private:
  static Singleton m_Instance;
};
// CPP文件
Singleton Singleton::m_Instance;
//类外定义-不要忘记写
Singleton &Singleton::GetInstance() { return m_Instance; }
//函数调用
Singleton &instance = Singleton::GetInstance();

// 饿汉模式实现二：静态指针 + 类外初始化时new空间实现
//代码实例（线程安全）
class Singleton {
protected:
  Singleton() {}

private:
  static Singleton *p;

public:
  static Singleton *initance();
};
Singleton *Singleton::p = new Singleton;
Singleton *singleton::initance() { return p; }
