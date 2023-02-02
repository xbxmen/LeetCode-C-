select
  ${YYYYMMDD} statis_day,
  base_cat.fmerchantid as mchid,
  -- 经营类目信息优先取top1类目
  base_cat.top1_id as base_catid,
  base_name1.market_category as base_catname,
  biz_map1.busi_category_id_lv1 as busi_catid_lv1,
  biz_map1.busi_category_name_lv1 as busi_catname_lv1,
  biz_map1.busi_category_id_lv2 as busi_catid_lv2,
  biz_map1.busi_category_name_lv2 as busi_catname_lv2,
  biz_map1.busi_category_id_lv3 as busi_catid_lv3,
  biz_map1.busi_category_name_lv3 as busi_catname_lv3,
  -- top1基础类目
  base_cat.top1_id as top1_base_catid,
  base_name1.market_category as top1_base_catname,
  base_cat.top1_prob as top1_base_prob,
  biz_map1.busi_category_id_lv1 as top1_busi_catid_lv1,
  biz_map1.busi_category_name_lv1 as top1_busi_catname_lv1,
  biz_map1.busi_category_id_lv2 as top1_busi_catid_lv2,
  biz_map1.busi_category_name_lv2 as top1_busi_catname_lv2,
  biz_map1.busi_category_id_lv3 as top1_busi_catid_lv3,
  biz_map1.busi_category_name_lv3 as top1_busi_catname_lv3,
  -- top2基础类目
  base_cat.top2_id as top2_base_catid,
  base_name2.market_category as top2_base_catname,
  base_cat.top2_prob as top2_base_prob,
  biz_map2.busi_category_id_lv1 as top2_busi_catid_lv1,
  biz_map2.busi_category_name_lv1 as top2_busi_catname_lv1,
  biz_map2.busi_category_id_lv2 as top2_busi_catid_lv2,
  biz_map2.busi_category_name_lv2 as top2_busi_catname_lv2,
  biz_map2.busi_category_id_lv3 as top2_busi_catid_lv3,
  biz_map2.busi_category_name_lv3 as top2_busi_catname_lv3,
  -- top3基础类目
  base_cat.top3_id as top3_base_catid,
  base_name3.market_category as top3_base_catname,
  base_cat.top3_prob as top3_base_prob,
  biz_map3.busi_category_id_lv1 as top3_busi_catid_lv1,
  biz_map3.busi_category_name_lv1 as top3_busi_catname_lv1,
  biz_map3.busi_category_id_lv2 as top3_busi_catid_lv2,
  biz_map3.busi_category_name_lv2 as top3_busi_catname_lv2,
  biz_map3.busi_category_id_lv3 as top3_busi_catid_lv3,
  biz_map3.busi_category_name_lv3 as top3_busi_catname_lv3,
  -- 基础类目数据来源
  base_cat.result_source as base_cat_result_source,
  base_cat.is_tencent as base_cat_is_tencent,
  base_cat.is_sft as base_cat_is_sft,
  base_cat.is_sjt as base_cat_is_sjt

from
  -- 基础类目v2
  wechat_pay_industry_test_thive::t_dwm_new_base_category_pred_full_info_day_test_data PARTITION(
    p_${YYYYMMDD}
  ) base_cat
  left join wechat_pay_industry_test_thive::t_dim_wxpay_mch_market_category_map_test_data base_name1 on base_cat.top1_id = base_name1.market_category_id
  left join wechat_pay_industry_test_thive::t_dim_wxpay_mch_market_category_map_test_data base_name2 on base_cat.top2_id = base_name2.market_category_id
  left join wechat_pay_industry_test_thive::t_dim_wxpay_mch_market_category_map_test_data base_name3 on base_cat.top3_id = base_name3.market_category_id
  -- 经营类目有效映射关系
  left join wechat_pay_industry_test_thive::t_dim_wxpay_business_category_map_result_day_test PARTITION(
    p_${YYYYMMDD}
  ) biz_map1 on base_cat.top1_id = biz_map1.base_category_id -- 经营类目关系
  left join wechat_pay_industry_test_thive::t_dim_wxpay_business_category_map_result_day_test PARTITION(
    p_${YYYYMMDD}
  ) biz_map2 on base_cat.top2_id = biz_map2.base_category_id -- 经营类目关系
  left join wechat_pay_industry_test_thive::t_dim_wxpay_business_category_map_result_day_test PARTITION(
    p_${YYYYMMDD}
  ) biz_map3 on base_cat.top3_id = biz_map3.base_category_id -- 经营类目关系