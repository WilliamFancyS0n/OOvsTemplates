//
// Created by Will on 3/29/2022.
//

#include "ICStringWrapper.h"

ICStringWrapper::ICStringWrapper(const std::string &value) : value(value) {}

const std::string &ICStringWrapper::getValue() const {
    return value;
}
void ICStringWrapper::setValue(const std::string &value) {
    ICStringWrapper::value = value;
}

bool ICStringWrapper::operator<(const ICStringWrapper &rhs) const {
    if (this->value.compare(rhs.value) < 0)
        return true;
    else
        return false;
}

void ICStringWrapper::printValue() const {
    std::cout << value << std::endl;
}

bool ICStringWrapper::isLessThan(const IComparable &Comparable) {
    auto * tmp = dynamic_cast<const ICStringWrapper*>(&Comparable);
    if (this->value.compare(tmp->value) < 0)
        return true;
    else
        return false;
}
