#!/bin/bash

./generate_cmake_files.sh
cd cmake_build
emmake make
cd ..
mkdir -p bin
cd bin
emcc libtest.a -o test.html
cd ..
./compile_webworker.sh
mv test_worker.js bin/test_worker.js
mv test_worker.wasm bin/test_worker.wasm
