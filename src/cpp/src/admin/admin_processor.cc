
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