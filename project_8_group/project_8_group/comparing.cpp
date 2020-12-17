#include "comparing.h"
#include "TTI.h"

int comparing(vector<char>& num1, vector<char>& num2) {
    int number1, number2;
    int length_num1 = num1.size();
    int length_num2 = num2.size();
    int flag = 0;
    int counter_equality;
    if (length_num1 > length_num2) {                            //если первое больше второго, то вставка во второй
        for (int i = 0; i < length_num1 - length_num2; i++) {   //вектор нулей до выравнивания
            num2.push_back(0);
            flag = 1;
        }
    }
    else if (length_num1 < length_num2) {                     //если второй больше, то вставка в первый вектор
        for (int i = 0; i < length_num2 - length_num1; i++) { //нулей до выравнивания                   
            num1.push_back(0);
            flag = 2;
        }
    }
    else {
        for (int i = num1.size() - 1; i >= 0; i--) {         //если равны по количеству символов
            number1 = translate_to_int(num1[i]);
            number2 = translate_to_int(num2[i]);
            if (number1 > number2) {                         //у первого числа быстрее встретилось большее - по алгоритму ->
                flag = 1;                                    // -> для num1 > num2
                break;
            }
            else if (number1 < number2) {                    //иначе - по алгоритму для num1 < num2
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