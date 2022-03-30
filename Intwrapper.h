//
// Created by Will on 3/29/2022.
//

#ifndef OOVSTEMPLATES_INTWRAPPER_H
#define OOVSTEMPLATES_INTWRAPPER_H
#include "IComparable.h"

class Intwrapper : public IComparable {
public:
    Intwrapper(int intValue);
    int getValue() const;
    void setValue(int intValue);

    bool operator<(const Intwrapper& rhs) const;
    //bool isLessThan(const IComparable &Comparable) override;
    bool isLessThan(const IComparable &Comparable) override;

    void printValue() const override;

private:

    int value;
};


#endif //OOVSTEMPLATES_INTWRAPPER_H
