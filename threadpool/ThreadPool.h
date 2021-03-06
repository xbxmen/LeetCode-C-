#pragma once

#include <condition_variable>
#include <functional>
#include <list>
#include <memory>
#include <mutex>
#include <thread>
#include <vector>

namespace netlib {
class ThreadPool {
 public:
  typedef std::function<void(void)> Task;
  ThreadPool(int threadNumber);
  ~ThreadPool();

  //往任务队列里添加任务
  bool append(Task task);

  //启动线程池
  bool start(void);

  //停止线程池
  bool stop(void);

 private:
  //线程所执行的工作函数
  void threadWork(void);

  std::mutex mutex_;                                   //互斥锁
  std::condition_variable_any condition_empty_;        //当任务队列为空时的条件变量
  std::list<Task> tasks_;                              //任务队列
  bool running_;                                       //线程池是否在运行
  int threadNumber_;                                   //线程数
  std::vector<std::shared_ptr<std::thread>> threads_;  //用来保存线程对象指针
};
}  // namespace netlib