#!/bin/bash

CheckTcpCloseWait() {
  tcp_num=`netstat -anp|grep CLOSE_WAIT|wc -l`
  echo "TcpCloseWait:"$tcp_num
  if [ $tcp_num -ge 50 ];
  then
    /etc/init.d/apache2 restart
  fi
}

CheckMemory() {
  total=`cat /proc/meminfo|grep "MemTotal:"|awk '{print $2}'`
  used=`cat /proc/meminfo|grep "MemFree:\|Buffers:\|^Cached:"|awk '{sum+=$2} END {print sum}'`
  rate=`echo "scale=2;$used/$total"|bc`
  echo "Mem used:":$rate
  mem_error=`echo "$rate>0.9 "|bc`
  if [ $mem_error -eq 1 ];
  then 
    /etc/init.d/apache2 restart
    killall -9 click_server
    killall -9 order_server
    killall -9 admin_server
    nohup ./admin_main &>../admin_main.log &
    nohup ./admin_server &>../admin_server.log &
    nohup ./click_server &>../click_sever.log &
    nohup ./order_server &>../order_server.log &
  fi
}

CheckTcpCloseWait;
CheckMemory;
