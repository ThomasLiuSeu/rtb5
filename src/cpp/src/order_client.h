#ifndef SRC_ORDER_CLIENT_H
#define SRC_ORDER_CLIENT_H

#include <iostream>
#include <memory>
#include <string>

#include <grpc++/grpc++.h>
#include "proto/order.grpc.pb.h"
#include "proto/order.pb.h"

namespace RTB5 {

class OrderClient {
 public:
  OrderClient(std::shared_ptr<grpc::Channel> channel)
      : stub_(OrderService::NewStub(channel)) {}

  // Assambles the client's payload, sends it and presents the response back
  // from the server.
  bool Process(const OrderRequest& request, OrderResponse* response) {

    // Context for the client. It could be used to convey extra information to
    // the server and/or tweak certain RPC behaviors.
    grpc::ClientContext context;

    // The actual RPC.
    grpc::Status status = stub_->Process(&context, request, response);

    // Act upon its status.
    if (status.ok()) {
      return true;
    } else {
      return false;
    }
  }

 private:
  std::unique_ptr<OrderService::Stub> stub_;
};

} // RTB5

#endif // SRC_ORDER_CLIENT_H
