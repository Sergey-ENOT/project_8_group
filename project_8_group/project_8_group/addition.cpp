#include <iostream>
#include "addition.h"
#include "comparing.h"
#include "TTI.h"
#include "show_result.h"

void addition(vector<char>& num1, vector<char>& num2, vector<char>& result) {
    int number1, number2, iterator;
    int flag = comparing(num1, num2);
    if (flag != 0) {
        iterator = 0;
        for (int i = 0; i < num1.size(); i++) {
            number1 = translate_to_int(num1[i]);
            number2 = translate_to_int(num2[i]);
            cout << "number1: " << number1 << endl;
            cout << "number2: " << number2 << endl;
            if (number1 + number2 + iterator < 10) {              //���� ����� ������ 10, �� ������ ��� � result �����
                int summ = number1 + number2 + iterator;
                cout << "summ...: " << summ << endl;
                iterator = 0;
                result.push_back(summ);
            }
            else if (number1 + number2 + iterator >= 10) {      //���� ����� >= 10, �� ��� �������� �� ��������� 10
                if (i == num1.size() - 1) {
                    int summ = number1 + number2 + iterator;
                    iterator = 1;                                 // � ������ ���������� ���������� ������� � iterator
                    result.push_back(summ - 10);
                    result.push_back(iterator);
                    cout << "summ/: " << summ << endl;
                    cout << "iterator: " << iterator << endl;
                }
                else {
                    int summ = number1 + number2 + iterator;
                    iterator = 1;
                    result.push_back(summ - 10);
                }
            }
        }
    }
}