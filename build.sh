#!/bin/bash

git submodule update --init
cd tiny/cmake/
./build_linux_x86.sh 
cd -
cd tinyfx/cmake/
./build_linux_x86.sh 
cd -
cd tinymdns/cmake/
./build_linux_x86.sh 
cd -
cd tinycrypto/cmake/
./build_linux_x86.sh 
cd -
mkdir build
cd build/
cmake ..
make
ls ../target
