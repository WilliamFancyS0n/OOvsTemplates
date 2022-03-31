//
// Created by Will on 3/29/2022.
//

#ifndef OOVSTEMPLATES_INTWRAPPER_H
#define OOVSTEMPLATES_INTWRAPPER_H
#include "IComparable.h"

class Intwrapper : public IComparable {
private:
    int value;
public:
    ~Intwrapper();

    Intwrapper(int intValue);

    int getValue() const;

    void setValue(int intValue);

    bool operator<(const Intwrapper& rhs) const;
    //bool isLessThan(const IComparable &Comparable) override;
    bool isLessThan(const IComparable &Comparable) override;

    void printValue() const override;
};


#endif //OOVSTEMPLATES_INTWRAPPER_H
