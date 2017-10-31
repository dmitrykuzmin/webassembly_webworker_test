#!/bin/bash

emcc                                                            \
   test_worker.cpp                               		\
   -s WASM=1                                                   	\
   -s ALLOW_MEMORY_GROWTH=1					\
   -s BUILD_AS_WORKER=1                                        	\
   -s EXPORTED_FUNCTIONS="['_test']"                  		\
   -I./                                                        	\
   ./bin/libtest.a                           			\
   -o test_worker.js
