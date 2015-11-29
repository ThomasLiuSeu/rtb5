#include "src/viglink_order_update_functor.h"
#include <time.h>
#include <fstream>
#include <sstream>
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/bind.hpp>
#include <boost/date_time.hpp>
#include <glog/logging.h>

using namespace std;

namespace RTB5 {

template <class T>
static std::string ConvertToString(T num) {
  return boost::lexical_cast<std::string>(num);
}

bool ViglinkOrderUpdateFunctor::Init() {
  return true;
}

bool ViglinkOrderUpdateFunctor::JsonToProto(const std::string& tags, const std::string& cashback, Order* order) {
  try {
    order->set_click_id(boost::lexical_cast<uint64_t>(tags));
    order->set_order_time(GetClickTime(boost::lexical_cast<uint64_t>(tags)));
    order->set_commission(boost::lexical_cast<double>(cashback));
    order->set_cash_back(order->commission());
    order->set_order_id(GenerateOrderID(*order));
    // 业务逻辑暂时硬编码，后续改为配置 
    order->set_currency_type("USD");
    order->set_status(1);
    order->set_trading_volume(order->commission() * 10);
  }
  catch(exception& e) {
    return false;
  }
  return true;
}

bool ViglinkOrderUpdateFunctor::Process(std::vector<Order>* orders) {
  time_t now;
  time(&now);
  struct tm* ptm  = localtime(&now);
  uint64_t year = ptm->tm_year + 1900;
  uint64_t month = ptm->tm_mon + 1;
  uint64_t day = ptm->tm_mday;
  const std::string url = "https://publishers.viglink.com/service/v1/cuidRevenue?lastDate="+ ConvertToString(year) +"%2F" + ConvertToString(month) +"%2F" + ConvertToString(day) + "&period=month&secret=5147982ce378a512af1f5da6c849f4a38febe983";
  std::string response;
  const std::string file = "viglink.json";
  std::string cmd = "wget \"" + url + "\" -O " + file;
  LOG(ERROR) << "Cmd:" << cmd;

  if (system(cmd.c_str()) != 0) {
    LOG(ERROR) << "Gets Failed:" << url;
    return false; 
  }
  std::ifstream ifs(file.c_str());
  std::stringstream ss;
  ss << ifs.rdbuf() ;
  response = ss.str();
  LOG(ERROR) << "Response:" << response;
  Json::Reader reader;
  Json::Value value;
  if (reader.parse(response, value)) {
    for (const auto& day_json : value) {
      for (const auto& order_jsons : day_json) {
        for (const auto& memeber : order_jsons.getMemberNames()) {
          Order order;
          if (JsonToProto(memeber, order_jsons[memeber].asString(), &order)) {
            orders->push_back(order);
          } else {
            LOG(ERROR) << "Failed to read " << memeber;
          }
        }
      }      
    }
  } else {
    LOG(ERROR) << "Response Parse Failed";
  }
  LOG(ERROR) << "Viglink Orders" << orders->size();
  return true;
}

} // RTB5