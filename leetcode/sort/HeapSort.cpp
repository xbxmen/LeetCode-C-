#include <iostream>
#include <vector>
using namespace std;

// 堆排序
// 不稳定

// 向下调整
void AjustDown(vector<int>& nums, int index) {
  int parent = nums[index];

  int child_index = index * 2 + 1;

  int size = nums.size();
  while (child_index < size) {
    if (child_index + 1 < size && nums[child_index] < nums[child_index + 1]) {
      child_index += 1;
    }

    if (nums[child_index] < parent) {
      break;
    }

    nums[index] = nums[child_index];
    index = child_index;
    child_index = 2 * index + 1;
  }
  nums[index] = parent;
}

// 复杂度：O(nlog(n))
void HeapSort(vector<int>& nums) {
  int size = nums.size();
  for (int i = size / 2; i >= 0; i--) {
    AjustDown(nums, i);
  }
}

int main() {
  vector<int> nums = {3, 11, 2, 1, 2, 9, 5};

  HeapSort(nums);
  for (int i = 0; i < nums.size(); i++) {
    cout << nums[i] << " ";
  }
}