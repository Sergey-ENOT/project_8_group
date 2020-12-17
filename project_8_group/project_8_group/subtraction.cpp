#include "subtraction.h"
#include "comparing.h"
#include "TTI.h"

using namespace std;

void subtraction(vector<char>& num1, vector<char>& num2, vector<char>& result) {
    int number1, number2, iterator;
    int reducer = 0;
    int difference;
    int flag = comparing(num1, num2);
    if (flag == 1) {
        for (int i = 0; i < num1.size(); i++) {
            number1 = translate_to_int(num1[i]);
            number2 = translate_to_int(num2[i]);
            if (number1 - number2 - reducer >= 0) {            //��� ������������� ��� 0 �������� - ������ �������� ��������
                difference = number1 - number2 - reducer;
                reducer = 0;
                result.push_back(difference);
            }
            else if (number1 - number2 - reducer < 0) {         //��� ������������� �������� �������� ������� � ������������ 10
                difference = number1 + 10 - number2 - reducer;  //� 
                reducer = 1;                                    //������� � ���������� reducer ����� ��� ���������� ���������� �������
                result.push_back(difference);
            }
        }
    }
    if (flag == 2) {                                            //��� � ��������� flag = 1, �� ��������������� �������
        for (int i = 0; i < num2.size(); i++) {
            number1 = translate_to_int(num1[i]);
            number2 = translate_to_int(num2[i]);
            if (number2 - number1 - reducer >= 0) {
                difference = number2 - number1 - reducer;
                reducer = 0;
                result.push_back(difference);
            }
            else if (number2 - number1 - reducer < 0) {
                difference = number2 + 10 - number1 - reducer;
                reducer = 1;
                result.push_back(difference);
            }
        }
        result.push_back('m');
    }
    if (flag == 3) {
        result.push_back('n');
    }
}