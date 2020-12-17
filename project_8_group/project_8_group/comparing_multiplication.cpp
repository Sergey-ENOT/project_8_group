#include "comparing_multiplication.h"
#include "TTI.h"

int comparing_multiplication(vector<char>& num1, vector<char>& num2) {
    int number1, number2;
    int flag = 0;
    int counter_null_num1 = 0;
    int counter_null_num2 = 0;
    for (int i = 0; i < num1.size(); i++) {
        number1 = translate_to_int(num1[i]);
        if (num1[i] == '0') {
            counter_null_num1 += 1;
        }
    }
    for (int i = 0; i < num2.size(); i++) {
        number2 = translate_to_int(num2[i]);
        if (num2[i] == '0') {
            counter_null_num2 += 1;
        }
    }
    if (counter_null_num1 == num1.size() || counter_null_num2 == num2.size()) {
        flag = 1;
    }
    else if (num1.size() > num2.size()) {
        flag = 2;
    }
    else if (num1.size() < num2.size()) {
        vector<char> changer;
        changer = num2;
        num2 = num1;
        num1 = changer;
        flag = 2;
    }
    else if (num1.size() == num2.size()) {
        flag = 2;
    }
    return flag;
}