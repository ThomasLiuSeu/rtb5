/*
 *
 * Copyright 2015, Google Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *     * Neither the name of Google Inc. nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#include <iostream>
#include <memory>
#include <string>
#include <glog/logging.h> 
#include <gflags/gflags.h> 
#include <grpc++/grpc++.h>
#include "proto/admin_server.grpc.pb.h"
#include "src/admin/admin_processor.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using namespace RTB5;
using RTB5::AdminRequest;
using RTB5::AdminResponse;
using RTB5::AdminService;


// Logic and data behind the server's behavior.
class AdminServiceImpl final: public RTB5::AdminService::Service {
 public:
  //
  bool Init() {
    LOG(ERROR) << "Init";
    if (!admin_processor.Init()) {
      return false;
    }
  }
  //
  Status Process(ServerContext* context, const AdminRequest* request,
                 AdminResponse* response) {
    if (admin_processor.Process(*request, response)) {
      return Status::OK;
    } else {
      return Status::CANCELLED;
    }
  }

 private:
  AdminProcessor admin_processor;

};

bool RunServer() {
  std::string server_address("0.0.0.0:50053");
  AdminServiceImpl service;
  if (!service.Init()) {
    LOG(ERROR) << "Init Failed";
    return false;
  }
  ServerBuilder builder;
  // Listen on the given address without any authentication mechanism.
  builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
  // Register "service" as the instance through which we'll communicate with
  // clients. In this case it corresponds to an *synchronous* service.
  builder.RegisterService(&service);
  // Finally assemble the server.
  std::unique_ptr<Server> server(builder.BuildAndStart());
  std::cout << "Server listening on " << server_address << std::endl;

  // Wait for the server to shutdown. Note that some other thread must be
  // responsible for shutting down the server for this call to ever return.
  server->Wait();
  return true;
}

int main(int argc, char** argv) {
  ::google::InitGoogleLogging(argv[0]); 
  gflags::ParseCommandLineFlags(&argc, &argv, true);
  return RunServer();
}