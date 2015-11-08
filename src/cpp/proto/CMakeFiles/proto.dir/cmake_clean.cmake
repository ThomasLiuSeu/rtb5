FILE(REMOVE_RECURSE
  "CMakeFiles/proto"
  "click.pb.h"
  "click.pb.cc"
  "order.pb.h"
  "order.pb.cc"
  "campaign.pb.h"
  "campaign.pb.cc"
  "union.pb.h"
  "union.pb.cc"
  "user.pb.h"
  "user.pb.cc"
  "admin_server.pb.h"
  "admin_server.pb.cc"
  "proto"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/proto.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
