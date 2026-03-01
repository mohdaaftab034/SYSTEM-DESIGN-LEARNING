#include<iostream>
using namespace std;

class Person {
    protected:
    string name;

    public:

    void introduce() {
        cout << "Hi, I am " << name << endl;
    }
};

class Employee : public Person {
    protected:
    int salary;

    public:

    void monthlySalary() {
        cout << "My monthly salary is " << salary << endl;
    }
};

class Manager : public Employee {
    public:

    string department;

    Manager(string name, int salary, string department) {
        this->name = name;
        this->salary = salary;
        this->department = department;
    }

    void managerInfo() {
        cout << "I am a manager in " << department << " department." << endl;
    }
};

int main() {

    Manager A1("Alice", 5000, "Sales");
    A1.introduce();
    A1.monthlySalary();
    A1.managerInfo();
    return 0;
}