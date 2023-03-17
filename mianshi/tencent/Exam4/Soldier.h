#pragma once
#include "Util.h"
#include <iostream>
#include <memory>
#include <mutex>
#include <vector>

using namespace std;

/**
 * @brief 随从
 *
 */
class Soldier {
public:
  /**
   * @brief 技能
   *
   */
  enum skill {
    NORMAL = 0, // 无技能
    TOXIC = 1,  // 剧毒
    SHIELD = 2, // 圣盾
    TAUNT = 3,  // 嘲讽
    WIND = 4    // 风怒
  };
  int health_;
  int attack_;
  skill sk_;

  Soldier(int at, int h, Soldier::skill s = NORMAL) {
    attack_ = at;
    health_ = h;
    sk_ = s;
  }
  ~Soldier() {}

  Soldier(const Soldier &base) {
    attack_ = base.attack_;
    health_ = base.health_;
    sk_ = base.sk_;
  };

  /**
   * @brief 选择敌人
   *
   * @param user
   * @return int
   */
  int getRival(vector<Soldier> &users) {
    // 优先选择带嘲讽技能的敌人
    for (int i = 0; i < users.size(); i++) {
      if (users[i].sk_ == Soldier::TAUNT) {
        return i;
      }
    }

    return getRand() % users.size();
  }

  /**
   * @brief 随机攻击
   *
   * @param rivals
   */
  void attackRand(vector<Soldier> &rivals) {
    int rand_rival = getRival(rivals);
    Soldier rival = rivals[rand_rival];
    attack(rival);
    defense(rival);
    rivals[rand_rival] = rival;
    if (rival.isDead()) {
      rivals.erase(rivals.begin() + rand_rival);
    }

    // 二次攻击
    if (!isDead() && sk_ == Soldier::WIND) {
      int rand_rival = getRival(rivals);
      Soldier rival = rivals[rand_rival];
      attack(rival);
      defense(rival);
      rivals[rand_rival] = rival;
      if (rival.isDead()) {
        rivals.erase(rivals.begin() + rand_rival);
      }
    }
  }

  /**
   * @brief 先手的攻击过程
   *
   * @param rival
   */
  void attack(Soldier &rival) {
    // 对方防守
    if (rival.sk_ == Soldier::SHIELD) {
      rival.sk_ = Soldier::NORMAL;
      return;
    }

    // 使用技能
    switch (sk_) {
    case Soldier::TOXIC:
      rival.health_ = 0;
      break;
    default:
      rival.health_ -= attack_;
    }
  }

  /**
   * @brief 先手的防守环节
   *
   * @param rival
   */
  void defense(Soldier &rival) {
    // 自己防守
    if (sk_ == Soldier::SHIELD) {
      sk_ = Soldier::NORMAL;
      return;
    }

    // 对方攻击
    // 防守不考虑对方的技能
    switch (rival.sk_) {
    default:
      health_ -= rival.attack_;
    }
  }

  bool isDead() {
    if (health_ <= 0) {
      return true;
    }

    return false;
  }
};
