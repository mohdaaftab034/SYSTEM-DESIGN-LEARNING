#include<iostream>
using namespace std;

// Definition of Abstraction in C++ ---> Abstraction is one of the fundamental principles of Object-Oriented Programming (OOP) that focuses on hiding the internal implementation details of a class and exposing only the necessary features to the user. It allows developers to create complex systems by breaking them down into simpler, more manageable components. In C++, abstraction is achieved through the use of abstract classes and interfaces, which define a contract for derived classes to implement specific functionalities without revealing how those functionalities are implemented.

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