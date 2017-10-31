# WebAssembly with webworker test

This repository contains small WebAssembly program, which showcases a strange behaviour which I encountered when trying to call webworker multiple times and serialize/deserialize data in it.

Prerequisites to run the program:

1. Emscripten installed and exported to the PATH to support commands like "emcc", "emconfigure", "emmake";
2. Python.

How to run the program:

1. Run ./build.sh;
2. Run ./start_server.sh;
3. Navigate to the localhost:8000/test.html and observe results printed to the emscripten console.

First 3 string in the results should be similar and human-readable, while forth is some random sequence of bytes.

In short about what happens in the program.

A simple StringContainer class is created, it stores one string as a class member. StringContainer can be serialized and deserialized via corresponding functions. In these functions, string bytes are copied to and from serialization data via memcpy.

The general flow is as follows:

1. Create StringContainer;
2. Serialize it and send to webworker;
3. Inside webworker deserialize the container;
4. Then serialize it again and send to the worker callback;
5. In worker callback deserialize StringContainer sent by webworker.

During first call everything works fine, but when trying to perform these operations for the second time, webworker sends corrupted data to the callback.
