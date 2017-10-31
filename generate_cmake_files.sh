#!/bin/bash

CWD=$PWD

BUILD_DIR=$CWD/cmake_build

mkdir -p $BUILD_DIR

cd $BUILD_DIR

emconfigure cmake -G"KDevelop3 - Unix Makefiles" -DCMAKE_BUILD_TYPE=Release $CWD
