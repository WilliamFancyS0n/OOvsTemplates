//
// Created by Will on 3/29/2022.
//

#ifndef OOVSTEMPLATES_INTWRAPPER_H
#define OOVSTEMPLATES_INTWRAPPER_H


class IntWrapper {
public:

    IntWrapper(int intValue);

    int getValue() const;

    void setValue(int intValue);

    bool operator<(const IntWrapper& rhs) const;

private:
    int value;

};

#endif //OOVSTEMPLATES_INTWRAPPER_H
