#include <iostream>
#include <vector>
using namespace std;

// 堆排序
// 不稳定

// 最大堆

/**
 * @brief 向下调整
 *
 * @param nums
 * @param index
 */
void AjustDown(vector<int> &nums, int index) {
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

/**
 * @brief 复杂度：O(nlog(n))
 *
 */
void HeapSort(vector<int> &nums) {
  int size = nums.size();
  for (int i = size / 2; i >= 0; i--) {
    AjustDown(nums, i);
  }
}

/**
 * @brief 删除最大值
 *
 * @param nums
 */
void DeleMaxValue(vector<int> &nums) {
  nums[0] = 0;
  AjustDown(nums, 0);
  nums.pop_back();
}

/**
 * @brief 向上调整
 *
 * @param nums
 * @param index
 */
void AjustUp(vector<int> &nums, int index) {
  int new_value = nums[index];

  int parent_index = (index - 1) / 2;
  while (index > 0) {
    if (nums[parent_index] > new_value) {
      break;
    }

    nums[index] = nums[parent_index];
    index = parent_index;
    parent_index = (index - 1) / 2;
  }

  nums[index] = new_value;
}

/**
 * @brief 在最大堆基础上添加一个值
 *
 * @param nums
 */
void AddValue(vector<int> &nums) {
  nums.push_back(100);
  AjustUp(nums, nums.size() - 1);
}

int main() {
  vector<int> nums = {3, 11, 2, 1, 2, 9, 5};

  HeapSort(nums);
  for (int i = 0; i < nums.size(); i++) {
    cout << nums[i] << " ";
  }
  cout << endl;

  DeleMaxValue(nums);
  for (int i = 0; i < nums.size(); i++) {
    cout << nums[i] << " ";
  }

  cout << endl;
  AddValue(nums);
  for (int i = 0; i < nums.size(); i++) {
    cout << nums[i] << " ";
  }
}