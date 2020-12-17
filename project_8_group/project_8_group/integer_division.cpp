#include "integer_division.h"
#include "comparing_division.h"
#include "addition.h"
#include "subtraction.h"

using namespace std;

void integer_division(vector<char>& num1, vector<char>& num2, vector<char>& result) {
    int flag = comparing_division(num1, num2);
    if (flag == 1) {                  //����� ������� ����� 0
        result.push_back(0);
        return;
    }
    else if (flag == 2) {             //����� �������� ����� 0
        result.push_back('e');        //'e' = error
        return;
    }
    else if (flag == 3) {
        vector<char> summand = { 1 };
        vector<char> counter_iteration = { 0 };
        bool flagok = true;
        do {
            addition(counter_iteration, summand, result);     // ���� ��������
            counter_iteration = result;                      // ��������
            result.clear();
            subtraction(num1, num2, result);
            num1 = result;
            result.clear();
            flag = comparing_division(num1, num2);       //������������ ��������� ��������
            if (flag == 1) {
                result = counter_iteration;
                flagok = false;
            }
            else if (flag == 4) {
                result = counter_iteration;
                flagok = false;
            }
            else if (flag == 5) {
                addition(counter_iteration, summand, result);
                flagok = false;
            }
        } while (flagok);
        //��������� � ����� while , ���� ����������� ������ ����������� � ���������� ������� ��������
    }
    else if (flag == 4) {
        result.push_back(0);
        return;
    }
    else if (flag == 5) {
        result.push_back(1);
        return;
    }
}