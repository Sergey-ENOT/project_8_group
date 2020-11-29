﻿// project_8_group.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

vector<char> getNumber(vector<char> &number) {
    //todo добавить считывание минуса и плюса в начале числа.
    //todo реализовать возможность введения отрицательных чисел.
    bool condition = true;
    while (condition) {
        std::cout << "Введите число: ";
        string Number;
        getline(cin, Number);
        for (int i = Number.length() - 1; i >= 0; i--) {
            //if (i == 0 && Number[i] = '-')
            if (Number[i] == '0' || Number[i] == '1' || Number[i] == '2' || Number[i] == '3' ||
                Number[i] == '4' || Number[i] == '5' || Number[i] == '6' || Number[i] == '7' ||
                Number[i] == '8' || Number[i] == '9') {
                number.push_back(Number[i]);
                if (i == 0) {
                    condition = false;
                }
            }
            else {
                cout << "Вы ввели неправильное число" << endl;               
                number.clear();
                break;
            }
        }
    }
    cout << "\n";
    return number;
}

char getOperand() {
    char operand;
    while (true) {
        std::cout << "Введите операцию: ";
        std::cin >> operand;
        std::cin.ignore(32767, '\n');
        if (operand == '+' || operand == '/' || operand == '-' || operand == '*' || operand == '**' || operand == '!') {
            return operand;
        }
        std::cout << "Введите правильный знак операции" << std::endl;
    }
    return operand;
}

int translate_to_int(char a) {
    if (a == '0') {
        return 0;
    }
    if (a == '1') {
        return 1;
    }
    if (a == '2') {
        return 2;
    }
    if (a == '3') {
        return 3;
    }
    if (a == '4') {
        return 4;
    }
    if (a == '5') {
        return 5;
    }
    if (a == '6') {
        return 6;
    }
    if (a == '7') {
        return 7;
    }
    if (a == '8') {
        return 8;
    }
    if (a == '9') {
        return 9;
    }
    return 0;
}

//функция вывода результатного вектора
void show_result(vector<char>& number) {
    int condition_of_null = 0;
    for (int i = number.size() - 1; i >= 0; i--) {   //в обратном порядке  
        if (number[i] == 0 && condition_of_null == 0) {
            cout << "";           
        }
        else {
            switch (number[i]) {
            case 0:
                cout << 0;
                break;
            case 1:
                cout << 1;
                break;
            case 2:
                cout << 2;
                break;
            case 3:
                cout << 3;
                break;
            case 4:
                cout << 4;
                break;
            case 5:
                cout << 5;
                break;
            case 6:
                cout << 6;
                break;
            case 7:
                cout << 7;
                break;
            case 8:
                cout << 8;
                break;
            case 9:
                cout << 9;
                break;
            }     
            condition_of_null = 1;
        }
    }
}

void calc(vector<char>& num1, char op, vector<char>& num2, vector<char>& result) {
    int number1, number2, iterator;
    if (op == '+') {
        int length_num1 = num1.size();
        int length_num2 = num2.size();
        if (length_num1 > length_num2) {                            //если первое больше второго, то вставка во второй
            for (int i = 0; i < length_num1 - length_num2; i++) {   //вектор нулей до выравнивания
                num2.push_back(0);
            }
        }
        else if (length_num1 < length_num2) {                     //если второй больше, то вставка в первый вектор
            for (int i = 0; i < length_num2 - length_num1; i++) { //нулей до выравнивания                   
                num1.push_back(0);
            }
        }

        iterator = 0;
        for (int i = 0; i < num1.size(); i++) {
            number1 = translate_to_int(num1[i]);
            number2 = translate_to_int(num2[i]);
            if (number1 + number2 + iterator < 10) {              //если сумма меньше 10, то просто пуш в result числа
                int summ = number1 + number2 + iterator;
                iterator = 0;
                result.push_back(summ);
            }
            else if (number1 + number2 + iterator >= 10) {      //если сумма >= 10, то пуш отстатка от вычитания 10
                if (i == num1.size() - 1) {
                    int summ = number1 + number2 + iterator;
                    iterator = 1;                                 // и запись увеличения следующего разряда в iterator
                    result.push_back(summ - 10);
                    result.push_back(iterator);
                }
                else {
                    int summ = number1 + number2 + iterator;
                    iterator = 1;
                    result.push_back(summ - 10);
                }
            }
        }
    } 
    if (op == '-') {
        int length_num1 = num1.size();
        int length_num2 = num2.size();
        int flag = 0;

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
                    //num1<num2
                    flag = 2;
                    break;
                }
            }
        }

        int reducer = 0;
        int difference;
        if (flag == 1) {
            for (int i = 0; i < length_num1; i++) {
                number1 = translate_to_int(num1[i]);
                number2 = translate_to_int(num2[i]);
                if (number1 - number2 - reducer >= 0) {            //при положительной или 0 разности - просто запушить разность
                    difference = number1 - number2 - reducer;
                    reducer = 0;
                    result.push_back(difference);
                }
                else if (number1 - number2 - reducer < 0) {         //при отрицательной разности запушить разницу с прибавлением 10
                    difference = number1 + 10 - number2 - reducer;  //и 
                    reducer = 1;                                    //занести в переменную число для уменьшения следующего разряда
                    result.push_back(difference);
                }
            }
        } 
        if (flag == 2) {                                            //как в алгоритме flag = 1, но противоположные векторы
            for (int i = 0; i < length_num2; i++) {
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
        }
        /*else if (length_num1 = length_num2) {

        }*/
    }
}

int main()
{
    setlocale(0, "");
    while (true) {
        vector<char> num1a;
        vector<char> num2a;
        vector<char> result;
        getNumber(num1a);
        getNumber(num2a);
        calc(num1a, getOperand(), num2a, result);
        cout << "\nРезультат операции: ";
        show_result(result);
        cout << "\n";
        cout << "\n";
        cout << "\n";
    }
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
