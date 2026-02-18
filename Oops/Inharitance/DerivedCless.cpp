#include <iostream>
using namespace std;

class Human
{
public:
    string name;
    int age, weight;
};

class Student : public Human
{
    int roll_number, fees;

public:
    void setData(string n, int a, int w, int r, int f)
    {
        name = n;
        age = a;
        weight = w;
        roll_number = r;
        fees = f;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Weight: " << weight << endl;
        cout << "Roll Number: " << roll_number << endl;
        cout << "Fees: " << fees << endl;
    }
};

int main()
{

    Student S1;
    S1.setData("John", 20, 70, 101, 5000);

    return 0;
}