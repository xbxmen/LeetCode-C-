#include <iostream>
#include <vector>

using namespace std;

int Jiuping() {
  int result = 50;

  int cap = 50;
  int ping = 50;
  while (cap > 3 || ping > 5) {
    int cap_bear = cap / 3;
    int ping_bear = ping / 5;

    cap = cap % 3 + ping_bear + cap_bear;
    ping = ping % 5 + cap_bear + ping_bear;

    result += cap_bear;
    result += ping_bear;
  }

  return result;
}




int main() {
  cout << Jiuping();

  return 0;
}