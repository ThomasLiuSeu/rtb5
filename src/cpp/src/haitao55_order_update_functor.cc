#include "src/haitao55_order_update_functor.h"
#include <time.h>
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/bind.hpp>
#include <boost/date_time.hpp>
#include <glog/logging.h>
#include <stdlib.h>  

namespace RTB5 {

time_t StringToTime(const std::string& str) {
  return boost::lexical_cast<uint64_t>(str);
}

bool Haitao55OrderUpdateFunctor::Init() {
  return true;
}

bool Haitao55OrderUpdateFunctor::JsonToProto(const Json::Value& order_json, Order* order) {
  try {
    order->set_order_time(StringToTime(order_json["order_time"].asString()));
    order->set_valid_time(StringToTime(order_json["valid_time"].asString()));
    order->set_trading_volume(boost::lexical_cast<double>(order_json["sale_amount"].asString())*100);
    order->set_commission(boost::lexical_cast<double>(order_json["cashback"].asString())*100);
    order->set_cash_back(order->commission());
    order->set_status(boost::lexical_cast<uint64_t>(order_json["status"].asString()));
    order->set_click_id(boost::lexical_cast<uint64_t>(order_json["tagcode"].asString()));
    order->set_currency_type(order_json["currency_type"].asString());
    order->set_order_id(GenerateOrderID(*order)); 
  } catch(std::exception& e) {
    return false;
  }
  return true;
}

bool Haitao55OrderUpdateFunctor::Process(std::vector<Order>* orders) {
  const std::string url = "union.55haitao.com/union.php?mod=api_cashback";
  const std::string post = "token=ZhZIC5HluW3vVdlO&begin_date=2014-01-01&end_date=2017-10-01";
  std::string response;
  if (http_client.Post(url, post, response) != 0 || response.empty()) {
    LOG(ERROR) << "Post Failed:" << url;
  }
  Json::Reader reader;
  Json::Value value;
  if (reader.parse(response, value)) {
    int ret = value["status"]["code"].asInt();
    if (ret != 0) {
      LOG(ERROR) << "Haitao55 Update Order Failed:" << value["status"]["msg"].asString();
    } else {
      LOG(ERROR) << "Haitao55 Update Order Success:" << value["status"]["msg"].asString();    	
    }
    const Json::Value& orders_json = value["data"];
    for (const auto& order_json : orders_json) {
      Order order;
      if (JsonToProto(order_json, &order)) {
        orders->push_back(order);
      } else {
        LOG(ERROR) << "Failed to read " << order_json.toStyledString();
      }
    }
  } else {
    LOG(ERROR) << "Response Parse Failed";
  }
  LOG(ERROR) << "Haitao55 Orders" << orders->size();
  return true;
}

} // RTB5