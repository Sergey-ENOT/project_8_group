// project_8_group.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include "GetOperand.h"
#include "GetNumber1.h"
#include "GetNumber2.h"
#include "comparing.h"
#include "addition.h"
#include "subtraction.h"
#include "multiplication.h"
#include "integer_division.h"
#include "remainder_division.h"
#include "show_result.h"
//#include <cmath> (пока не нужен)

using namespace std;

int main()
{
    setlocale(0, "");
    cout << "Вы используете калькулятор больших чисел" << endl;
    cout << "Вам доступны следующие операции: \n1.Сложение[+]\n2.Вычитание[-]\n3.Умножение[*]\n4.Целочисленное деление[/]\n5.Остаток от деления[%]" << endl;
    while (true) {
        vector<char> num1a;
        vector<char> num2a;
        vector<char> result;
        char operand;
        char symbol_1 = '+';
        char symbol_2 = '+';
        cout << "\n";
        getNumber1(num1a, symbol_1);
        getOperand(operand);
        cout << "\n";
        getNumber2(num2a, symbol_2);
        switch (operand) {
        case '+':
            if (symbol_1 == '+' && symbol_2 == '+') {
                addition(num1a, num2a, result);
            }
            else if (symbol_1 == '+' && symbol_2 == '-') {
                subtraction(num1a, num2a, result);
            }
            else if (symbol_1 == '-' && symbol_2 == '-') {
                addition(num1a, num2a, result);
                result.push_back('m');
            }
            else if (symbol_1 == '-' && symbol_2 == '+') {
                int flag = comparing(num1a, num2a);
                if (flag == 1) {
                    subtraction(num1a, num2a, result);
                    result.push_back('m');
                }
                else if (flag == 2) {
                    subtraction(num2a, num1a, result);
                }
                else if (flag == 3) {
                    result = { 0 };
                }
            }
            break;
        case '-':
            if (symbol_1 == '+' && symbol_2 == '+') {
                subtraction(num1a, num2a, result);
            }
            else if (symbol_1 == '-' && symbol_2 == '-') {
                int flag = comparing(num1a, num2a);
                if (flag == 1) {
                    subtraction(num1a, num2a, result);
                    result.push_back('m');
                }
                else if (flag == 2) {
                    subtraction(num2a, num1a, result);
                }
                else if (flag == 3) {
                    result = { 0 };
                }
            }
            else if (symbol_1 == '+' && symbol_2 == '-') {
                addition(num1a, num2a, result);
            }
            else if (symbol_1 == '-' && symbol_2 == '+') {
                addition(num1a, num2a, result);
                result.push_back('m');
            }
            break;
        case '*':
            if ((symbol_1 == '-' && symbol_2 == '-') || (symbol_1 == '+' && symbol_2 == '+')) {
                multiplication(num1a, num2a, result);
            }
            else {
                multiplication(num1a, num2a, result);
                result.push_back('m');
            }
            break;
        case '/':
            if ((symbol_1 == '-' && symbol_2 == '-') || (symbol_1 == '+' && symbol_2 == '+')) {
                integer_division(num1a, num2a, result);
            }
            else {
                integer_division(num1a, num2a, result);
                result.push_back('m');
            }
            break;
        case '%':
            if ((symbol_1 == '-' && symbol_2 == '-') || (symbol_1 == '+' && symbol_2 == '+')) {
                remainder_division(num1a, num2a, result);
            }
            else {
                remainder_division(num1a, num2a, result);
                result.push_back('m');
            }
        }
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
