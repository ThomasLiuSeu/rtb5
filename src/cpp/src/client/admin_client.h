#ifndef SRC_CLIENT_ADMIN_CLIENT_H
#define SRC_CLIENT_ADMIN_CLIENT_H

#include <iostream>
#include <memory>
#include <string>

#include <grpc++/grpc++.h>
#include "proto/admin_server.grpc.pb.h"

namespace RTB5 {

class AdminClient {
 public:
  AdminClient(std::shared_ptr<grpc::Channel> channel)
      : stub_(AdminService::NewStub(channel)) {}

  // Assambles the client's payload, sends it and presents the response back
  // from the server.
  bool Process(const AdminRequest& request, AdminResponse* response) {

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
  std::unique_ptr<AdminService::Stub> stub_;
};

} // RTB5

#endif // SRC_CLIENT_ADMIN_CLIENT_H
