#include <iostream>
#include <memory>
#include <mutex>
#include <vector>

#include "Soldier.h"
#include "Util.h"

using namespace std;

/**
题目：敁棋对战模拟器

描述：
战棋对战定义：
ab双方各有一些棋子（每人最多7枚）代表出战随从，每个随从有攻击力和生命值两个数值属性
（均为正整数）
    * 对战开始时，随从多的一方获得先手（若两者随从数量相等，则随机先手）
    * 随从从左到右开始攻击，双方交替攻击（例：若a先手，在不考虑死亡下攻击顺序为
    a0->b0->a1->b1->a2->b2 ... a6->66->a0->b0->a1->b1.
* 当一名随从攻击时，随机选择对方一个随从作为目标，攻击与被攻击的两名随从分别用己方生命值-对方攻击力作为剩余生命值，若生命值<=0则随从死亡，从场上移除
* 随从的战斗会持续到其中一个玩家失去所有随从*
战斗结束时，拥有存活随从的一方获胜，若双方均没有随从，则为平局

任务1：
给定若干行输入
第1行为双方随从数量
m n(o<=m，n＜=7 后m行为a方的随从攻击力和血量
attack a health a
(o < attack_a, health_a < 200)
后n行为b方的随从攻击力和血量
attack_b health_b (0 < attack_b, health_b < 200)

输出1行
  x y z
    x表示在20000次模拟对战下a获胜的频率
    y表示在20000次模拟对战下双方平局的频率
    z表示在20000次模拟对战下b获胜的频率
示例输入1:
  1 1
  1 3
  2 1
示例输出1：
  1 0 0

示例输入2：
  2 3
  2 2
  1 3
  3 1
  1 1
  1 1
示例输出2：
  0.5 0.5 0
（模拟数值浮动，仅供参考）

任务2：
考虑随从有如下特效
    * 剧毒：如果对方随从没有圣盾，则直接杀死对方随从
    * 圣盾：抵挡一次伤害（包括毒）
    * 嘲讽：对方优先攻击嘲讽的随从（多个嘲讽随机选择）
    * 风怒：当该随从攻击时，可以攻击两次（每次目标随机）

考虑代码该如何设计？
 */

/**
 * @brief 攻击回合，a攻击b
 *
 * @param user_a
 * @param user_b
 * @param index_a
 */
void attackRound(vector<Soldier> &user_a, vector<Soldier> &user_b,
                 int index_a) {

  Soldier at = user_a[index_a];

  // 进攻
  at.attackRand(user_b);

  user_a[index_a] = at;
  if (at.isDead()) {
    user_a.erase(user_a.begin() + index_a);
  }
}

/**
 * @brief 开始游戏
 *
 * @param user_a
 * @param user_b
 */
void start(vector<Soldier> user_a, vector<Soldier> user_b) {
  // 随机开始
  bool round = (getRand() % 2) == 1 ? true : false;
  if (user_a.size() > user_b.size()) {
    round = true;
  }

  // 记录结果
  int x = 0, y = 0, z = 0;

  // 循环20000次
  int time = 20000;
  while (time > 0) {
    vector<Soldier> user_a_new;
    user_a_new.assign(user_a.begin(), user_a.end());
    vector<Soldier> user_b_new;
    user_b_new.assign(user_b.begin(), user_b.end());

    int index_a = 0;
    int index_b = 0;
    while (user_a_new.size() > 0 && user_b_new.size() > 0) {
      index_a %= user_a_new.size();
      index_b %= user_b_new.size();

      // 交替回合
      if (round) {
        attackRound(user_a_new, user_b_new, index_a);
        round = false;
        index_a++;
      } else {
        attackRound(user_b_new, user_a_new, index_b);
        round = true;
        index_b++;
      }
    }

    // 记录结果
    if (user_a_new.size() > 0) {
      x++;
    } else if (user_b_new.size() > 0) {
      z++;
    } else {
      y++;
    }

    time--;
  }

  cout << "x: " << x << endl;
  cout << "y: " << y << endl;
  cout << "z: " << z << endl;
}

int main() {
  vector<Soldier> user_a = {};
  user_a.push_back(Soldier(2, 2));
  user_a.push_back(Soldier(1, 3));

  vector<Soldier> user_b = {};
  user_b.push_back(Soldier(3, 1));
  user_b.push_back(Soldier(1, 1, Soldier::TOXIC));
  user_b.push_back(Soldier(1, 1, Soldier::TOXIC));
  user_b.push_back(Soldier(1, 1, Soldier::TOXIC));
  user_b.push_back(Soldier(1, 1));

  start(user_a, user_b);

  return 0;
}
