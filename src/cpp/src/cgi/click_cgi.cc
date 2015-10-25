#include <iostream>
#include <vector>
#include <string>
#include <boost/lexical_cast.hpp>
#include <cgicc/Cgicc.h>
#include <cgicc/HTTPHTMLHeader.h>
#include <cgicc/HTMLClasses.h>
#include "src/click_client.h"

using namespace std;
using namespace cgicc;
using namespace RTB5;

int main(int argc, char **argv) {
  try {
    Cgicc cgi;
    // Send HTTP header
    cout << HTTPHTMLHeader() << endl;
    //
    ClickRequest click_request;
    //
    ClickResponse click_response;

    // Print out the submitted element
    form_iterator url = cgi.getElement("url");
    if (url != cgi.getElements().end()) {
      click_request.set_origin_url(**url);
    } 
    // Print out the submitted element
    form_iterator uid = cgi.getElement("uid");
    if (uid != cgi.getElements().end()) {
      click_request.set_user_id(boost::lexical_cast<uint64_t>(**uid));
    }
    // Print out the submitted element
    form_iterator tags = cgi.getElement("tags");
    if (tags != cgi.getElements().end()) {
      click_request.set_tags(**tags);
    }

    ClickClient click_client(grpc::CreateChannel("localhost:50051", grpc::InsecureCredentials()));
    if (click_client.Process(click_request, &click_response)) {
      std::cout << click_response.second_jump_url();
    } else {
      std::cout << "Request Failed";
    }
    // Close the HTML document
  }
  catch(exception& e) {
    // handle any errors - omitted for brevity
  }
}