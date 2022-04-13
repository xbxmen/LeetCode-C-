#include <iostream>
#include <vector>

// BM65 最长公共子序列(二)
// https://www.nowcoder.com/practice/6d29638c85bb4ffd80c020fe244baf11?tpId=295&tqId=991075&ru=%2Fpractice%2Ff33f5adc55f444baa0e0ca87ad8a6aac&qru=%2Fta%2Fformat-top101%2Fquestion-ranking&sourceUrl=%2Fexam%2Foj

class Solution {
 public:
  /**
   * longest common subsequence
   * @param s1 string字符串 the string
   * @param s2 string字符串 the string
   * @return string字符串
   */
  string LCS(string s1, string s2) {
    vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, 0));
    for (int i = 1; i <= s1.length(); i++) {
      for (int j = 1; j <= s2.length(); j++) {
        if (s1[i - 1] == s2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
        } else {
          dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
      }
    }

    int i = s1.length();
    int j = s2.length();
    string res = "";
    while (dp[i][j] > 0) {
      if (s1[i - 1] == s2[j - 1]) {
        res = s1[i - 1] + res;
        i--;
        j--;
      } else if (dp[i - 1][j] > dp[i][j - 1]) {
        i--;
      } else {
        j--;
      }
    }

    if (res == "") {
      return "-1";
    }

    return res;
  }
};