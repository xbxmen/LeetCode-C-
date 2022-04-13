#include <iostream>
#include <vector>
using namespace std;

// BM65 最长公共子字符串
// https://www.nowcoder.com/practice/f33f5adc55f444baa0e0ca87ad8a6aac?tpId=295&tqId=991150&ru=%2Fpractice%2F6d29638c85bb4ffd80c020fe244baf11&qru=%2Fta%2Fformat-top101%2Fquestion-ranking&sourceUrl=%2Fexam%2Foj

class Solution {
 public:
  /**
   * longest common subsequence
   * @param s1 string字符串 the string
   * @param s2 string字符串 the string
   * @return string字符串
   */
  string LCS(string s1, string s2) {
    int l1 = s1.length();
    int l2 = s2.length();
    vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));

    int max = 0;
    int max_right = 0;
    for (int i = 1; i <= s1.length(); i++) {
      for (int j = 1; j <= s2.length(); j++) {
        if (s1[i - 1] == s2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
        } else {
          dp[i][j] = 0;
        }

        if (dp[i][j] > max) {
          max = dp[i][j];
          max_right = i - 1;
        }
      }
    }

    int max_left = max_right - max;
    std::string res;
    while (max_left <= max_right) {
      res += s1[max_left++];
    }
    return res;
  }
};

int main() {}