#include "remainder_division.h"
#include "subtraction.h"
#include "comparing_division.h"

using namespace std;

void remainder_division(vector<char>& num1, vector<char>& num2, vector<char>& result) {
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
        bool flagok = true;
        do {
            subtraction(num1, num2, result);
            num1 = result;
            result.clear();
            flag = comparing_division(num1, num2);       //������������ ��������� ��������
            if (flag == 1) {
                result = { 0 };
                flagok = false;
            }
            else if (flag == 4) {
                result = num1;
                flagok = false;
            }
            else if (flag == 5) {
                result = { 0 };
                flagok = false;
            }
        } while (flagok);
        //��������� � ����� while , ���� �� ����� �� num1 < num2
    }
    else if (flag == 4) {
        result = num1;
        return;
    }
    else if (flag == 5) {
        result.push_back(0);
        return;
    }
}
