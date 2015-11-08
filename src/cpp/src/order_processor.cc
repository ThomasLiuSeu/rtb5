
#include "src/order_processor.h"
#include <time.h>
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/bind.hpp>
#include <glog/logging.h>

namespace RTB5 {
//  
bool OrderProcessor::Process(const OrderRequest& order_request, OrderResponse* order_response) {
  std::vector<Order> orders;
  if (database.Load(order_request, &orders)) {
    for (const auto& order : orders) {
      Order* order_ptr = order_response->mutable_data()->add_orders();
      *order_ptr = order;
    }
    order_response->mutable_status()->set_error_code(0);
    order_response->mutable_status()->set_msg("Success");
  }
  return true;
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