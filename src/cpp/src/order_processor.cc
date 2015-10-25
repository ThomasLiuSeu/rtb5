
#include "src/order_processor.h"
#include <time.h>
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/bind.hpp>
#include <glog/logging.h>

namespace RTB5 {
//  
bool OrderProcessor::Process(const OrderRequest& order_request, std::vector<Order>* orders) {
  return database.Load(order_request, orders);
}
//
bool OrderProcessor::Init() {
  if (!database.Open()) {
    LOG(ERROR) << "Database Open Failed!";
    return false;
  }
  return true;
}

} // RTB5