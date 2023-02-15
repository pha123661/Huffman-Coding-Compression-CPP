#include <iostream>
#include <cmath>
#include <string>
/*The header files above are those you might use.
You can include other header files if you need to use them.
But make sure those header files can be used in the test environment. */
using namespace std;


class Machine {  /* DO NOT add any code in this parent class and its virtual function*/
    protected:
        string type;
    public:
        virtual void welcome_message(){}
        virtual void problem_solver(){}
};


class Math_machine:public Machine{
    public:
        Math_machine(string type){this->type=type;}
        void welcome_message(){cout<<"Solving the "<<type<<" problem."<<endl;}

        void problem_solver(int x) {
        /*Write your code here*/
        }
};

class String_machine:public Machine{
    public:
        String_machine(string type){this->type=type;}
        void welcome_message(){cout<<"Solving the "<<type<<" problem."<<endl;}

        void problem_solver(string str) {
         /*Write your code here*/
        }
};

int main(){

    /*Write your code here*/

}
