//
// Created by Will on 3/29/2022.
//

#ifndef OOVSTEMPLATES_STRINGWRAPPER_H
#define OOVSTEMPLATES_STRINGWRAPPER_H
#include <string>

class StringWrapper {
public:

    StringWrapper(const std::string &stringValue);

    const std::string &getValue() const;

    void setValue(const std::string &stringValue);

    bool operator<(const StringWrapper& rhs) const;

private:
    std::string value;
};


#endif //OOVSTEMPLATES_STRINGWRAPPER_H
