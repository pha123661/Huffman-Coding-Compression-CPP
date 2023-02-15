#include <iostream>
#include <math.h>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Polynomial
{
public:
    Polynomial();
    Polynomial(int &n);
    ~Polynomial();
    int calculate();
    int firstDerivative();
    int secDerivative();

private:
    int x;
    vector<int> coef;
};

Polynomial ::Polynomial() : x(0) {}

Polynomial ::Polynomial(int &n)
{
    int tempa = 0, i;
    string str = "\n", temps;
    getline(cin, str); //clear previous '\n'
    getline(cin, temps);
    stringstream ss(temps);
    vector<int> temp;
    temp.clear();
    coef.clear();
    while (ss >> tempa)
    {
        temp.push_back(tempa);
    }
    for (i = 0; i < temp.size(); i++)
    {
        coef.push_back(temp.at(temp.size() - i - 1));
    }
    x = n;
}

Polynomial ::~Polynomial()
{
    coef.clear();
}

int Polynomial::calculate()
{
    int rst = 0, i;
    for (i = coef.size() - 1; i >= 0; i--)
    {
        rst += coef.at(i) * pow(x, i);
    }
    return rst;
}

int Polynomial::firstDerivative()
{
    int rst = 0, i;
    for (i = coef.size() - 1; i >= 1; i--)
    {
        rst += coef.at(i) * i * pow(x, i - 1);
    }
    return rst;
}

int Polynomial::secDerivative()
{
    int rst = 0, i;
    for (i = coef.size() - 1; i >= 2; i--)
    {
        rst += coef.at(i) * i * (i - 1) * pow(x, i - 2);
    }
    return rst;
}

int main()
{
    int n;
    vector<int> a;
    Polynomial p;
    while (cin >> n)
    {
        p = Polynomial(n);
        cout << p.calculate() << ' ' << p.firstDerivative() << ' ' << p.secDerivative() << endl;
    }
    return 0;
}