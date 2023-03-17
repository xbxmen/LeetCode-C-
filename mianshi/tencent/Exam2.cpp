#include <iostream>
#include <vector>

using namespace std;

/**
题目：猜单词

描述：
小明找你玩猜单词的游戏，
他心里先随机生成一个长度为n的单词（例如word，n=4）
然后对word通过轮换得到
word
ordw
rdwo
dwor
然后对这n=4个轮换做字母序排序即
sort('word','ordw', 'rdwo','dwor')得到
dwor
ordw
rdwo
word
取最后一列rwod告诉你，然后问你他心里想的单词是什么
（猜到其中之一轮换就可以 word / ordw / rdwo / dwor）

输入：小明告诉你的单词（上文提到的最后一列即rwod）
输出：小明心里想的单词的任一轮换
 */

// 没有想到很好的解法
std::string GuessWord(std::string word) { return ""; }

int main() { return 0; }