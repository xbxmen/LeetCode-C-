#include <iostream>
#include <vector>
using namespace std;

// 冒泡排序
// 稳定

// 时间复杂度 O(n2)
// 选取
void BubbleSort1(vector<int>& nums) {
  int count = nums.size();

  for (int i = 0; i < count; i++) {
    for (int j = 0; j < count - i - 1; j++) {
      if (nums[j] > nums[j + 1]) {
        int temp = nums[j];
        nums[j] = nums[j + 1];
        nums[j + 1] = temp;
      }
    }
  }
}

// 时间复杂度O(n2)
// 
void BubbleSort2(vector<int>& nums) {
  int count = nums.size();
  bool flag = true;
  while (flag) {
    flag = false;
    for (int i = 0; i < count - 1; i++) {
      if (nums[i] > nums[i + 1]) {
        int temp = nums[i];
        nums[i] = nums[i + 1];
        nums[i + 1] = temp;
      }
    }

    count--;
  }
}

// 时间复杂度O(n2)
// 设置一个下标，记录最后换位的index，如果一次排序下来没有换位，说明已经有序
void BubbleSort3(vector<int>& nums) {
  int count = nums.size();
  while (count > 0) {
    int index = 0;
    for (int i = 0; i < count - 1; i++) {
      if (nums[i] > nums[i + 1]) {
        int temp = nums[i];
        nums[i] = nums[i + 1];
        nums[i + 1] = temp;

        index = i;
      }
    }

    cout << index << " 下标" << endl;

    count = index;
  }
}

void BubbleSort4(int* nums) { *nums = 123; }

int main() {
  vector<int> nums = {3, 11, 2, 1, 2, 9, 5};
  BubbleSort3(nums);
  for (int i = 0; i < nums.size(); i++) {
    cout << nums[i] << " ";
  }

  int qwe = 1;
  int* pr = &qwe;
  BubbleSort4(pr);
  cout << qwe << endl;
  *pr = 111111;
  cout << qwe << endl;

  return 0;
}
