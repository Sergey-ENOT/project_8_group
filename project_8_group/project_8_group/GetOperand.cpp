#include <iostream>
#include "GetOperand.h"

char getOperand(char& operand) {
    while (true) {
        std::cout << "¬ведите операцию: ";
        std::cin >> operand;
        std::cin.ignore(32767, '\n');
        if (operand == '+' || operand == '/' || operand == '-' || operand == '*' || operand == '**' || operand == '!' || operand == '%') {
            return operand;
        }
        std::cout << "¬ведите правильный знак операции" << std::endl;
    }
    return operand;
}