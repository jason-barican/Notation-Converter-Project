//Jason Barican U18728557
//Samuel Sau U44954874

#ifndef NOTATIONCONVERTER_H
#define NOTATIONCONVERTER_H

#include <string>
#include <iostream>
#include "NotationDeque.hpp"
#include "NotationConverterInterface.hpp"

using namespace std;

class NotationConverter : public NotationConverterInterface {
public:

    std::string postfixToInfix(std::string inStr);
    std::string postfixToPrefix(std::string inStr);

    std::string infixToPostfix(std::string inStr);
    std::string infixToPrefix(std::string inStr);

    std::string prefixToInfix(std::string inStr);
    std::string prefixToPostfix(std::string inStr);

private:
    NotationDeque MainDeque;                        //deque to store/format main equation conversion
    NotationDeque TempDeque;                        //temp deque for storing operands
    NotationDeque TempDeque2;                       //temp deque for storing operators       
};

#endif


