#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
  string str;
  vector<int> numsA;

  int team, rank;
  cin >> team >> rank;
  vector<vector<int>> fenshu(team + 1, vector<int>(3, 0));
  for (int i = 0; i < team + 1; i++) {
    fenshu[i][0] = i;
  }

  int number = team * (team - 1) / 2;
  while (number > 0) {
    int x, y, a, b;
    cin >> x >> y >> a >> b;

    fenshu[x][1] += a;
    fenshu[y][1] += b;
    if (a > b) {
      fenshu[x][2] += 1;
    } else {
      fenshu[y][2] += 1;
    }
    number--;
  }

  for (int i = 2; i <= team; i++) {
    for (int j = i; j > 1; j--) {
      if (fenshu[j][2] > fenshu[j - 1][2]) {
        fenshu[j].swap(fenshu[j - 1]);
      } else {
        break;
      }
    }
  }

  for (int i = 2; i <= team; i++) {
    for (int j = i; j > 1; j--) {
      if (fenshu[j][1] > fenshu[j - 1][1] && fenshu[j][2] >= fenshu[j - 1][2]) {
        fenshu[j].swap(fenshu[j - 1]);
      } else {
        break;
      }
    }
  }

  // cout << "------------------" << endl;
  // for (int i = 1; i <= team; i++) {
  //   for (auto x : fenshu[i]) {
  //     cout << x << " ";
  //   }
  //   cout << endl;
  // }
  // cout << "------------------" << endl;

  // 计算排名
  int mingci = 1;
  vector<int> paiming(team + 1);
  for (int i = 1; i <= team; i++) {
    // cout << "名次:" << mingci << endl;
    if (mingci > rank) {
      break;
    }
    paiming[fenshu[i][0]] = 1;
    // cout << "当前队伍：" << fenshu[i][0] << endl;

    // 如果有并列往后延
    int j = i + 1;
    if (j <= team && fenshu[j][1] == fenshu[i][1] && fenshu[j][2] == fenshu[i][2]) {
      continue;
    }

    mingci = i + 1;
  }

  for (int i = 1; i <= team; i++) {
    cout << paiming[i];
    if (i != team) {
      cout << endl;
    }
  }

  return 0;
}