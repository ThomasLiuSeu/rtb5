#ifndef SRC_VIGLINK_ORDER_UPDATE_FUNCTOR_H
#define SRC_VIGLINK_ORDER_UPDATE_FUNCTOR_H

#include <string>
#include <json/json.h>
#include "src/http_client.h"
#include "src/order_update_functor.h"

namespace RTB5 {

class ViglinkOrderUpdateFunctor : public OrderUpdateFunctor {
 public:
  //
  bool Init();
  //
  bool Process(std::vector<Order>* orders);
  //
  virtual std::string Name() {
    return "Viglink";
  }
  //
  virtual ~ViglinkOrderUpdateFunctor() {}

 private:
  // json convert to Proto
  bool JsonToProto(const std::string& tags, const std::string& cashback, Order* order);
};

} // RTB5

#endif // SRC_VIGLINK_ORDER_UPDATE_FUNCTOR_H
