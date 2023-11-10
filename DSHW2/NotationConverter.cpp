//Jason Barican U18728557
//Samuel Sau U44954874

#include <algorithm>
#include <iostream>

#include "NotationDeque.cpp"
#include "NotationConverterInterface.hpp"
#include "NotationConverter.hpp"

std::string NotationConverter::postfixToInfix(std::string inStr) {

    if (!isalpha(inStr[0]))                 //checks if first element is a letter. if not, then it is not a valid postfix notation
        throw inStr;

    int operatorcount = 0, operandcount = 0;

    for (unsigned int i = 0; i < inStr.size(); i++) {
        if (inStr[i] != ' ') {
            if (isalpha(inStr[i])) {

                MainDeque.insertBack(inStr[i]);
                operandcount++;

            } else if (inStr[i] == '+' || inStr[i] == '-' || inStr[i] == '*' || inStr[i] == '/') { 

                TempDeque.insertFront(MainDeque.back());                                
                MainDeque.removeBack();

                TempDeque.insertFront(MainDeque.back());
                MainDeque.removeBack();

                MainDeque.insertBack('(' + TempDeque.front() + ' ' + inStr[i] +         //appends equation back into maindeque
                                     ' ' + TempDeque.back() + ')');

                TempDeque.removeBack();
                TempDeque.removeBack();

                operatorcount++;
            }
        }
    }
    
    checkCount(operandcount, operandcount, inStr);

    string outputstr; //if count of operator and operand is valid
    outputstr = MainDeque.front();
    MainDeque.removeFront();
    return outputstr; 
}

std::string NotationConverter::prefixToInfix(std::string inStr) {

    reverse(inStr.begin(), inStr.end());             //reverses string to help with storing prefix in deque

    if (!isalpha(inStr[0]))                          //if last element (or first element reversed) is not a letter, then not a valid prefix
        throw inStr;

    int operatorcount = 0, operandcount = 0;
    
    for (unsigned int i = 0; i < inStr.size(); i++) {
        if (inStr[i] != ' ') {                       //ignoring whitespace
            if (isalpha(inStr[i])) {                 //if element is a letter, stores it in maindeque
                
                MainDeque.insertBack(inStr[i]);      
                operandcount++;                      //increments operandcount

            } else if (inStr[i] == '+' || inStr[i] == '-' || inStr[i] == '*' || inStr[i] == '/') {      //formats first equation once it detects an operation
                
                TempDeque.insertBack(MainDeque.back());                                                 //adds maindeque elements to tempdeque for easier formatting
                MainDeque.removeBack();

                TempDeque.insertBack(MainDeque.back());
                MainDeque.removeBack();

                MainDeque.insertBack('(' + TempDeque.front() + ' ' + inStr[i] +                         //inserts equation (with whitespaces and groupings) to the back of the maindeque
                                     ' ' + TempDeque.back() + ')');                 

                TempDeque.removeBack();
                TempDeque.removeBack();             //empties tempdeque

                operatorcount++;                    //increments operatorcount
            }    
        }
    }

    checkCount(operandcount, operandcount, inStr);

    string outputstr;                           
    outputstr = MainDeque.front();              //stores infix equation in maindeque into string
    MainDeque.removeFront();
    return outputstr;
    
}

std::string NotationConverter::infixToPostfix(std::string inStr) {
    
    if (inStr[0] != '(')                        //if first element not equal to open parentheses, then not valid infix
        throw inStr;
    
    int operatorcount = 0, operandcount = 0;
    
    for (unsigned int i = 0; i < inStr.size(); i++) {
        if (inStr[i] != '(' || inStr[i] != ' ') {           //ignores whitespace and open parentheses
            if (inStr[i] == '+' || inStr[i] == '-' || inStr[i] == '*' || inStr[i] == '/') {

                TempDeque2.insertBack(inStr[i]);   //stores operators in temporary deque
                operatorcount++;
            
            } else if (isalpha(inStr[i])) {
                
                MainDeque.insertBack(inStr[i]);
                operandcount++;
           
            } else if (inStr[i] == ')') {

                MainDeque.insertBack(TempDeque2.back());
                TempDeque2.removeBack();
                
            }
        }
    }

    if (operandcount - 1 != operatorcount)          //checks if there is valid amount of operator to operand
        throw inStr;
    
    else {
        string outputstr;
        while (!MainDeque.empty()) {                //formats equation with whitespaces into outputstr, then returns
            outputstr += MainDeque.front();
            MainDeque.removeFront();
            if (!MainDeque.empty()) 
                outputstr += ' ';
                
            
        } return outputstr;  
    } 
}

std::string NotationConverter::infixToPrefix(std::string inStr) {
    
    if (inStr[0] != '(')                            //if first element not equal to open parentheses, then not valid infix
        throw inStr;
    
    reverse(inStr.begin(), inStr.end());            //reverses string for easier prefix conversion

    int operatorcount = 0, operandcount = 0;

    for (unsigned int i = 0; i < inStr.size(); i++) {
        if (inStr[i] != ')' || inStr[i] != ' ') {   //ignores closing bracket and whitespace (closing instead of open because string is reversed)
            if (inStr[i] == '+' || inStr[i] == '-' || inStr[i] == '*' || inStr[i] == '/') {

                TempDeque2.insertFront(inStr[i]);   
                operatorcount++;

            } else if (isalpha(inStr[i])) {

                MainDeque.insertFront(inStr[i]);     
                operandcount++;

            } else if (inStr[i] == '(') {

                MainDeque.insertFront(TempDeque2.front());
                TempDeque2.removeFront();
            }
        }   
    }
    checkCount(operandcount, operandcount, inStr);
    
    string outputstr;
    while (!MainDeque.empty()) {
        outputstr += MainDeque.front();
        MainDeque.removeFront();
        if (!MainDeque.empty())
           outputstr += ' ';
    } return outputstr;
    

}

std::string NotationConverter::postfixToPrefix(std::string inStr) {
    return infixToPrefix(postfixToInfix(inStr));                    //calls two functions: postfixtoinfix then infixtoprefix to obtain postfixtoprefix
}

std::string NotationConverter::prefixToPostfix(std::string inStr) {
    return infixToPostfix(prefixToInfix(inStr));                    //calls two functions: prefixtoinfix then infixtopostfix to obtain postfixtoprefix
}

std::string checkCount(int operandcount, int operatorcount,std::string inStr){

    if (operandcount - 1 != operatorcount)          //checks if there is valid amount of operator to operand
        throw inStr;
}