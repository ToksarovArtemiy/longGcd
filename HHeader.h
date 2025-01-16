#include <vector>
#include <string>
using namespace std;
bool isNumber(const string& str);
bool equal(vector <long int> a, vector <long int> b);
void difference(vector <long int> x, vector <long int> y, vector <long int>& z, int part);
bool isGreater(vector <long int> a, vector <long int> b);
void longGcd(vector <long int>& a, vector <long int> b);
void massiv(vector <long int>& a, string s, int len, int part);
string to_str(long int m);