#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <locale.h>

using namespace std;
bool isNumber(const string& str) {//проверяет является ли строка числом
    for (char c : str) {
        if (!isdigit(c)) { // используем isdigit для каждого символа
            return false;
        }
    }
    return true;
}
bool equal(vector <long int> a, vector <long int> b) {// проверяет равны ли два вектора
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}
void difference(vector <long int> x, vector <long int> y, vector <long int>& z, int part)
{
    for (int i = 0; i < part; i++) // проход по всем разрядам числа, начиная с последнего
    {
        z[i] = x[i] - y[i];
        if (z[i] < 0) // если разность меньше нуля, то занимаем
        {
            z[i] += 1000000000;// добавляем занятый разряд
            if (i + 1 != part) x[i + 1]--;//занимаем разряд
            else return;
        }

    }
}

bool isGreater(vector <long int> a, vector <long int> b) {
    for (int i = 0; i < a.size(); i++) // поразрядное сравнение весов чисел
    {
        if (a[i] > b[i]) // если разряд первого числа больше
        {
            return true;
        }
        if (b[i] > a[i]) // если разряд второго числа больше
        {
            return false;
        }
    }
    return false;
}
// функция разделения строки на подстроки по 9 цифр и занесение их 
// в массив в виде чисел (с конца)
void longGcd(vector <long int>& a, vector <long int> b) { // функция вичисляет НОД, записан в векторе a
    int part = a.size(); // колличество частей в векторе
    bool flag = true;
    vector <long int> d(part, 0); // вспомогательный вектор
    for (long int x : b) { // проверка является ли b нулевым, иначе цикл будет бесконечным
        if (x != 0) {
            flag = false;
            break;// если да, выходим из цикла
        }
    }
    if (flag) a = b; //зануляем a, потому что НОД любого числа с нулём это 0
    while (!equal(a, b)) {// алгоритм Евклида, функция equal проверяет равны ли a и b, и пока они не равны, выполняем алгоритм
        if (isGreater(a, b)) {
            difference(a, b, d, part);
            a = d;
        }
        else {
            difference(b, a, d, part);
            b = d;
        }
    }
}
void massiv(vector <long int>& a, string s, int len, int part)
{
    string sub;
    // j - номер элемента в массиве, k - номер подстроки, 
    // i -позиция первого символа в подстроке
    int k = 1, i = len - 9, j = 0;
    while (k <= part)
    {
        // выделяем подстроку из 9 цифр, двигаясь с конца
        // если последняя подстрока содержит меньше 9 символов,то
        // берем с 0-го символа все оставшиеся
        sub = i >= 0 ? s.substr(i, 9) : s.substr(0, 9 + i);
        a[j] = atol(sub.c_str()); // преобразование в число
        j++; k++;
        i -= 9;
    }
}

// функция преобразования числа в строку с добавлением нулей
// до 9 разрядов
string to_str(long int m)
{
    string s = to_string(m);
    s.insert(0, 9 - s.length(), '0');
    return s;
}