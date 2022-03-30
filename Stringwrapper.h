//
// Created by Will on 3/29/2022.
//

#ifndef OOVSTEMPLATES_STRINGWRAPPER_H
#define OOVSTEMPLATES_STRINGWRAPPER_H
#include <string>

class Stringwrapper : public IComparable {
public:

    Stringwrapper(const std::string &stringValue);

    const std::string &getValue() const;
    void setValue(const std::string &stringValue);

    bool operator<(const Stringwrapper& rhs) const;

    //bool isLessThan(IComparable &Comparable) override;

private:
    std::string value;


};


#endif //OOVSTEMPLATES_STRINGWRAPPER_H
