//
// Created by Will on 3/29/2022.
//

#include "Intwrapper.h"

Intwrapper::Intwrapper(int intValue) : value(intValue) {}

int Intwrapper::getValue() const {
    return value;
}
void Intwrapper::setValue(int intValue) {
    Intwrapper::value = intValue;
}

bool Intwrapper::operator<(const Intwrapper &rhs) const {
    if (this->value < rhs.value)
        return true;
    else
        return false;
}

bool Intwrapper::isLessThan(const IComparable &Comparable) {
    auto * tmp = dynamic_cast<const Intwrapper*>(&Comparable);
    if (this->value < tmp->value)
        return true;
    else
        return false;
}

void Intwrapper::printValue() const {
    std::cout << value << std::endl;
}

//bool Intwrapper::isLessThan(const IComparable &Comparable) {
//    auto * tmp = dynamic_cast<Intwrapper*>(&Comparable);
//    if (this->value < tmp->value)
//        return true;
//    else
//        return false;
//}




