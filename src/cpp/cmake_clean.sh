#!/bin/bash
CleanSubdir()
{
  pwd
  rm -rf ./cmake_install.cmake
  rm -rf ./CMakeFiles
  rm -rf ./Makefile
  rm -rf ./CMakeCache.txt
  rm -rf ./*.pb.h
  rm -rf ./*.pb.cc	
  filelist=`ls`
  for file in $filelist
  do
  	if [[ -d $file && "$file" != "thirdparty" ]]
    then 
      cd $file
      CleanSubdir
      cd ..
    fi
  done
}

echo "rm cmake cache begin..."
CleanSubdir
echo "rm cmake cache end..."
