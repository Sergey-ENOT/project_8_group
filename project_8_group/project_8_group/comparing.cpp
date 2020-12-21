#include "comparing.h"
#include "TTI.h"

int comparing(vector<char>& num1, vector<char>& num2) {
    int number1, number2;
    int length_num1 = num1.size();
    int length_num2 = num2.size();
    int flag = 0;
    int counter_equality;
    if (length_num1 > length_num2) {                            //���� ������ ������ �������, �� ������� �� ������
        for (int i = 0; i < length_num1 - length_num2; i++) {   //������ ����� �� ������������
            num2.push_back('n');
            flag = 1;
        }
    }
    else if (length_num1 < length_num2) {                     //���� ������ ������, �� ������� � ������ ������
        for (int i = 0; i < length_num2 - length_num1; i++) { //����� �� ������������                   
            num1.push_back('n');
            flag = 2;
        }
    }
    else {
        for (int i = num1.size() - 1; i >= 0; i--) {         //���� ����� �� ���������� ��������
            number1 = translate_to_int(num1[i]);
            number2 = translate_to_int(num2[i]);
            if (number1 > number2) {                         //� ������� ����� ������� ����������� ������� - �� ��������� ->
                flag = 1;                                    // -> ��� num1 > num2
                break;
            }
            else if (number1 < number2) {                    //����� - �� ��������� ��� num1 < num2
                flag = 2;
                break;
            }
            else if (number1 == number2) {
                if (i == 0) {
                    flag = 3;
                }
            }
        }
    }
    return flag;
}