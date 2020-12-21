#include "condition_symbols_console.h"
#include "GetNumber1.h"
#include "GetNumber2.h"
#include <iostream>
#include "GetOperand.h"
#include "addition.h"
#include "subtraction.h"
#include "comparing.h"
#include "multiplication.h"
#include "integer_division.h"
#include "remainder_division.h"
#include "show_result.h"

void condition_symbols_console(vector<char> num1a, vector<char> num2a, vector<char>& result, char symbol_1, char symbol_2, char operand) {
    switch (operand) {
    case '+':
        if (symbol_1 == '+' && symbol_2 == '+') {
            addition(num1a, num2a, result);
        }
        else if (symbol_1 == '+' && symbol_2 == '-') {
            subtraction(num1a, num2a, result);
        }
        else if (symbol_1 == '-' && symbol_2 == '-') {
            addition(num1a, num2a, result);
            result.push_back('m');
        }
        else if (symbol_1 == '-' && symbol_2 == '+') {
            int flag = comparing(num1a, num2a);
            if (flag == 1) {
                subtraction(num1a, num2a, result);
                result.push_back('m');
            }
            else if (flag == 2) {
                subtraction(num2a, num1a, result);
            }
            else if (flag == 3) {
                result = { 0 };
            }
        }
        break;
    case '-':
        if (symbol_1 == '+' && symbol_2 == '+') {
            subtraction(num1a, num2a, result);
        }
        else if (symbol_1 == '-' && symbol_2 == '-') {
            int flag = comparing(num1a, num2a);
            if (flag == 1) {
                subtraction(num1a, num2a, result);
                result.push_back('m');
            }
            else if (flag == 2) {
                subtraction(num2a, num1a, result);
            }
            else if (flag == 3) {
                result = { 0 };
            }
        }
        else if (symbol_1 == '+' && symbol_2 == '-') {
            addition(num1a, num2a, result);
        }
        else if (symbol_1 == '-' && symbol_2 == '+') {
            addition(num1a, num2a, result);
            result.push_back('m');
        }
        break;
    case '*':
        if ((symbol_1 == '-' && symbol_2 == '-') || (symbol_1 == '+' && symbol_2 == '+')) {
            multiplication(num1a, num2a, result);
        }
        else {
            multiplication(num1a, num2a, result);
            result.push_back('m');
        }
        break;
    case '/':
        if ((symbol_1 == '-' && symbol_2 == '-') || (symbol_1 == '+' && symbol_2 == '+')) {
            integer_division(num1a, num2a, result);
        }
        else {
            integer_division(num1a, num2a, result);
            result.push_back('m');
        }
        break;
    case '%':
        if ((symbol_1 == '-' && symbol_2 == '-') || (symbol_1 == '+' && symbol_2 == '+')) {
            remainder_division(num1a, num2a, result);
        }
        else {
            remainder_division(num1a, num2a, result);
            result.push_back('m');
        }
    }
    std::cout << "Результат операции: ";
    show_result(result);
}