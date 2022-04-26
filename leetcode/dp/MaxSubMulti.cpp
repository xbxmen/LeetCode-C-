#include <iostream>
#include <map>

using namespace std;

int integerBreak(int n) {
  map<int, int> dp;
  if (n < 4) {
    return n - 1;
  }

  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 3;
  for (int i = 4; i <= n; i++) {
    int max = 0;
    for (int j = 1; j <= i / 2; j++) {
      dp[i] = j * dp[i - j];
      if (dp[i] > max) {
        max = dp[i];
      }
    }

    dp[i] = max;
  }

  return dp[n];
}

int main() { cout << integerBreak(10); }