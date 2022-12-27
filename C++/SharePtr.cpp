#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

/**
 * 面试题：简单实现一个shared_ptr智能指针
 * https://cloud.tencent.com/developer/article/1688444
 *
 * shared_ptr的原理
 * shared_ptr的原理：是通过引用计数的方式来实现多个shared_ptr对象之间共享资源。
 * 1.shared_ptr在其内部，给每个资源都维护了着一份计数，用来记录该份资源被几个对象共享。
 * 2.在对象被销毁时(也就是析构函数调用)，就说明自己不使用该资源了，对象的引用计数减一。
 * 3.如果引用计数是0，就说明自己是最后一个使用该资源的对象，必须释放该资源。
 * 4.如果不是0，就说明除了自己还有其他对象在使用该份资源，不能释放该资源，否则其他对象就成野指针了。
 */

template <class T>
class Shared_Ptr {
 private:
  void Release() {
    bool deleteflag = false;
    _pMutex->lock();
    if (--(*_pRefCount) == 0) {
      delete _pRefCount;
      delete _pPtr;
      deleteflag = true;
    }
    _pMutex->unlock();
    if (deleteflag == true) delete _pMutex;
  }

 private:
  int* _pRefCount;
  T* _pPtr;
  mutex* _pMutex;

 public:
  // 构造函数
  Shared_Ptr(T* ptr = nullptr) : _pPtr(ptr), _pRefCount(new int(1)), _pMutex(new mutex) {}
  // 析构函数
  ~Shared_Ptr() { Release(); }

  // 拷贝构造函数
  Shared_Ptr(const Shared_Ptr<T>& sp) : _pPtr(sp._pPtr), _pRefCount(sp._pRefCount), _pMutex(sp._pMutex) {
    AddRefCount();
  }

  // 赋值操作符
  Shared_Ptr<T>& operator=(const Shared_Ptr<T>& sp) {
    // if (this != &sp)
    if (_pPtr != sp._pPtr) {
      // 释放管理的旧资源
      Release();
      // 共享管理新对象的资源，并增加引用计数
      _pPtr = sp._pPtr;
      _pRefCount = sp._pRefCount;
      _pMutex = sp._pMutex;
      AddRefCount();
    }
    return *this;
  }

  T& operator*() { return *_pPtr; }
  T* operator->() { return _pPtr; }

  // 获取对象指针
  T* Get() { return _pPtr; }

  // 返回计数器
  int UseCount() { return *_pRefCount; }

  // 增加计数器
  void AddRefCount() {
    _pMutex->lock();
    ++(*_pRefCount);
    _pMutex->unlock();
  }
};