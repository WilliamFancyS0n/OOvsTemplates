//
// Created by Will on 3/29/2022.
//



#include "ICIntWrapper.h"

ICIntWrapper::ICIntWrapper(int intValue) : value(intValue) {}

ICIntWrapper::~ICIntWrapper() {

}

int ICIntWrapper::getValue() const {
    return value;
}
void ICIntWrapper::setValue(int intValue) {
    ICIntWrapper::value = intValue;
}



bool ICIntWrapper::operator<(const ICIntWrapper &rhs) const {
    if (this->value < rhs.value)
        return true;
    else
        return false;
}

bool ICIntWrapper::isLessThan(const IComparable &Comparable) {

    auto * tmp = dynamic_cast<const ICIntWrapper*>(&Comparable);
    if (this->value < tmp->value)
        return true;
    else
        return false;
}

void ICIntWrapper::printValue() const {
    std::cout << value << std::endl;
}





