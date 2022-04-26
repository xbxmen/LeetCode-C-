#include <iostream>
#include <map>
#include <vector>
using namespace std;

// BM68 矩阵的最小路径和

class Solution {
 public:
  /**
   *
   * @param matrix int整型vector<vector<>> the matrix
   * @return int整型
   */
  int minPathSum(vector<vector<int>>& matrix) {
    int row = matrix.size();
    int line = matrix[0].size();

    vector<vector<int>> dp(row, vector<int>(line, 0));

    for (int i = 0; i < row; i++) {
      if (i == 0) {
        dp[i][0] = matrix[i][0];
      } else {
        dp[i][0] = matrix[i][0] + matrix[i - 1][0];
      }
    }

    for (int i = 0; i < line; i++) {
      if (i == 0) {
        dp[0][i] = matrix[0][i];
      } else {
        dp[0][i] = matrix[0][i] + matrix[0][i - 1];
      }
    }

    for (int i = 1; i <= row; i++) {
      for (int j = 1; j <= line; j++) {
        if (dp[i - 1][j] <= dp[i][j - 1]) {
          dp[i][j] = dp[i - 1][j] + matrix[i - 1][j - 1];
        } else {
          dp[i][j] = dp[i][j - 1] + matrix[i - 1][j - 1];
        }
      }
    }

    for (int i = 1; i <= row; i++) {
      for (int j = 1; j <= line; j++) {
        cout << dp[i][j] << " ";
      }

      cout << endl;
    }

    return dp[row][line];
  }
};

int main() {
  Solution so;
  vector<int, vector<int>> dp = {{1, 2, 3}, {1, 2, 3}, {1, 2, 3}};
  so.minPathSum(dp);
}