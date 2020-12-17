#include "multiplication.h"
#include "comparing_multiplication.h"
#include "addition.h"
#include "subtraction.h"

using namespace std;

void multiplication(vector<char>& num1, vector<char>& num2, vector<char>& result) {
    int flag = comparing_multiplication(num1, num2);     //обязательно переделать на умножение со смещением  
    if (flag == 1) {                                     //т.к. 643 миллиона итераций это 22+ минуты ожидания(дальше я не стал ждать)
        result.push_back('n');
    }
    else if (flag == 2) {
        int counter_null = 0;
        vector<char> pre_result;
        vector<char> subtrahend = { 1 };
        bool flagok = true;
        do {
            addition(num1, pre_result, result);
            pre_result = result;
            result.clear();
            subtraction(num2, subtrahend, result);
            num2 = result;
            result.clear();
            counter_null = 0;
            for (int i = 0; i < num2.size(); i++) {
                if (num2[i] == 'n' || num2[i] == '0') {
                    counter_null += 1;
                }
            }
            if (counter_null == num2.size()) {
                result = pre_result;
                flagok = false;
            }
        } while (flagok);
    }
}