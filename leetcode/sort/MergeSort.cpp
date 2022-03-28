#include <iostream>
#include <vector>
using namespace std;

// 归并排序
// 稳定

// 合并两个有序数组
void Merge(vector<int>& nums, int left, int center, int right) {
  int i = left;
  int j = center + 1;

  // 临时数组
  vector<int> tmp = {};
  while (i <= center && j <= right) {
    if (nums[i] < nums[j]) {
      tmp.push_back(nums[i++]);
    } else {
      tmp.push_back(nums[j++]);
    }
  }

  while (i <= center) {
    tmp.push_back(nums[i++]);
  }

  while (j <= right) {
    tmp.push_back(nums[j++]);
  }

  int index_t = 0;
  while (left <= right) {
    nums[left++] = tmp[index_t++];
  }
}

// 复杂度：O(nlog(n))
void MergeSort(vector<int>& nums, int left, int right) {
  if (left < right) {
    int center = (left + right) / 2;
    MergeSort(nums, left, center);
    MergeSort(nums, center + 1, right);

    Merge(nums, left, center, right);
  }
}

int main() {
  vector<int> nums = {3, 11, 2, 1, 2, 9, 5};

  MergeSort(nums, 0, nums.size() - 1);
  for (int i = 0; i < nums.size(); i++) {
    cout << nums[i] << " ";
  }
}