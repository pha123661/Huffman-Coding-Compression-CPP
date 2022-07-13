#ifndef STUDENT_0711239
#define STUDENT_0711239

#include <iostream>
#include <string>
using namespace std;

class Large
{
public:
    Large();
    Large(string tstr, int tn, int *thuge);
    friend istream &operator>>(istream &in, Large &a);
    friend ostream &operator<<(ostream &out, const Large &a);
    friend Large operator-(const Large &a); //unary
    friend Large operator+(const Large &a, const Large &b);
    friend Large operator-(const Large &a, const Large &b);
    friend Large absadd(const Large &a, const Large &b);
    friend Large absminus(const Large &a, const Large &b);
    friend Large operator*(const Large &a, const Large &b);
    friend Large operator/(const Large &a, const Large &b);
    friend string operator>(const Large &a, const Large &b);
    friend string operator<(const Large &a, const Large &b);
    friend string operator==(const Large &a, const Large &b);
    friend void findp(const Large &r, const Large &b, int &Q1, int &Q2, int &Q3, int &rounding);

    //private:
    string str; //temp
    int huge[60];
    int n;        //0='+',1='-'
    int point[3]; //1>point>=0
    int rounding;
};

Large::Large()
{
    int i;
    str = "0";
    n = 0;
    rounding = 0;
    for (i = 0; i < 3; i++)
    {
        point[i] = 0;
    }
    for (i = 0; i < 60; i++)
    {
        huge[i] = 0;
    }
}

Large::Large(string tstr, int tn, int *thuge)
{
    int i;
    str = tstr;
    n = tn;
    rounding = 0;
    for (i = 0; i < 3; i++)
    {
        point[i] = 0;
    }
    for (i = 0; i < 60; i++)
    {
        huge[i] = thuge[i];
    }
}

istream &operator>>(istream &in, Large &a)
{
    int i, j;
    in >> a.str;
    for (i = 0; i < a.str.size(); i++)
    {
        j = a.str.size() - (i + 1);
        if (a.str[j] != '-')
        {
            a.huge[i] = a.str[j] - 48;
        }
        else if (a.str[j] == '-')
        {
            a.n = 1;
        }
    }
    return in;
}

ostream &operator<<(ostream &out, const Large &a)
{
    int i = 59, length = 0;

    while (a.huge[i] == 0 && i >= 0)
    {
        length++;
        i--;
    }
    length = 60 - length;

    if (length == 0)
    {
        if ((a.point[0] + a.point[1] + a.point[2]) != 0)
        {
            if (a.n == 1)
                out << '-';
        }
        out << 0;
    }
    else
    {
        if (a.n == 1)
        {
            out << '-';
        }
        for (i = length - 1; i >= 0; i--)
        {
            out << a.huge[i];
        }
    }
    if ((a.point[0] + a.point[1] + a.point[2]) != 0)
        out << '.' << a.point[0] << a.point[1] << a.point[2];
    return out;
}

Large operator-(const Large &a) //unary
{
    Large temp(a.str, a.n, (int *)a.huge);
    if (temp.n == 0)
        temp.n = 1;
    else
        temp.n = 0;
    return temp;
}

Large operator+(const Large &a, const Large &b)
{
    Large temp, ta, tb;
    string f = "False", t = "True";
    ta = a;
    tb = b;
    ta.n = 0;
    tb.n = 0;
    if (a.n == 0 && b.n == 0)
    {
        return absadd(a, b);
    }
    else if (a.n == 0 && b.n == 1)
    {
        if (!((ta < tb) == t)) //ta>=tb
        {
            return absminus(a, b);
        }
        else if ((tb > ta) == t)
        {
            temp = absminus(b, a);
            temp.n = 1;
            return temp;
        }
    }
    else if (a.n == 1 && b.n == 0)
    {
        if (!((ta < tb) == t)) //ta>=tb
        {
            temp = absminus(a, b);
            temp.n = 1;
            return temp;
        }
        else if ((tb > ta) == t)
        {
            return absminus(b, a);
        }
    }
    else if (a.n == 1 && b.n == 1)
    {

        temp = absadd(a, b);
        temp.n = 1;
        return temp;
    }
    cout << "error in '+'" << endl;
    exit(EXIT_FAILURE);
}

