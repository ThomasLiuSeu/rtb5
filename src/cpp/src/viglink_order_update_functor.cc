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

bool ViglinkOrderUpdateFunctor::Init() {
  return true;
}

bool ViglinkOrderUpdateFunctor::JsonToProto(const std::string& tags, const std::string& cashback, Order* order) {
  LOG(ERROR) << tags <<  "   " << cashback;
  try {
    time_t now;
    time(&now);
    order->set_order_time(now);
    order->set_click_id(boost::lexical_cast<uint64_t>(tags));
    order->set_commission(boost::lexical_cast<double>(cashback));
    order->set_order_id(GenerateOrderID(*order)); 
  }
  catch(exception& e) {
    return false;
  }
  return true;
}

bool ViglinkOrderUpdateFunctor::Process(std::vector<Order>* orders) {
  const std::string url = "https://publishers.viglink.com/service/v1/cuidRevenue?lastDate=2015%2F01%2F10&period=month&secret=5147982ce378a512af1f5da6c849f4a38febe983";
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
  response = "{\"2012/01/01\": [{\"XYZ\":4.05,\"ABC\":2.20},{}], \"2012/01/02\": [{\"ABC\":13.02},{\"amazon.com\":3}]}";
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