#ifndef SRC_ADMIN_ADMIN_PROCESSOR_H
#define SRC_ADMIN_ADMIN_PROCESSOR_H

#include <string>
#include <boost/functional/hash.hpp>
#include "proto/click.pb.h"
#include "proto/campaign.pb.h"
#include "proto/union.pb.h"
#include "proto/user.pb.h"
#include "src/database.h"
#include "proto/admin_server.grpc.pb.h"

namespace RTB5 {

class AdminProcessor {
 public:
  //
  bool Init();
  //
  bool Process(const AdminRequest& admin_request, AdminResponse* admin_response);

 private:


 private:
  //
  Database database;
};

} // RTB5

#endif // SRC_ADMIN_ADMIN_PROCESSOR_H
