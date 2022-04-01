//
// Created by Will on 3/29/2022.
//

#ifndef OOVSTEMPLATES_ICSTRINGWRAPPER_H
#define OOVSTEMPLATES_ICSTRINGWRAPPER_H
#include <string>

class ICStringWrapper : public IComparable {
private:
    std::string value;
public:

    ICStringWrapper(const std::string &stringValue);

    const std::string &getValue() const;

    void setValue(const std::string &stringValue);

    bool operator<(const ICStringWrapper& rhs) const;

    bool isLessThan(const IComparable &Comparable) override;

    void printValue() const override;
};


#endif //OOVSTEMPLATES_ICSTRINGWRAPPER_H
