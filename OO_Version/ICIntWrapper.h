//
// Created by Will on 3/29/2022.
//

#ifndef OOVSTEMPLATES_ICINTWRAPPER_H
#define OOVSTEMPLATES_ICINTWRAPPER_H
#include "IComparable.h"

class ICIntWrapper : public IComparable {
private:
    int value;
public:
    ~ICIntWrapper();

    ICIntWrapper(int intValue);

    int getValue() const;

    void setValue(int intValue);

    bool operator<(const ICIntWrapper& rhs) const;
    //bool isLessThan(const IComparable &Comparable) override;
    bool isLessThan(const IComparable &Comparable) override;

    void printValue() const override;
};


#endif //OOVSTEMPLATES_ICINTWRAPPER_H
