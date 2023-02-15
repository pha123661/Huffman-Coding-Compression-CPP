#include <cmath>
#include <iostream>
#include <string>
#include <vector>
/*The header files above are those you might use.
You can include other header files if you need to use them.
But make sure those header files can be used in the test environment. */
using namespace std;

class Machine
{ /* DO NOT add any code in this parent class and its virtual function*/
protected:
    string type;

public:
    virtual void welcome_message() {}
    virtual void problem_solver() {}
};

class Math_machine : public Machine
{
public:
    Math_machine(string type) { this->type = type; }
    using Machine::problem_solver;
    void welcome_message() { cout << "Solving the " << type << " problem." << endl; }
    class math_ans
    {
    public:
        math_ans() : a1(0), a2(0) {}
        math_ans(int a, int b) : a1(a), a2(b) {}
        int a1, a2;
        int get_a3()
        {
            return abs(a1 - a2);
        }
    };
    void output(vector<math_ans> &ans)
    {
        int min = 2147483647, i, min_index = -1;
        for (i = 0; i < ans.size(); i++)
        {
            if (ans.at(i).get_a3() <= min)
            {
                min = ans.at(i).get_a3();
                min_index = i;
            }
        }
        cout << ans.at(min_index).a1 << ' ' << ans.at(min_index).a2 << endl;
    }
    void problem_solver(int x)
    {
        vector<math_ans> ans;
        int temp1, temp2;
        for (temp1 = (int)sqrt(x); temp1 >= 1; temp1--)
        {
            for (temp2 = (int)sqrt(x); temp2 <= x; temp2++)
            {
                if (temp1 * temp2 == x || temp1 * temp2 == x + 1)
                {
                    ans.push_back(math_ans(temp1, temp2));
                }
            }
        }
        output(ans);
    }
};

class String_machine : public Machine
{
public:
    String_machine(string type) { this->type = type; }
    using Machine::problem_solver;
    void welcome_message() { cout << "Solving the " << type << " problem." << endl; }
    string next_stage(string str)
    {
        if (str.at(0) == '0' && str.at(str.size() - 1) == '1')
        {
            str = "0" + str + "1";
        }
        else if (str.at(0) == '1' && str.at(str.size() - 1) == '0')
        {
            str = "1" + str + "0";
        }
        return str;
    }
    void problem_solver(string str)
    {
        string sub;
        int sum = 0, pos, sub_l;
        //starts from "01"
        sub = "01";
        for (sub_l = 2; sub_l <= str.size(); sub_l += 2)
        {
            pos = 0;
            while (pos != str.npos)
            {
                pos = str.find(sub, pos);
                if (pos != str.npos)
                {
                    pos++;
                    sum++;
                }
            }
            sub = next_stage(sub);
        }
        //starts from "10"
        sub = "10";
        for (sub_l = 2; sub_l <= str.size(); sub_l += 2)
        {
            pos = 0;
            while (pos != str.npos)
            {
                pos = str.find(sub, pos);
                if (pos != str.npos)
                {
                    pos++;
                    sum++;
                }
            }
            sub = next_stage(sub);
        }

        cout << "sum = " << sum << endl;
    }
};

int main()
{
    string temp, p;
    int a;
    while (cin >> temp)
    {
        if (temp == "string")
        {
            String_machine s(temp);
            s.welcome_message();
            cin >> p;
            s.problem_solver(p);
        }
        else if (temp == "math")
        {
            Math_machine m(temp);
            m.welcome_message();
            cin >> a;
            m.problem_solver(a);
        }
    }
    getchar();
    return 0;
}
