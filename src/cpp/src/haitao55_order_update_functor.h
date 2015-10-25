#ifndef SRC_HAITAO55_ORDER_UPDATE_FUNCTOR_H
#define SRC_HAITAO55_ORDER_UPDATE_FUNCTOR_H

#include <string>
#include <json/json.h>
#include "src/http_client.h"
#include "src/order_update_functor.h"

namespace RTB5 {

class Haitao55OrderUpdateFunctor : public OrderUpdateFunctor {
 public:
  //
  bool Init();
  //
  bool Process(std::vector<Order>* orders);
  //
  virtual std::string Name() {
    return "Haitao55";
  }
  //
  virtual ~Haitao55OrderUpdateFunctor() {}

 private:
  // json convert to Proto
  bool JsonToProto(const Json::Value& order_json,Order* order);
};

} // RTB5

#endif // SRC_HAITAO55_ORDER_UPDATE_FUNCTOR_H
