#include "comparing_division.h"
#include "TTI.h"

int comparing_division(vector<char>& num1, vector<char>& num2) {
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
    } if (num1.size() == counter_null_num1) {
        flag = 1;
    }
    else if (num2.size() == counter_null_num2) {
        flag = 2;
    }
    else if (num1.size() > num2.size()) {
        flag = 3;
    }
    else if (num1.size() < num2.size()) {
        flag = 4;
    }
    else {
        for (int i = num1.size() - 1; i >= 0; i--) {         //если равны по количеству символов
            number1 = translate_to_int(num1[i]);
            number2 = translate_to_int(num2[i]);
            if (number1 > number2) {                         //у первого числа быстрее встретилось большее - по алгоритму ->
                flag = 3;                                    // -> для num1 > num2
                break;
            }
            else if (number1 < number2) {                    //иначе - по алгоритму для num1 < num2
                flag = 4;
                break;
            }
            else if (number1 == number2) {
                if (i == 0) {
                    flag = 5;
                }
            }
        }
    }
    return flag;
}