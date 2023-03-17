#pragma once
#include <iostream>
#include <memory>

using namespace std;

/**
 * @brief Get the Rand object
 *
 * @return int
 */
int getRand() {
  srand((unsigned)time(NULL));
  return rand();
}