#include <iostream>
#include <map>
#include <vector>
using namespace std;

bool BinarySearch(vector<int> nums, int target) {

  int left = 0;
  int right = nums.size();

  while (left <= right) {
    int mid = (right + left) / 2;
    if (nums[mid] == target) {
      return true;
    } else if (nums[mid] < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  return false;
}

int main() {
  vector<int> nums = {1, 2, 3, 4, 7};

  cout << BinarySearch(nums, 8);
  cout << BinarySearch(nums, 3);

  return 0;
}