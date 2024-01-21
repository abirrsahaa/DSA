// You are using GCC
#include <iostream>
using namespace std;

class Person
{
public:
    string name;
    string code;
    void input()
    {
        cin >> name >> code;
        // cout << "i m name " << name << endl;
        // cout << "i m code " << code << endl;
    }

    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Code: " << code << endl;
    }
    // Type your code here
};

class Account : virtual public Person
{
public:
    int pay;
    int experience;
    void input()
    {
        Person::input();
        cin >> pay;
        cin >> experience;
        // cout << " i am pay " << pay << endl;
    }
    void display()
    {
        // cout<<" i am inside "
        Person::display();
        cout << "Pay: " << this->pay << endl;
        cout << "experience: " << this->experience << endl;
    }
    // Type your code here
};

// class Admin : virtual public Person
// {
//     // Type your code here
// public:
//     int experence;
//     void input()
//     {
//         Person::input();
//         cin >> experence;
//         cout << " i am expereince " << experence;
//     }
//     void display()
//     {
//         Person::display();
//         cout << "experence" << experence << endl;
//     }
// };

class Master : public Account
{
    // Type your code here
public:
    void input()
    {
        Account::input();
        // Admin::input();
    }

    void display()
    {
        Account::display();
        // Admin::display();
        cout << endl;
    }
};

int main()
{
    int n, i;
    cin >> n;
    Master emp[n];
    for (int i = 0; i < n; i++)
    {
        emp[i].input();
    }
    for (int i = 0; i < n; i++)
    {
        emp[i].display();
    }
}