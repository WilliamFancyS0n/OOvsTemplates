//
// Created by Will on 3/29/2022.
//

#include "Stringwrapper.h"

Stringwrapper::Stringwrapper(const std::string &value) : value(value) {}

const std::string &Stringwrapper::getValue() const {
    return value;
}
void Stringwrapper::setValue(const std::string &value) {
    Stringwrapper::value = value;
}

bool Stringwrapper::operator<(const Stringwrapper &rhs) const {
    if (this->value.compare(rhs.value) < 0)
        return true;
    else
        return false;
}

void Stringwrapper::printValue() const {
    std::cout << value << std::endl;
}

bool Stringwrapper::isLessThan(const IComparable &Comparable) {
    auto * tmp = dynamic_cast<const Stringwrapper*>(&Comparable);
    if (this->value.compare(tmp->value) < 0)
        return true;
    else
        return false;
}
