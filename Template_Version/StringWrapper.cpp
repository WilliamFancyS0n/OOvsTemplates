#include "StringWrapper.h"

StringWrapper::StringWrapper(const std::string &value) : value(value) {}

const std::string &StringWrapper::getValue() const {
    return value;
}
void StringWrapper::setValue(const std::string &value) {
    StringWrapper::value = value;
}

bool StringWrapper::operator<(const StringWrapper &rhs) const {
    if (this->value.compare(rhs.value) < 0)
        return true;
    else
        return false;
}
