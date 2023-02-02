#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

// 最长不重复子串

// abcdabcbb
// abc

int MaxString(std::string str) {

  map<char, int> result = {};

  int max_length = 0;
  if (str.length() == 0) {
    return 0;
  }

  int left = 0;
  for (int i = 0; i < str.length(); i++) {
    if (result.count(str.at(i)) > 0) {
      left = result[str.at(i)];
    }
    int tmp = i - left;
    max_length = max(tmp, max_length);
    result[str.at(i)] = i;
  }

  return max_length;
}

int main() {
  std::string str = "abcdabcdedb";
  //   std::string str = "bbbbb†bb";
  //   std::string str = "pwwkew";
  cout << MaxString(str);

  return 0;
}