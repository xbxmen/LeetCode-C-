#include <unistd.h>

#include <functional>
#include <iostream>
#include <string>
#include <vector>

#include "ThreadPool.h"

void fun(void) { std::cout << "hello" << std::endl; }

int main() {
  netlib::ThreadPool pool(10);
  pool.start();
  pool.append(fun);

  return 0;
}