#include "string_container.h"

StringContainer::StringContainer()
        : data_(nullptr)
        , size_(0)
        , offset_(0) {
}


void StringContainer::loadData() {
    testString_ = "aBitLongTestingString";
}

char *StringContainer::serialize() {
    size_t serializedStringSize = testString_.size() + testString_.size() * sizeof(char);
    size_t serializedDataSize = serializedStringSize + 1;

    // Reserve memory for data.
    size_ = serializedDataSize;
    data_ = new char[size_];
    offset_ = 0;

    // Serialize string size.
    size_t stringSize = testString_.size();
    memcpy(data_ + offset_, &stringSize, sizeof(stringSize));
    offset_ += sizeof(stringSize);

    //Serialize string data.
    size_t stringDataCount = testString_.size() * sizeof(char);
    memcpy(data_ + offset_, testString_.data(), stringDataCount);
    offset_ += stringDataCount;

    return data_;
}

void StringContainer::deserialize(char* data, int size) {
    data_ = data;
    size_ = size;
    offset_ = 0;

    // Deserialize string size.
    size_t stringSize = 0;
    memcpy(&stringSize, data_ + offset_, sizeof(stringSize));
    testString_.resize(stringSize);
    offset_ += sizeof(stringSize);

    // Deserialize string data.
    size_t stringDataCount = stringSize * sizeof(char);
    memcpy(&testString_[0], data_ + offset_, stringDataCount);
    offset_ += stringDataCount;
}

int StringContainer::getSerializedSize() const {
    return size_;
}

const std::string& StringContainer::getString() const {
    return testString_;
}
