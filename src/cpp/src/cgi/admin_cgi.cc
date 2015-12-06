#include <iostream>
#include <vector>
#include <string>
#include <boost/lexical_cast.hpp>
#include <cgicc/Cgicc.h>
#include <cgicc/HTTPHTMLHeader.h>
#include <cgicc/HTMLClasses.h>
#include <json/reader.h>
#include <json/value.h>
#include <json/writer.h>
#include "src/client/admin_client.h"
#include "common/encoding/pb_to_json.h"

using namespace std;
using namespace cgicc;
using namespace RTB5;

<<<<<<< HEAD
void ParseGetToUnion(Union* upper_union, Cgicc& cgi) {
  form_iterator union_id = cgi.getElement("union_id");
  if (union_id != cgi.getElements().end()) {
    upper_union->set_union_id(boost::lexical_cast<uint64_t>(**union_id));
  }
  form_iterator union_name = cgi.getElement("union_name");
  if (union_name != cgi.getElements().end()) {
    upper_union->set_union_name(**union_name);
  } 
  form_iterator url_pattern = cgi.getElement("url_pattern");
  if (url_pattern != cgi.getElements().end()) {
    upper_union->set_url_pattern(**url_pattern);
  }
}

void ParseGetToUser(User* user, Cgicc& cgi) {
  form_iterator user_id = cgi.getElement("user_id");
  if (user_id != cgi.getElements().end()) {
    user->set_user_id(boost::lexical_cast<uint64_t>(**user_id));
  }
  form_iterator user_name = cgi.getElement("user_name");
  if (user_name != cgi.getElements().end()) {
    user->set_user_name(**user_name);
  } 
  form_iterator account = cgi.getElement("account");
  if (account != cgi.getElements().end()) {
    user->set_account(**account);
  }
  form_iterator password = cgi.getElement("password");
  if (password != cgi.getElements().end()) {
    user->set_password(**password);
  }
  form_iterator token = cgi.getElement("token");
  if (token != cgi.getElements().end()) {
    user->set_token(**token);
  }
}

