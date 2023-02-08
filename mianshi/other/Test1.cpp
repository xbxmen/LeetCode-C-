// 二维矩阵

// 123
// 456
// 789

// 741
// 852
// 963

#include <iostream>
#include <map>
#include <ostream>
#include <string>
#include <vector>

using namespace std;

void Matrix(vector<vector<int>> &nums) {
  if (nums.size() == 0) {
    return;
  }

  int length = nums.size();
  for (int i = 0; i < 1; i++) {
    for (int j = 0; j < 2; j++) {
      // 7 -> 1 -> 3 -> 9 -> 7
      int tmp = nums[i][j];
      nums[i][j] = nums[length - 1 - j][i];
      nums[length - 1 - j][i] = nums[length - 1 - i][length - 1 - j];
      nums[length - 1 - i][length - 1 - j] = nums[j][length - 1 - i];
      nums[j][length - 1 - i] = tmp;
    }
  }
}

int main() {
  vector<vector<int>> nums = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

  Matrix(nums);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cout << nums[i][j] << " ";
    }

    cout << endl;
  }
  return 0;
}
