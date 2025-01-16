#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <locale.h>

using namespace std;
bool isNumber(const string& str) {//��������� �������� �� ������ ������
    for (char c : str) {
        if (!isdigit(c)) { // ���������� isdigit ��� ������� �������
            return false;
        }
    }
    return true;
}
bool equal(vector <long int> a, vector <long int> b) {// ��������� ����� �� ��� �������
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}
void difference(vector <long int> x, vector <long int> y, vector <long int>& z, int part)
{
    for (int i = 0; i < part; i++) // ������ �� ���� �������� �����, ������� � ����������
    {
        z[i] = x[i] - y[i];
        if (z[i] < 0) // ���� �������� ������ ����, �� ��������
        {
            z[i] += 1000000000;// ��������� ������� ������
            if (i + 1 != part) x[i + 1]--;//�������� ������
            else return;
        }

    }
}

bool isGreater(vector <long int> a, vector <long int> b) {
    for (int i = 0; i < a.size(); i++) // ����������� ��������� ����� �����
    {
        if (a[i] > b[i]) // ���� ������ ������� ����� ������
        {
            return true;
        }
        if (b[i] > a[i]) // ���� ������ ������� ����� ������
        {
            return false;
        }
    }
    return false;
}
// ������� ���������� ������ �� ��������� �� 9 ���� � ��������� �� 
// � ������ � ���� ����� (� �����)
void longGcd(vector <long int>& a, vector <long int> b) { // ������� ��������� ���, ������� � ������� a
    int part = a.size(); // ����������� ������ � �������
    bool flag = true;
    vector <long int> d(part, 0); // ��������������� ������
    for (long int x : b) { // �������� �������� �� b �������, ����� ���� ����� �����������
        if (x != 0) {
            flag = false;
            break;// ���� ��, ������� �� �����
        }
    }
    if (flag) a = b; //�������� a, ������ ��� ��� ������ ����� � ���� ��� 0
    while (!equal(a, b)) {// �������� �������, ������� equal ��������� ����� �� a � b, � ���� ��� �� �����, ��������� ��������
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
    // j - ����� �������� � �������, k - ����� ���������, 
    // i -������� ������� ������� � ���������
    int k = 1, i = len - 9, j = 0;
    while (k <= part)
    {
        // �������� ��������� �� 9 ����, �������� � �����
        // ���� ��������� ��������� �������� ������ 9 ��������,��
        // ����� � 0-�� ������� ��� ����������
        sub = i >= 0 ? s.substr(i, 9) : s.substr(0, 9 + i);
        a[j] = atol(sub.c_str()); // �������������� � �����
        j++; k++;
        i -= 9;
    }
}

// ������� �������������� ����� � ������ � ����������� �����
// �� 9 ��������
string to_str(long int m)
{
    string s = to_string(m);
    s.insert(0, 9 - s.length(), '0');
    return s;
}