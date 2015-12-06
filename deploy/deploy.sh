#!/bin/sh

cd ..
proj_dir=`pwd`
deploy_dir=/var/www/$1
cgi_dir=$deploy_dir/cgi-bin/

rm -r $deploy_dir/*
mkdir -p $deploy_dir
mkdir -p $cgi_dir
cp $proj_dir/html/*.html $deploy_dir
cp $proj_dir/html/*.jsp $deploy_dir
cp -r $proj_dir/webroot $deploy_dir
cp $proj_dir/src/php/*.php $deploy_dir
cp -r $proj_dir/document $deploy_dir
cp $proj_dir/src/cpp/bin/* $cgi_dir

cd $cgi_dir
killall -9 click_server
killall -9 order_server

nohup ./admin_main &>../admin_main.log &
nohup ./admin_server &>../admin_server.log &
nohup ./click_server &>../click_sever.log &
nohup ./order_server &>../order_server.log &
