#include "check_operand.h"
#include <iostream>

char check_operand(char operand) {
    setlocale(0, "");
    if (operand == '+' || operand == '/' || operand == '-' || operand == '*' || operand == '**' || operand == '!' || operand == '%') {
        return operand;
    }
    std::cout << "SyntaxError: invalid syntax";
    exit(0);
}