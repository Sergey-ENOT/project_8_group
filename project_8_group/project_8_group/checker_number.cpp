#include "checker_number.h"
#include <iostream>

std::vector<char> checker_number(std::string num_str, char& symbol, std::vector<char>& number) {
    for (int i = num_str.length() - 1; i >= 0; i--) {
        if (num_str[i] == '0' || num_str[i] == '1' || num_str[i] == '2' ||
            num_str[i] == '3' || num_str[i] == '4' || num_str[i] == '5' ||
            num_str[i] == '6' || num_str[i] == '7' || num_str[i] == '8' ||
            num_str[i] == '9') {
            number.push_back(num_str[i]);
        }
        else {
            if (i == 0) {
                if (num_str[i] == '-') {
                    symbol = '-';
                }
                else if (num_str[i] == '+') {
                    symbol = '+';
                }
            }
            else {
                std::cout << "SyntaxError: invalid syntax";
                exit(0);
            }
        }
    }
    return number;
}