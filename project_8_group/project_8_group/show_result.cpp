#include <iostream>
#include "show_result.h"

using namespace std;

//функция вывода результатного вектора
void show_result(vector<char>& number) {
    int counter_equality = 0;
    for (int i = number.size() - 1; i >= 0; i--) {         //непонятная часть, которая работает
        if (number[i] == 0 || number[i] == 'm') {
            counter_equality += 1;
            if (counter_equality == number.size()) {
                cout << "0";
                return;
            }
        }
    }
    int condition_of_null = 0;
    for (int i = number.size() - 1; i >= 0; i--) {                       //в обратном порядке  
        if (number[i] == 'm' && counter_equality != number.size()) {     //тут вообще забыл как работает, но работает
            cout << "-";
        }
        else if (number[i] == 0 && condition_of_null == 0) {
            if (i == 0) {
                cout << 0;
            }
            else {
                cout << "";
            }
        }
        else {
            if (number[i] == 0 or number[i] == '0' or number[i] == 'n') {
                cout << 0;
            }
            if (number[i] == 1 or number[i] == '1') {
                cout << 1;
            }
            if (number[i] == 2 or number[i] == '2') {
                cout << 2;
            }
            if (number[i] == 3 or number[i] == '3') {
                cout << 3;
            }
            if (number[i] == 4 or number[i] == '4') {
                cout << 4;
            }
            if (number[i] == 5 or number[i] == '5') {
                cout << 5;
            }
            if (number[i] == 6 or number[i] == '6') {
                cout << 6;
            }
            if (number[i] == 7 or number[i] == '7') {
                cout << 7;
            }
            if (number[i] == 8 or number[i] == '8') {
                cout << 8;
            }
            if (number[i] == 9 or number[i] == '9') {
                cout << 9;
            }
            if (number[i] == 'e') {
                cout << "error(на ноль делить нельзя)";
            }
            condition_of_null = 1;
        }
    }
}