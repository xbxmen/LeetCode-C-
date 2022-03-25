#include <iostream>
#include <vector>
using namespace std;

// 插入排序
// 稳定

// 复杂度：O(n2)
void InsertSort(vector<int>& nums) {
  int count = nums.size();

  for (int i = 1; i < count; i++) {
    for (int j = i; j > 0; j--) {
      if (nums[j] > nums[j - 1]) {
        int temp = nums[j];
        nums[j] = nums[j - 1];
        nums[j - 1] = temp;
      } else {
          break;
      }
    }
  }
}

int main() {
  vector<int> nums = {3, 11, 2, 1, 2, 9, 5};
  InsertSort(nums);
  for (int i = 0; i < nums.size(); i++) {
    cout << nums[i] << " ";
  }
}