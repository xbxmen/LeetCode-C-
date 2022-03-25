#include <iostream>
#include <vector>
using namespace std;

// 选择排序
// 不稳定

// 复杂度：O(n2)
void SelectSort(vector<int>& nums) {
  int count = nums.size();

  for (int i = 0; i < count; i++) {
    int max_index = 0;
    for (int j = 0; j < count - i; j++) {
      if (nums[j] > nums[max_index]) {
        max_index = j;
      }
    }

    int temp = nums[count - i - 1];
    nums[count - i - 1] = nums[max_index];
    nums[max_index] = temp;
  }
}

int main() {
  vector<int> nums = {3, 11, 2, 1, 2, 9, 5};
  SelectSort(nums);
  for (int i = 0; i < nums.size(); i++) {
    cout << nums[i] << " ";
  }
}