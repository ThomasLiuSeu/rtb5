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
#include "src/order_client.h"
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
    OrderRequest order_request;
    //
    OrderResponse order_response;

    // Print out the submitted element
    form_iterator begin_time = cgi.getElement("begin_time");
    if (begin_time != cgi.getElements().end()) {
      order_request.set_begin_time(boost::lexical_cast<uint64_t>(**begin_time));
    }
    // Print out the submitted element
    form_iterator end_time = cgi.getElement("end_time");
    if (end_time != cgi.getElements().end()) {
      order_request.set_end_time(boost::lexical_cast<uint64_t>(**end_time));
    } 
    // Print out the submitted element
    form_iterator uid = cgi.getElement("uid");
    if (uid != cgi.getElements().end()) {
      order_request.set_user_id(boost::lexical_cast<uint64_t>(**uid));
    }
    // Print out the submitted element
    form_iterator tags = cgi.getElement("tags");
    if (tags != cgi.getElements().end()) {
      order_request.set_tags(**tags);
    }

    OrderClient order_client(grpc::CreateChannel("localhost:50052", grpc::InsecureCredentials()));
    if (order_client.Process(order_request, &order_response)) {
      for (auto order : order_response.orders()) {
        Json::Value json_value;
        std::string error_message;
        if(ProtoMessageToJsonValue(order_response, &json_value, &error_message)) {
          std::cout << json_value.toStyledString();
        }
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