
#include "src/order_update_processor.h"
#include <time.h>
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/bind.hpp>
#include <glog/logging.h>


namespace RTB5 {
//  
bool OrderUpdateProcessor::Process(std::vector<Order>* orders) {
  for (auto& functor : functors) {
    if (!functor->Process(orders)) {
      LOG(ERROR) << functor->Name() << "Update Order Failed!";
    }
  }
  for (const auto order : *orders) {
    database.Insert(order);
  }
  return true;
}
//
bool OrderUpdateProcessor::Init() {
  if (!database.Open()) {
    LOG(ERROR) << "Database Open Failed!";
    return false;
  }
  OrderUpdateFunctor* haitao55 = new Haitao55OrderUpdateFunctor();
  haitao55->Init();
  functors.push_back(haitao55);
  OrderUpdateFunctor* viglink = new ViglinkOrderUpdateFunctor();
  viglink->Init();
  functors.push_back(viglink);
  return true;
}
//
bool OrderUpdateProcessor::GetClickInfo(std::vector<Order>* orders) {
  for (auto order : *orders) {
    if (database.Query(order.click_id(), order.mutable_click())) {
      Campaign campaign;
      if (database.Query(order.click().campaign_id(), &campaign)) {
        order.set_cash_back(order.commission() * campaign.percent());
      }
    }
  }
  return true;
}
//
OrderUpdateProcessor::~OrderUpdateProcessor() {
  for (auto& functor : functors) {
    delete functor;
  }
}

} // RTB5