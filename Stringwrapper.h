//
// Created by Will on 3/29/2022.
//

#ifndef OOVSTEMPLATES_STRINGWRAPPER_H
#define OOVSTEMPLATES_STRINGWRAPPER_H
#include <string>

class Stringwrapper : public IComparable {
private:
    std::string value;
public:

    Stringwrapper(const std::string &stringValue);

    const std::string &getValue() const;

    void setValue(const std::string &stringValue);

    bool operator<(const Stringwrapper& rhs) const;

    bool isLessThan(const IComparable &Comparable) override;

    void printValue() const override;
};


#endif //OOVSTEMPLATES_STRINGWRAPPER_H
