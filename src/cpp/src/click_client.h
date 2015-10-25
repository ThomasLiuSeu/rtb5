#ifndef SRC_CLICK_CLIENT_H
#define SRC_CLICK_CLIENT_H

#include <iostream>
#include <memory>
#include <string>

#include <grpc++/grpc++.h>
#include "proto/click.grpc.pb.h"
#include "proto/click.pb.h"

namespace RTB5 {

class ClickClient {
 public:
  ClickClient(std::shared_ptr<grpc::Channel> channel)
      : stub_(ClickService::NewStub(channel)) {}

  // Assambles the client's payload, sends it and presents the response back
  // from the server.
  bool Process(const ClickRequest& request, ClickResponse* response) {

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
  std::unique_ptr<ClickService::Stub> stub_;
};

} // RTB5

#endif // SRC_CLICK_CLIENT_H
