
using namespace std;

template <T> 
struct ref_count { int number; };

template <T>
class SharePtr {

private:
  ref_count *rc;

public:
  SharePtr(T *ptr){
    rc->number = 0;
  };

  ~SharePtr(){};

  operator =(T *ptr) {
    rc->number++;
  }
  

  
};
// 棋牌游戏

// 通用能力，共同的
// C++底层，网络模块
// C++工具箱，工具包

// 分布式架构，C++、PHP、JAVA

// 