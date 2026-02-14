#include<iostream>
using namespace std;

// Definition of Encapsulation int C++ ---> Encapsulation is one of the fundamental principles of Object-Oriented Programming (OOP) that combines data and functions that operate on that data into a single unit called a class. It restricts direct access to some of an object's components, which can prevent the accidental modification of data. Encapsulation is achieved through the use of access specifiers (private, protected, public) in C++.

class Customer {
    string name;
    int acc_number,balance;

    public:
    Customer(string name, int acc_number, int balance) {
        this->name = name;
        this->acc_number = acc_number;
        this->balance = balance;
    }

    void deposit(int amount) {
        if(amount > 0) {
            balance += amount;
        } else {
            cout<<"Invalid Amount"<< endl;
        }
    }

    void withdraw(int amount) {
        if(balance <= balance && amount > 0) {
            balance -= amount;
        }
    }

    void display() {
        cout<<name<<" "<<acc_number<<" "<<balance<<endl;
    }
};

int main() {
    Customer A1("Alice", 1, 2000);
    Customer A2("Charlie", 2, 4000);
    Customer A3("Bob", 3, 3000);

    A1.deposit(-10);
    A1.display();
    return 0;
}