#include "string_container.h"

#include <emscripten/emscripten.h>

extern "C"
{

// Function that deserializes StringContainer and then serializes it back.
// If calling this multiple times, data gets corrupted.
void test(char* data, int size) {

    // Deserialize StringContainer.
    StringContainer stringContainer;
    stringContainer.deserialize(data, size);

    delete[] data;

    // Serialize StringContainer back.
    char* serializedData = stringContainer.serialize();
    int serializedLength = stringContainer.getSerializedSize();

    // Send serialized data to callback.
    emscripten_worker_respond(serializedData, serializedLength);
    delete[] serializedData;
}

}
