#include "0711239_1.hpp"
#include <iostream>
using namespace std;

int main()
{
    Large a, b;
    cout << "Please ENTER two number a and b: ";
    cin >> a >> b;
    cout << endl;
    cout << "a = " << a << endl;
    cout << "-a = " << -a << endl;
    cout << "b = " << b << endl;
    cout << "-b = " << -b << endl;
    cout << "a > b ? " << (a > b) << endl;
    cout << "a < b ? " << (a < b) << endl;
    cout << "a = b ? " << (a == b) << endl;
    cout << "a + b = " << a + b << endl;
    cout << "a - b = " << a - b << endl;
    cout << "a * b = " << a * b << endl;
    cout << "a / b = " << a / b << endl;
    return 0;
}