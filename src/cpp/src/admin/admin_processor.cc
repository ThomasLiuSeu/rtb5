
#include "src/admin/admin_processor.h"
#include <time.h>
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/bind.hpp>
#include <glog/logging.h>

namespace RTB5 {
//  
bool AdminProcessor::Process(const AdminRequest& admin_request,
                             AdminResponse* admin_response) {
  LOG(ERROR) << admin_request.Utf8DebugString();
  switch (admin_request.action()) {
    case AdminRequest_Action_Add:
      switch (admin_request.object()) {
        case AdminRequest_Object_ObjUnion:
          return Process(admin_request.add_union_request(), admin_response->mutable_add_union_response());
        case AdminRequest_Object_ObjUser:
          return Process(admin_request.add_user_request(), admin_response->mutable_add_user_response());
        case AdminRequest_Object_ObjCampaign:
          return Process(admin_request.add_campaign_request(), admin_response->mutable_add_campaign_response());
      }
      break;
    case AdminRequest_Action_Delete:
      switch (admin_request.object()) {
        case AdminRequest_Object_ObjUnion:
          break;
        case AdminRequest_Object_ObjUser:
          break;
        case AdminRequest_Object_ObjCampaign:
          break;
      }
      break;
    case AdminRequest_Action_Update:
      switch (admin_request.object()) {
        case AdminRequest_Object_ObjUnion:
          break;
        case AdminRequest_Object_ObjUser:
          break;
        case AdminRequest_Object_ObjCampaign:
          break;
      }
      break;  
  }
  return true; 
}
//
bool AdminProcessor::Process(const AddUserRequest& add_user_request,
                             AddUserResponse* add_user_response) {
  if (database.Insert(add_user_request.user())) {
    add_user_response->set_status(AddUserResponse_OperateStatus_SUCCESS);
  } else {
    add_user_response->set_status(AddUserResponse_OperateStatus_USER_ID_ALREADY_EXIST);
  }
  return true;
}
//
bool AdminProcessor::Process(const AddCampaignRequest& add_campaign_request,
                             AddCampaignResponse* add_campaign_response) {
  if (database.Insert(add_campaign_request.campaign())) {
    add_campaign_response->set_status(AddCampaignResponse_OperateStatus_SUCCESS);
  } else {
    add_campaign_response->set_status(AddCampaignResponse_OperateStatus_CAMPAIGN_ID_ALREADY_EXIST);
  }
  return true;
}
//
bool AdminProcessor::Process(const AddUnionRequest& add_union_request,
                             AddUnionResponse* add_union_response) {
  if (database.Insert(add_union_request.upper_union())) {
    add_union_response->set_status(AddUnionResponse_OperateStatus_SUCCESS);
  } else {
    add_union_response->set_status(AddUnionResponse_OperateStatus_UNION_ID_ALREADY_EXIST);
  }
  return true;
}
//
bool AdminProcessor::Init() {
  if (!database.Open()) {
    LOG(ERROR) << "Database Open Failed!";
    return false;
  }
  return true;
}
//



} // RTB5