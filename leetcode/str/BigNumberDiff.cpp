#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 1231313231231231231232323
// 3334545454545
std::string Diff(std::string str1, std::string str2) {
  if (str1.length() < str2.length()) {
    return "";
  }

  reverse(str1.begin(), str1.end());
  reverse(str2.begin(), str2.end());

  int index = 0;
  std::string result = "";
  while (index < str2.length()) {
    char tmp_a = str2[index];
    int j = index;
    if (str1[j] < tmp_a) {
      int jie = j - 1;
      while (str1[jie] == '0') {
        str1[jie] = '9';
        jie--;
      }
      str1[jie] = str1[jie] - 1;
      str1[j] += 10;
    }

    result += std::to_string(str1[j] - str2[index]);
    index++;
  }

  while (index < str1.length()) {
    result += str1[index];
    index++;
  }

  reverse(result.begin(), result.end());

  return result;
}

int main() {

  cout << Diff("123123", "123");
  return 0;
}