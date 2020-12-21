// project_8_group.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <string>
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
#include "condition_symbols.h"
#include "TTI.h"
#include "condition_symbols_console.h"
#include "checker_number.h"
#include "check_operand.h"
//#include <cmath> (пока не нужен)

using namespace std;

void main(int argc, char* argv[])        //сделать считывание по каждому аргументу(3 получается на ввод) 
{
    setlocale(0, "");
    if (argc > 1) {
        if (argc == 3) {
            cout << "SyntaxError: invalid syntax";
            exit(0);
        }
        else if (argc == 2) {
            cout << argv[1];
        }
        else if (argc >= 5) {
            cout << "SyntaxError: invalid syntax";
        }
        else {
            char operand;
            char symbol_1 = '+';
            char symbol_2 = '+';
            string num1a_str;
            string num2a_str;
            vector<char> num1a;
            vector<char> num2a;
            vector<char> result;
            for (int i = 1; i < argc; i++) {
                if (i == 1) {
                    num1a_str = argv[i];
                }
                else if (i == 2) {
                    operand = *(argv[i]);
                }
                else if (i == 3) {
                    num2a_str = argv[i];
                }
            }
            checker_number(num1a_str, symbol_1, num1a);
            check_operand(operand);
            checker_number(num2a_str, symbol_2, num2a);
            condition_symbols_console(num1a, num2a, result, symbol_1, symbol_2, operand);
            exit(0);
        }
    }
    else {
        cout << "Вы используете калькулятор больших чисел" << endl;
        cout << "Вам доступны следующие операции: \n1.Сложение[+]\n2.Вычитание[-]\n3.Умножение[*]\n4.Целочисленное деление[/]\n5.Остаток от деления[%]" << endl;
        while (true) {
            vector<char> num1a;
            vector<char> num2a;
            vector<char> result;
            condition_symbols(num1a, num2a, result);
            cout << "\n";
            cout << "\n";
            cout << "\n";
        }
    }
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