Large operator-(const Large &a, const Large &b)
{
    Large temp, ta, tb;
    string f = "False", t = "True";
    ta = a;
    tb = b;
    ta.n = 0;
    tb.n = 0;
    if (a.n == 0 && b.n == 0)
    {
        if (!((tb > ta) == t)) //ta>=tb
        {
            return absminus(a, b);
        }
        else if ((tb > ta) == t)
        {
            temp = absminus(b, a);
            temp.n = 1;
            return temp;
        }
    }
    else if (a.n == 0 && b.n == 1)
    {
        return absadd(a, b);
    }
    else if (a.n == 1 && b.n == 0)
    {
        temp = absadd(a, b);
        temp.n = 1;
        return temp;
    }
    else if (a.n == 1 && b.n == 1)
    {
        if (!((tb > ta) == t)) //ta>=tb
        {
            temp = absminus(a, b);
            temp.n = 1;
            return temp;
        }
        else if ((tb > ta) == t)
        {
            return absminus(b, a);
        }
    }
    cout << "error in '-'" << endl;
    exit(EXIT_FAILURE);
}

Large absadd(const Large &a, const Large &b)
{
    int i, sum[60] = {0};
    for (i = 0; i < 60; i++)
    {
        sum[i] = a.huge[i] + b.huge[i];
    }
    for (i = 0; i < 59; i++)
    {
        sum[i + 1] += sum[i] / 10;
        sum[i] = sum[i] % 10;
    }
    return Large("don't read this", 0, (int *)sum);
}

Large absminus(const Large &a, const Large &b)
{
    int i, ans[60];
    for (i = 0; i < 60; i++)
    {
        ans[i] = a.huge[i] - b.huge[i];
    }
    for (i = 0; i < 59; i++)
    {
        if (ans[i] < 0)
        {
            ans[i] += 10;
            ans[i + 1] -= 1;
        }
    }
    return Large("don't read this", 0, (int *)ans);
}

Large operator*(const Large &a, const Large &b)
{
    int ans[120] = {0}, i, j;
    int pn = 0;
    for (i = 0; i < 60; i++)
    {
        if (a.huge[i] == 0)
            continue;
        for (j = 0; i + j < 60; j++)
        {
            ans[i + j] += a.huge[i] * b.huge[j];
        }
    }
    for (i = 0; i < 119; i++)
    {
        ans[i + 1] += ans[i] / 10;
        ans[i] = ans[i] % 10;
    }
    if ((a.n + b.n) == 2)
        pn = 0;
    else if ((a.n + b.n) == 1)
        pn = 1;
    else if ((a.n + b.n) == 0)
        pn = 0;
    return Large("don't read this", pn, (int *)ans);
}

void findp(const Large &r, const Large &b, int &Q1, int &Q2, int &Q3, int &rounding)
{
    Large tr = r, tb = b, Q;
    string f = "False", t = "True";
    tr.n = 0;
    tb.n = 0;
    int i, lenr = 0, lenb = 0, n;
    for (i = 55; i >= 0; i--)
    {
        tr.huge[i + 4] = tr.huge[i];
    }
    for (i = 0; i < 4; i++)
    {
        tr.huge[i] = 0;
    }
    i = 59;
    while (tr.huge[i] == 0 && i >= 0)
    {
        lenr++;
        i--;
    }
    lenr = 60 - lenr;
    i = 59;
    while (tb.huge[i] == 0 && i >= 0)
    {
        lenb++;
        i--;
    }
    lenb = 60 - lenb;
    for (n = lenr - lenb; n >= 0; n--)
    {
        for (i = lenb - 1; i >= 0; i--)
        {
            tb.huge[i + n] = tb.huge[i];
        }

        for (i = 0; i < n; i++)
        {
            tb.huge[i] = 0;
        }
        while (!((tb > tr) == t))
        {
            tr = tr - tb;
            Q.huge[n]++;
        }
        tb = b;
        tb.n = 0;
    }
    Q.huge[1] = (Q.huge[1] + (Q.huge[0] + 5) / 10);
    Q.huge[2] = (Q.huge[2] + Q.huge[1] / 10);
    Q.huge[3] = (Q.huge[3] + Q.huge[2] / 10);
    rounding = Q.huge[3] / 10;
    Q1 = Q.huge[3] % 10;
    Q2 = Q.huge[2] % 10;
    Q3 = Q.huge[1] % 10;
}

