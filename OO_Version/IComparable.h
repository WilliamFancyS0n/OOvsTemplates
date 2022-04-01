//
// Created by Will on 3/29/2022.
//

#ifndef OOVSTEMPLATES_ICOMPARABLE_H
#define OOVSTEMPLATES_ICOMPARABLE_H

class IComparable {
public:
    virtual bool isLessThan(const IComparable & Comparable) = 0;
    virtual void printValue() const = 0;
};

#endif //OOVSTEMPLATES_ICOMPARABLE_H