void ParseGetToCampaign(Campaign* campaign, Cgicc& cgi) {
  form_iterator campaign_id = cgi.getElement("campaign_id");
  if (campaign_id != cgi.getElements().end()) {
    campaign->set_campaign_id(boost::lexical_cast<uint64_t>(**campaign_id));
  }
  form_iterator campaign_name = cgi.getElement("campaign_name");
  if (campaign_name != cgi.getElements().end()) {
    campaign->set_campaign_name(**campaign_name);
  } 
  form_iterator union_id = cgi.getElement("union_id");
  if (union_id != cgi.getElements().end()) {
    campaign->set_union_id(boost::lexical_cast<uint64_t>(**union_id));
  } 
  form_iterator pattern = cgi.getElement("pattern");
  if (pattern != cgi.getElements().end()) {
    campaign->set_pattern(**pattern);
  } 
  form_iterator percent = cgi.getElement("percent");
  if (percent != cgi.getElements().end()) {
    campaign->set_percent(boost::lexical_cast<double>(**percent));
=======
void ParseAddUnionRequst(AddUnionRequest* add_union_request, Cgicc& cgi) {
  form_iterator union_id = cgi.getElement("union_id");
  if (union_id != cgi.getElements().end()) {
    add_union_request->mutable_upper_union()->set_union_id(boost::lexical_cast<uint64_t>(**union_id));
  }
  form_iterator union_name = cgi.getElement("union_name");
  if (union_name != cgi.getElements().end()) {
    add_union_request->mutable_upper_union()->set_union_name(**union_name);
  } 
  form_iterator url_pattern = cgi.getElement("url_pattern");
  if (url_pattern != cgi.getElements().end()) {
    add_union_request->mutable_upper_union()->set_url_pattern(**url_pattern);
  }
}

void ParseAddUserRequst(AddUserRequest* add_user_request, Cgicc& cgi) {
  form_iterator user_id = cgi.getElement("user_id");
  if (user_id != cgi.getElements().end()) {
    add_user_request->mutable_user()->set_user_id(boost::lexical_cast<uint64_t>(**user_id));
  }
  form_iterator user_name = cgi.getElement("user_name");
  if (user_name != cgi.getElements().end()) {
    add_user_request->mutable_user()->set_user_name(**user_name);
  } 
  form_iterator account = cgi.getElement("account");
  if (account != cgi.getElements().end()) {
    add_user_request->mutable_user()->set_account(**account);
  }
  form_iterator password = cgi.getElement("password");
  if (password != cgi.getElements().end()) {
    add_user_request->mutable_user()->set_password(**password);
  }
  form_iterator token = cgi.getElement("token");
  if (token != cgi.getElements().end()) {
    add_user_request->mutable_user()->set_token(**token);
  }
}

void ParseAddCampaignRequst(AddCampaignRequest* add_campaign_request, Cgicc& cgi) {
  form_iterator campaign_id = cgi.getElement("campaign_id");
  if (campaign_id != cgi.getElements().end()) {
    add_campaign_request->mutable_campaign()->set_campaign_id(boost::lexical_cast<uint64_t>(**campaign_id));
  }
  form_iterator campaign_name = cgi.getElement("campaign_name");
  if (campaign_name != cgi.getElements().end()) {
    add_campaign_request->mutable_campaign()->set_campaign_name(**campaign_name);
  } 
  form_iterator union_id = cgi.getElement("union_id");
  if (union_id != cgi.getElements().end()) {
    add_campaign_request->mutable_campaign()->set_union_id(boost::lexical_cast<uint64_t>(**union_id));
  } 
  form_iterator pattern = cgi.getElement("pattern");
  if (pattern != cgi.getElements().end()) {
    add_campaign_request->mutable_campaign()->set_pattern(**pattern);
  } 
  form_iterator percent = cgi.getElement("percent");
  if (percent != cgi.getElements().end()) {
    add_campaign_request->mutable_campaign()->set_percent(boost::lexical_cast<double>(**percent));
>>>>>>> f93cdb02df5451d54c49fb3b7a8c561b16c57623
  } 
}

int main(int argc, char **argv) {
  try {
    Cgicc cgi;
    // Send HTTP header
    cout << HTTPHTMLHeader() << endl;
    //
    AdminRequest admin_request;
    // Print out the submitted element
    form_iterator action = cgi.getElement("action");
    if (action != cgi.getElements().end()) {
      if (**action == "add") {
        admin_request.set_action(AdminRequest_Action_Add);
      } else if (**action == "delete") {
        admin_request.set_action(AdminRequest_Action_Delete);
      } else if (**action == "update") {
        admin_request.set_action(AdminRequest_Action_Update);
<<<<<<< HEAD
      } else if (**action == "query") {
        admin_request.set_action(AdminRequest_Action_Query);
=======
>>>>>>> f93cdb02df5451d54c49fb3b7a8c561b16c57623
      } else {
        std::cout << "action invalid";
      }
    } 
    // Print out the submitted element
    form_iterator object = cgi.getElement("object");
    if (object != cgi.getElements().end()) {
      if (**object == "union") {
        admin_request.set_object(AdminRequest_Object_ObjUnion);
      } else if (**object == "user") {
        admin_request.set_object(AdminRequest_Object_ObjUser);
      } else if (**object == "campaign") {
        admin_request.set_object(AdminRequest_Object_ObjCampaign);
      } else {
        std::cout << "object invalid";
      }
    }

    switch (admin_request.action()) {
      case AdminRequest_Action_Add:
        switch (admin_request.object()) {
          case AdminRequest_Object_ObjUnion:
<<<<<<< HEAD
            ParseGetToUnion(admin_request.mutable_add_union_request()->mutable_upper_union(), cgi);
            break;
          case AdminRequest_Object_ObjUser:
            ParseGetToUser(admin_request.mutable_add_user_request()->mutable_user(), cgi);
            break;
          case AdminRequest_Object_ObjCampaign:
            ParseGetToCampaign(admin_request.mutable_add_campaign_request()->mutable_campaign(), cgi);
=======
            ParseAddUnionRequst(admin_request.mutable_add_union_request(), cgi);
            break;
          case AdminRequest_Object_ObjUser:
            ParseAddUserRequst(admin_request.mutable_add_user_request(), cgi);
            break;
          case AdminRequest_Object_ObjCampaign:
            ParseAddCampaignRequst(admin_request.mutable_add_campaign_request(), cgi);
>>>>>>> f93cdb02df5451d54c49fb3b7a8c561b16c57623
            break;
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

    //
    AdminResponse admin_response;

    AdminClient admin_client(grpc::CreateChannel("localhost:50053", grpc::InsecureCredentials()));
    if (admin_client.Process(admin_request, &admin_response)) {
      Json::Value json_value;
      std::string error_message;
      switch (admin_request.action()) {
        case AdminRequest_Action_Add:
          switch (admin_request.object()) {
            case AdminRequest_Object_ObjUnion:
              if(ProtoMessageToJsonValue(admin_response.add_union_response(), &json_value, &error_message)) {
                std::cout << json_value.toStyledString();
              }
              break;
            case AdminRequest_Object_ObjUser:
              if(ProtoMessageToJsonValue(admin_response.add_user_response(), &json_value, &error_message)) {
                std::cout << json_value.toStyledString();
              }
              break;
            case AdminRequest_Object_ObjCampaign:
              if(ProtoMessageToJsonValue(admin_response.add_campaign_response(), &json_value, &error_message)) {
                std::cout << json_value.toStyledString();
              }
              break;
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
        case AdminRequest_Action_Query:
          switch (admin_request.object()) {
            case AdminRequest_Object_ObjUnion:
              if(ProtoMessageToJsonValue(admin_response.query_union_response(), &json_value, &error_message)) {
                std::cout << json_value.toStyledString();
              }            
              break;
            case AdminRequest_Object_ObjUser:
              if(ProtoMessageToJsonValue(admin_response.query_user_response(), &json_value, &error_message)) {
                std::cout << json_value.toStyledString();
              }   
              break;
            case AdminRequest_Object_ObjCampaign:
              if(ProtoMessageToJsonValue(admin_response.query_campaign_response(), &json_value, &error_message)) {
                std::cout << json_value.toStyledString();
              }   
              break;
          }
          break; 
      }  
    } else {
      std::cout << "Request Failed";
    }
    // Close the HTML document
  }
  catch(exception& e) {
    // handle any errors - omitted for brevity
  }
}