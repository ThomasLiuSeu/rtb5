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

int main(int argc, char **argv) {
  try {
    Cgicc cgi;
    // Send HTTP header
    cout << HTTPHTMLHeader() << endl;
    //
    AdminRequest admin_request;
    //
    AdminResponse admin_response;

    AdminClient admin_client(grpc::CreateChannel("localhost:50053", grpc::InsecureCredentials()));
    if (admin_client.Process(admin_request, &admin_response)) {
      Json::Value json_value;
      std::string error_message;
      if(ProtoMessageToJsonValue(admin_response, &json_value, &error_message)) {
        std::cout << json_value.toStyledString();
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