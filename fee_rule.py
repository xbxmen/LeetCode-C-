#!/usr/bin/env python
# -*- coding: utf-8 -*-
# des: 该代码为xdata自动生成，请勿直接修改
#      xdata任务ID:None
# update time: 2023-03-06 16:26:54
# version uuid: a6d147e2-bbf8-11ed-a58b-f47488dda7bf

import datetime

# 计算过程，用户写的SQL语句逻辑会放在此处，并自动拼接成真实执行的SQL语句。
def calculate(tdw, basetime):
    # 计算基础时间
    basetime = str(basetime)
    if len(basetime) == 10:  # YYYYMMDDHH
        base_month = basetime[0:6]
        base_day = basetime[0:8]
        base_hour = basetime
    elif len(basetime) == 8:  # YYYYMMDD
        base_month = basetime[0:6]
        base_day = basetime
        base_hour = None
    elif len(basetime) == 6:  # YYYYMM
        base_month = basetime
        base_day = None
        base_hour = None
    # SQL计算逻辑
    try:

        # 执行第1条SQL逻辑,SQL描述:无
        sql = '''
        insert overwrite table t_dwd_reds_fee_rule_day partition(ds=%(base_day)s) (ds,fmch_id,ffee_rule_type,fpay_scene,frule_id,frate_template_id,fcredit_rate_template_id,fremark,effect_begin_time,effect_end_time,rate_effect_begin_time,rate_effect_end_time) 
        -- 全量活动相关商户计费规则数据
        SELECT
          ds, -- 日期
          fmch_id, -- 商户ID
          ffee_rule_type, -- 计费规则类型
          fpay_scene, -- 计费规则支付场景
          frule_id, -- 计费规则ID
          frate_template_id, -- 默认费率模板信息
          fcredit_rate_template_id, -- 贷记费率模板信息
          fremark, -- FFeeRemark
          effect_begin_time, -- 计费规则生效时间
          effect_end_time, -- 计费规则失效时间
          rate_effect_begin_time, -- 计费规则生效时间
          rate_effect_end_time -- 计费规则失效时间
        FROM
          wxg_wechat_pay_logic::t_dwm_settle_fee_rule_4activity_day
          
        WHERE ds=%(base_day)s
        ''' % {
            "base_day": base_day,
            "base_hour": base_hour,
            "base_month": base_month
        }
        run_sql_and_log(tdw, sql)

    finally:

        pass


# 配置函数，将所有的配置，包括库的切换，表的创建，分区的清洗创建等放在这里面
def init(tdw, db_name, table_name, basetime):
    # 选择TDW库
    sql = "use %s" % (db_name)
    run_sql_and_log(tdw, sql)
    # 配置INSERT INTO TABLE语句执行引擎使用Spark
    run_sql_and_log(tdw, 'set hive.insert.with.use.spark=true;')
    # 开启MP/Spark的推测执行
    run_sql_and_log(tdw, 'set mapreduce.reduce.speculative=true;')
    run_sql_and_log(tdw, 'set spark.speculation=true;')
    # 配置MP执行超时时间
    run_sql_and_log(tdw, 'set mapreduce.task.timeout=12000000;')
    # 配置单纯select时的最大数据返回行数
    run_sql_and_log(tdw, 'set select.max.limit=1000000;')

    # 创建数据表(在xdata上提交任务时会自动建表，这里只是防止表被意外删除时的兜底建表策略！！)
    sql = '''
    create table if not exists t_dwd_reds_fee_rule_day (
      ds bigint comment '日期',
      fmch_id bigint comment '商户ID',
      ffee_rule_type bigint comment '计费规则类型',
      fpay_scene bigint comment '计费规则支付场景',
      frule_id string comment '计费规则ID',
      frate_template_id string comment '默认费率模板信息',
      fcredit_rate_template_id string comment '贷记费率模板信息',
      fremark string comment 'FFeeRemark',
      effect_begin_time string comment '计费规则生效时间',
      effect_end_time string comment '计费规则失效时间',
      rate_effect_begin_time string comment '计费规则生效时间',
      rate_effect_end_time string comment '计费规则失效时间'
    )
    COMMENT '全量活动相关商户计费规则数据-测试数据'

    PARTITION BY LIST( ds )
    (
        PARTITION default
    )

    STORED AS ORCFILE
    '''
    run_sql_and_log(tdw, sql)

    # 删除default分区
    sql = "alter table t_dwd_reds_fee_rule_day drop partition (default)"
    run_sql_and_log(tdw, sql)

    # 删除当前分区
    sql = "alter table t_dwd_reds_fee_rule_day drop partition (p_%s)" % (
        basetime)
    run_sql_and_log(tdw, sql)

    # 创建当前分区
    sql = "alter table t_dwd_reds_fee_rule_day add partition p_%s values in (%s)" % (
        basetime, basetime)
    run_sql_and_log(tdw, sql)


def run_sql_and_log(tdw, sql):
    tdw.WriteLog("RUNNING SQL: " + sql)
    return tdw.execute(sql)


def timedelta(basetime, offset=None, pattern=None):
    if len(basetime) == 6 or pattern == "month":
        dt = datetime.datetime.strptime(basetime, '%Y%m')
        if 0 == (dt.month + offset) % 12:
            year_offset = (dt.month + offset) / 12 - 1
            month_offset = 12
        else:
            year_offset = (dt.month + offset) / 12
            month_offset = (dt.month + offset) % 12
        target_month = month_offset
        target_year = dt.year + year_offset
        return datetime.datetime(target_year, target_month,
                                 dt.day).strftime('%Y%m')
    elif len(basetime) == 10 or pattern == "hour":
        dt = datetime.datetime.strptime(basetime, '%Y%m%d%H')
        dt = dt + datetime.timedelta(hours=offset)
        return dt.strftime('%Y%m%d%H')
    else:
        dt = datetime.datetime.strptime(basetime, '%Y%m%d')
        dt = dt + datetime.timedelta(days=offset)
        return dt.strftime('%Y%m%d')


# 入口函数
def TDW_PL(tdw, argv=None):
    # print argv
    if not argv or len(argv) < 1:
        tdw.WriteLog('running Python', 'wrong numbers of arguments.')
        return 0
    else:
        basetime = argv[0]
        db_name = 'wechat_pay_industry'
        table_name = 't_dwd_reds_fee_rule_day'
        init(tdw, db_name, table_name, basetime)
        calculate(tdw, basetime)
        tdw.WriteLog("Calc data end.")