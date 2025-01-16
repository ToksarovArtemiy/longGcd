#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <locale.h>
#include "C:\Users\User\source\repos\testproj\testproj\HHeader.h"

using namespace std;

int main()
{
     setlocale(LC_ALL, "ru_RU.UTF-8");
     string s1, s2, s3;
     cout << "Программа вычислает НОД трёх числе m, n, k > MaxInt! " << endl;
     cout << "Введите первое число: ";
     getline(cin, s1);
     while (!isNumber(s1) or s1[0] == '-' or s1.size() > 300) {
         if (s1[0] == '-') cout << "Число не должно содержать минус! Введите снова: ";
         if (s1.size() > 300) cout << "Число слишком длинное! Введите снова: ";
         else cout << "Число введено некорректно! Попробуйте ввести снова: ";
         getline(cin, s1);
     }
     cout << "Введите второе число: ";
     getline(cin, s2);
     while (!isNumber(s2) or s2[0] == '-' or s2.size() > 300) {
         if (s2[0] == '-') cout << "Число не должно содержать минус! Введите снова: ";
         if (s2.size() > 300) cout << "Число слишком длинное! Введите снова: ";
         else cout << "Число введено некорректно! Попробуйте ввести снова: ";
         getline(cin, s2);
     }
     cout << "Введите третье число: ";
     getline(cin, s3);
     while (!isNumber(s3) or s3[0] == '-' or s3.size() > 300) {
         if (s3[0] == '-') cout << "Число не должно содержать минус! Введите снова: ";
         if (s3.size() > 300) cout << "Число слишком длинное! Введите снова: ";
         else cout << "Число введено некорректно! Попробуйте ввести снова: ";
         getline(cin, s3);
     }
     int len1 = s1.length();
     int len2 = s2.length();
     int len3 = s3.length();
     // добавляем нули слева к меньшей подстроке
     //если числа равны 
     if (len1 < len2 and len2 > len3)
     {
          s1.insert(0, len2 - len1, '0');
          s3.insert(0, len2 - len3, '0');
     }
     else
          if (len1 > len2 and len1 > len3)
          {
               s2.insert(0, len1 - len2, '0');
               s3.insert(0, len1 - len3, '0');
          }
          else if (len3 > len2 and len3 > len1)
              {
                  s2.insert(0, len3 - len2, '0');
                  s1.insert(0, len3 - len1, '0');
              }
      int len = s1.length(); // итоговая длина строки (длины строк уже уравняли)
        // делим строку на части по 9 символов 
      int part = len % 9 == 0 ? len / 9 : len / 9 + 1;
        // выделяем память и заполняем 0
      vector <long int> a(part,0);
      vector <long int> b(part, 0);
      vector <long int> c(part, 0);
  
      // вызываем функцию занесения строк в массивы
      massiv(a, s1, len, part);
      massiv(b, s2, len, part);
      massiv(c, s3, len, part);

      longGcd(a, b);
      longGcd(a, c);
      
      cout << "НОД трёх чисел: " << a[part - 1];
      for (int i = part - 2; i >= 0; i--)
           cout << to_str(a[i]); // вывод с конца с ведущими нулями!!
}