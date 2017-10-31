#include "stdio.h"
#include <thread>
#include <emscripten/emscripten.h>
#include "string_container.h"

worker_handle worker = emscripten_create_worker("test_worker.js");

// Second callback which receives wrong data.
void workerCallbackInner(char* data, int size, void* args)
{
    StringContainer stringContainer;
    stringContainer.deserialize(data, size);

    delete [] data;

    printf("String deserialized in second worker callback: %s \n", stringContainer.getString().c_str());
}

// First callback, which receives correct data.
void workerCallback(char* data, int size, void* args)
{
    StringContainer stringContainer;
    stringContainer.deserialize(data, size);

    delete [] data;

    printf("String deserialized in first worker callback: %s \n", stringContainer.getString().c_str());

    StringContainer newStringContainer;
    newStringContainer.loadData();

    printf("String passed to second worker call: %s \n", newStringContainer.getString().c_str());

    emscripten_call_worker(
            worker,
            "test",
            newStringContainer.serialize(),
            newStringContainer.getSerializedSize(),
            workerCallbackInner,
            (void *) 0
    );
}

// This program creates simple string container, which can be serialized and deserialized.
// Then it sends serialized container to the webworker.
// The webworker deserializes it, performs some actions on it and then sends serialized container back.
// When performing these operations for the first time, everything works fine.
// But during further calls webworker sends back some wrong data, which can't be properly deserialized.
int main(int argc, char** argv) {
    StringContainer stringContainer;
    stringContainer.loadData();

    printf("String passed to first worker call: %s \n", stringContainer.getString().c_str());

    emscripten_call_worker(
            worker,
            "test",
            stringContainer.serialize(),
            stringContainer.getSerializedSize(),
            workerCallback,
            (void *) 0
    );
}