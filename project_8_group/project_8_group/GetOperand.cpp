#include <iostream>
#include "GetOperand.h"

char getOperand(char& operand) {
    while (true) {
        std::cout << "������� ��������: ";
        std::cin >> operand;
        std::cin.ignore(32767, '\n');
        if (operand == '+' || operand == '/' || operand == '-' || operand == '*' || operand == '**' || operand == '!' || operand == '%') {
            return operand;
        }
        std::cout << "������� ���������� ���� ��������" << std::endl;
    }
    return operand;
}