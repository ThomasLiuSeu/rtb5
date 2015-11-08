FILE(REMOVE_RECURSE
  "CMakeFiles/campaign_pb.dir/campaign.pb.cc.o"
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
  "../lib/libcampaign_pb.pdb"
  "../lib/libcampaign_pb.a"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang CXX)
  INCLUDE(CMakeFiles/campaign_pb.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
