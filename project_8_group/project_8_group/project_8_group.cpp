// project_8_group.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<char> getNumber(vector<char> &number) {
    //todo реализовать возможность введения отрицательных чисел.
    std::cout << "Введите число: ";
    string Number;
    cin >> Number;
    /*std::cin.getline(Number, 255);
    while (std::cin.fail()) {
        std::cout << "Введите правильное число" << std::endl;
        std::cin.clear();
        std::cin.ignore(32767, '\n');
        std::cin.getline(number, 255);
    }*/
    for (int i = Number.length() - 1; i >= 0; i--) {
        number.push_back(int(Number[i]));
    }
    /*for (int i = 0; i < number.size(); i++) {
        cout << number[i] << " ";
    }*/
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
            if (number1 + number2 + iterator < 10) {
                int summ = number1 + number2 + iterator;
                iterator = 0;
                result.push_back(summ);
            } else if (number1 + number2 + iterator >= 10) {
                if (i == num1.size() - 1) {
                    int summ = number1 + number2 + iterator;
                    iterator = 1;
                    result.push_back(summ - 10);
                    result.push_back(iterator);
                }
                int summ = number1 + number2 + iterator;
                iterator = 1;
                result.push_back(summ - 10);
            }
        }

        for (int i = result.size() - 1; i >= 0; i--) {   //в обратном порядке
            switch (result[i]) {
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
        }

        //когда первое число меньше второго получение цифр 1 9 (пример 80 + 1980)
        //if (i < 0 && j >= 0) {
        //    number1 = 0;
        //    number2 = translate_to_int(num2[j]);

        //    if (result[j + 1] == ' ') {
        //        result[j + 1] = number2;
        //    }
        //    else {
        //        if (result[j + 1] + number2 >= 10) {
        //            result[j + 1] = (result[j + 1] + number2) % 10;
        //            if (result[j] == ' ') {
        //                result[j] = 1;
        //            }
        //            else {
        //                result[j] += 1;
        //            }
        //        }
        //        else {
        //            result[j + 1] += number2;
        //        }

        //    }
        //}
        ////когда второе число меньше первого получение цифр 1 9 (пример 1982 + 80)
        //else if (j < 0 && i >= 0) {
        //    number1 = translate_to_int(num1[i]);
        //    number2 = 0;
        //    if (result[i + 1] == ' ') {
        //        result[i + 1] = number1;
        //    }
        //    else {
        //        if (result[i + 1] + number1 >= 10) {
        //            result[i + 1] = (result[i + 1] + number1) % 10;
        //            if (result[i] == ' ') {
        //                result[i] = 1;
        //            }
        //            else {
        //                result[i] += 1;
        //            }
        //        }
        //        else {
        //            result[i + 1] += number1;
        //        }

        //    }
        //}
        ////еще не известно самое большое число
        //else {
        //    number1 = translate_to_int(num1[i]);
        //    number2 = translate_to_int(num2[j]);
        //    //iterator - служит для внесения результта в массив по правильным индексам начиная с эмента под индексом j или i + 1 (так как резульат суммы 2 чисел в худшем случае увеличиться на 1)
        //    if (i > j) {
        //        iterator = i;
        //    }
        //    else {
        //        iterator = j;
        //    }
        //    if (number1 + number2 >= 10) {
        //        if (result[iterator + 1] == ' ') {
        //            result[iterator + 1] = (number1 + number2) % 10;
        //        }
        //        else {
        //            result[iterator + 1] += (number1 + number2) % 10;
        //        }
        //        //перенос 1 влево, если там нет ничего то присвоить 1 если что-то уже лежит прибавить
        //        if (result[iterator] == ' ') {
        //            result[iterator] = 1;
        //        }
        //        else {
        //            result[iterator] += 1;
        //        }
        //    }
        //    else {
        //        if (result[iterator + 1] == ' ') {
        //            result[iterator + 1] = number1 + number2;
        //        }
        //        else {
        //            result[iterator + 1] += number1 + number2;
        //        }
        //    }
        //}
    }
}

int main()
{
    setlocale(0, "");
    vector<char> num1a;
    vector<char> num2a;
    vector<char> result;
    /*while (true) {
        getNumber(num1a);
        getNumber(num2a);
        calc(num1a, getOperand(), num2a, result);
        show_result(result);
    }*/
    getNumber(num1a);
    getNumber(num2a);
    calc(num1a, getOperand(), num2a, result);
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
