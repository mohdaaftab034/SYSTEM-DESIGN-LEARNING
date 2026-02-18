#include<iostream>
using namespace std;

class Human {
    protected:
    string name;
    int age;

    public:

    void work() {
        cout << "Human is working" << endl;
    }
};

class Student : public Human {
    int roll_number, fees;

    public:

    Student(string name, int age, int roll_number, int fees) {
        this->name = name;
        this->age = age;
        this->roll_number = roll_number;
        this->fees = fees;
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Roll Number: " << roll_number << endl;
        cout << "Fees: " << fees << endl;
    }
};

int main() {
    Student s1("John", 20, 123, 5000);
    s1.display();
    s1.work();

    return 0;
}