
#include "IntWrapper.h"

IntWrapper::IntWrapper(int intValue) : value(intValue) {}

int IntWrapper::getValue() const {
    return value;
}

void IntWrapper::setValue(int intValue) {
    IntWrapper::value = intValue;
}

bool IntWrapper::operator<(const IntWrapper &rhs) const {
    if (this->value < rhs.value)
        return true;
    else
        return false;
}







