#ifndef SRC_CLICK_PROCESSOR_H
#define SRC_CLICK_PROCESSOR_H

#include <string>
#include <boost/functional/hash.hpp>
#include "proto/click.pb.h"
#include "proto/campaign.pb.h"
#include "proto/union.pb.h"
#include "src/database.h"

namespace RTB5 {

class OrderProcessor {
 public:
  //
  bool Init();
  //
  bool Process(const OrderRequest& order_request, OrderResponse* order_response);

 private:

 private:
  //
  Database database;
};

} // RTB5

#endif // SRC_CLICK_PROCESSOR_H
