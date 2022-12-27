#include <iostream>
#include <vector>

using namespace std;

// 给定一个长度为N的整型数组arr,其中有N个互不相等的自然数1~N，请实现arr的排序，但是不要把下标0~N-1位置上的数通过直接赋值的方式替换成1~N。
// 时间复杂度为O(N),额外空间复杂度为O(1)

// 自然排序
void NormalSort(vector<int> &nums) {
  for (int i = 0; i < nums.size(); i++) {
    while (nums[i] != i + 1) {
      int tmp = nums[nums[i] - 1];
      nums[nums[i] - 1] = nums[i];
      nums[i] = tmp;
    }
  }
}

int main() {

  vector<int> nums = {1, 3, 5, 2, 6, 4};

  NormalSort(nums);

  for (int i = 0; i < nums.size(); i++) {
    cout << nums[i] << " ";
  }
  return 0;
}
