#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <locale.h>

using namespace std;
bool isNumber(const string& str) {
    for (char c : str) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}
bool equal(vector <long int> a, vector <long int> b) {
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}
void difference(vector <long int> x, vector <long int> y, vector <long int>& z, int part)
{
    for (int i = 0; i < part; i++) // проход по всем разр€дам числа, начина€ с последнего
    {
        z[i] = x[i] - y[i];
        if (z[i] < 0)
        {
            z[i] += 1000000000;
            if (i + 1 != part) x[i + 1]--;//занимаем разр€д
            else return;
        }

    }
}

bool isGreater(vector <long int> a, vector <long int> b) {
    for (int i = 0; i < a.size(); i++) // поразр€дное сравнение весов чисел
    {
        if (a[i] > b[i]) // если разр€д первого числа больше
        {
            return true;
        }
        if (b[i] > a[i]) // если разр€д второго числа больше
        {
            return false;
        }
    }
    return false;
}
// функци€ разделени€ строки на подстроки по 9 цифр и занесение их 
// в массив в виде чисел (с конца)
void longGcd(vector <long int>& a, vector <long int> b) {
    int part = a.size();
    bool flag = true;
    vector <long int> d(part, 0);
    for (long int x : b) {
        if (x != 0) {
            flag = false;
            break;
        }
    }
    if (flag) a = b;
    while (!equal(a, b)) {
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
    // i -позици€ первого символа в подстроке
    int k = 1, i = len - 9, j = 0;
    while (k <= part)
    {
        // выдел€ем подстроку из 9 цифр, двига€сь с конца
        // если последн€€ подстрока содержит меньше 9 символов,то
        // берем с 0-го символа все оставшиес€
        sub = i >= 0 ? s.substr(i, 9) : s.substr(0, 9 + i);
        a[j] = atol(sub.c_str()); // преобразование в число
        j++; k++;
        i -= 9;
    }
}

// функци€ преобразовани€ числа в строку с добавлением нулей
// до 9 разр€дов
string to_str(long int m)
{
    string s = to_string(m);
    s.insert(0, 9 - s.length(), '0');
    return s;
}