Large operator/(const Large &a, const Large &b)
{
    Large ta = a, tb = b, Q, r, ONE;
    string f = "False", t = "True";
    int one[60] = {0}, tempn = 0;
    one[0] = 1;
    ONE = Large("don't read this", 0, (int *)one);
    ta.n = 0;
    tb.n = 0;
    int i, lena = 0, lenb = 0, n;
    i = 59;
    while (ta.huge[i] == 0 && i >= 0)
    {
        lena++;
        i--;
    }
    lena = 60 - lena;
    i = 59;
    while (tb.huge[i] == 0 && i >= 0)
    {
        lenb++;
        i--;
    }
    lenb = 60 - lenb;
    if (lenb == 0)
    {
        cout << "undifined" << endl;
        return r;
    }
    if (lena >= lenb)
    {
        for (n = lena - lenb; n >= 0; n--)
        {

            for (i = lenb - 1; i >= 0; i--)
            {
                tb.huge[i + n] = tb.huge[i];
            }

            for (i = 0; i < n; i++)
            {
                tb.huge[i] = 0;
            }
            while (!((tb > ta) == t))
            {
                ta = ta - tb;
                Q.huge[n]++;
            }
            tb = b;
            tb.n = 0;
        }
        r = ta;
    }
    else
    {
        r = ta;
    }
    if ((a.n + b.n) == 2)
        Q.n = 0;
    else if ((a.n + b.n) == 1)
        Q.n = 1;
    else if ((a.n + b.n) == 0)
        Q.n = 0;
    findp(r, b, Q.point[0], Q.point[1], Q.point[2], Q.rounding);

    if (Q.rounding == 1)
    {
        tempn = Q.n;
        Q = Q + ONE;
        Q.n = tempn;
    }

    return Q;
}

string operator>(const Large &a, const Large &b)
{
    int i;
    string f = "False", t = "True";
    if (a.n < b.n)
        return t;
    else if (a.n > b.n)
        return f;
    else if (a.n == 0) //all positive
    {
        for (i = 59; i >= 0; i--)
        {
            if (a.huge[i] > b.huge[i])
            {
                return t;
            }
            else if (b.huge[i] > a.huge[i])
            {
                return f;
            }
        }
    }
    else if (a.n == 1) //all negetive
    {
        for (i = 59; i >= 0; i--)
        {

            if (b.huge[i] > a.huge[i])
            {

                return t;
            }
            else if (a.huge[i] > b.huge[i])
            {
                return f;
            }
        }
    }
    return f; //a==b
}

string operator<(const Large &a, const Large &b)
{
    int i;
    string f = "False", t = "True";
    if (a.n < b.n) //a >= 0 && b < 0
        return f;
    else if (a.n > b.n) //b >= 0 && a < 0
        return t;
    else if (a.n == 0) //all positive
    {
        for (i = 59; i >= 0; i--)
        {
            if (a.huge[i] > b.huge[i])
            {
                return f;
            }
            else if (b.huge[i] > a.huge[i])
            {
                return t;
            }
        }
    }
    else if (a.n == 1) //all negetive
    {
        for (i = 59; i >= 0; i--)
        {
            if (b.huge[i] > a.huge[i])
            {
                return f;
            }
            else if (a.huge[i] > b.huge[i])
            {
                return t;
            }
        }
    }
    return f; //a==b
}

string operator==(const Large &a, const Large &b)
{
    string f = "False", t = "True";
    if ((a > b) == t || (b > a) == t)
        return f;
    else
        return t;
}

#endif