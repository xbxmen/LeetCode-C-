#include <iostream>

using namespace std;

class Mysql {
public:
  int get(int id) { return 0; }

  bool set(int id, int value) { return true; };
};

class Redis {
public:
  int get(int id) { return 0; }

  bool del(int id) { return true; }

  bool set(int id, int value) { return true; };

  bool setNx(int id, int value, int ttl) { return true; };
};

class User {
private:
  int id_;
  int value_;

public:
  User(int id) { id_ = id; };

  ~User(){};

  bool set(int v) {
    Mysql sql;
    Redis rd;

    int lock = rand();
    if (!rd.setNx(lock, 1, 10)) {
      return false;
    }

    if (sql.set(this->id_, v)) {
      rd.del(this->id_);
    }

    rd.del(lock);
    return true;
  }

  int get() {
    Mysql sql;
    Redis rd;

    int result = rd.get(this->id_);
    if (result) {
      return result;
    }

    int lock = rand();
    if (!rd.setNx(lock, 1, 10)) {
      return result;
    }

    int new_value = sql.get(this->id_);
    rd.set(this->id_, new_value);
    rd.del(lock);

    return new_value;
  }
};

int main() { return 0; }

// 接口：VUE
// 应用： NODE PHP （腾讯云 -> docker） 模块 三园区
// 领域: C++
// 基础设施层：DAO C++
// KV + MSYQL

// 企业用车

// 滴滴
// 国际化 网约车 资产 货运，企业服务事业群（TOB）
// 商旅出行（企业级）
// 小组：企业支付能力
// 腾讯-》打车聚合平台-》滴滴 + 曹操（运营商）
// 包含：
// 下单：范围管控，权限限制
// 事中：企业支付（月结 +
// 充值），支付能力？企业判断、企业支付能力。小组能力，渠道建设
// 事后：对账，出账单

// 技术栈：PHP + golang
// 小组：5-6个人
// （1）支付侧：业务单 + 支付单
// （2）管控侧：

// 能力：
// 对外API：第三方公司
// 对内接口：滴滴APP
