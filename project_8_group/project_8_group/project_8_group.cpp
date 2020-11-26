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
    for (int i = 0; i < Number.length(); i++) {
        number.push_back(Number[i]);
    }
    for (int i = 0; i < number.size(); i++) {
        cout << number[i] << " ";
    }
    return number;
}

int main()
{
    setlocale(0, "");
    vector<char> num1a;
    /*vector<char> num2a;
    vector<char> result;*/
    /*while (true) {
        getNumber(num1a);
        getNumber(num2a);
        calc(num1a, getOperand(), num2a, result);
        show_result(result);
    }*/
    getNumber(num1a);
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
