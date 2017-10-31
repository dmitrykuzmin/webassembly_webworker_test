#ifndef WEBASSEMBLY_STRING_CONTAINER_H
#define WEBASSEMBLY_STRING_CONTAINER_H

#include <stddef.h>
#include <string>

class StringContainer
{

public:

    // Initializes data_, size_ and offset_ with some default values.
    StringContainer();

    // Assigns a value to the testString_.
    void loadData();

    // Serializes testString_ into data_ using memcpy operation.
    char* serialize();

    // Deserializes testString_ from data_ using memcpy operation.
    void deserialize(char* data, int size);

    // Getter for size_.
    int getSerializedSize() const;

    // Getter for testString_.
    const std::string& getString() const;

private:

    // Variable, which stores serialized data.
    char* data_;

    // Serialized data size.
    size_t size_;

    // Variable to store current data offset during serialization and deserialization.
    size_t offset_;

    // String being serialized and deserialized.
    std::string testString_;
};

#endif //WEBASSEMBLY_STRING_CONTAINER_H
