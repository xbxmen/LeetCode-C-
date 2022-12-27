#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> nums = {1, 3, 4, 3, 9, 1};

  int target = 12;

  int left = 0, right = 0;

  int sum = 0;

  int minlength = nums.size();
  while (right < nums.size()) {
    sum += nums[right];
    if (sum < target) {
      right++;
      continue;
    }

    while (sum - nums[left] >= target) {
      cout << "left " << nums[left] << endl;
      cout << "sum " << sum << endl;

      sum -= nums[left];
      left++;
    }

    minlength = min(minlength, right - left + 1);

    right++;
  }

  cout << minlength;
}