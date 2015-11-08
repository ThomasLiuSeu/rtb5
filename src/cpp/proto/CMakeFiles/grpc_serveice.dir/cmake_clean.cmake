FILE(REMOVE_RECURSE
  "CMakeFiles/grpc_serveice"
  "click.grpc.pb.h"
  "click.grpc.pb.cc"
  "order.grpc.pb.h"
  "order.grpc.pb.cc"
  "admin_server.grpc.pb.h"
  "admin_server.grpc.pb.cc"
  "proto"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/grpc_serveice.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
