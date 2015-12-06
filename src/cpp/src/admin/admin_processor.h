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
  //
  bool Process(const AddUserRequest& add_user_request,
               AddUserResponse* add_user_response);
  //
  bool Process(const AddCampaignRequest& add_campaign_request,
               AddCampaignResponse* add_paign_response);
  //
  bool Process(const AddUnionRequest& add_union_request,
               AddUnionResponse* add_union_response);
  //
  bool Process(const QueryUserRequest& query_user_request,
               QueryUserResponse* query_user_response);
  //
  bool Process(const QueryCampaignRequest& query_campaign_request,
               QueryCampaignResponse* query_paign_response);
  //
  bool Process(const QueryUnionRequest& add_union_request,
               QueryUnionResponse* query_union_response);
 private:


 private:
  //
  Database database;
};

} // RTB5

#endif // SRC_ADMIN_ADMIN_PROCESSOR_H
