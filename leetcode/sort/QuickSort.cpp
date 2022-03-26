#include <iostream>
#include <vector>
using namespace std;

// 快速排序
// 不稳定

// 时间复杂度 O(nlog(n))，最坏情况下：Q(n2)
// 双指针
void QuickSort(vector<int>& nums, int left, int right) {
  if (left >= right) {
    return;
  }

  int i = left;
  int j = right;

  int flag = nums[left];
  while (left < right) {
    while (left < right && nums[right] > flag) {
      right--;
    }

    while (left < right && nums[left] <= flag) {
      left++;
    }

    if (left < right) {
      int tmp = nums[left];
      nums[left] = nums[right];
      nums[right] = tmp;
    }
  }

  nums[i] = nums[left];
  nums[left] = flag;

  int center = left;
  QuickSort(nums, i, center - 1);
  QuickSort(nums, center + 1, j);
}

int main() {
  vector<int> nums = {3, 11, 2, 1, 2, 9, 5};
  QuickSort(nums, 0, nums.size() - 1);
  for (int i = 0; i < nums.size(); i++) {
    cout << nums[i] << " ";
  }

  return 0;
}
