#include<iostream>
using namespace std;

// Definition of Constructor ---> A constructor is a special member function of a class that is automatically called when an object of the class is created. It is used to initialize the objects of its class. The constructor has the same name as the class and does not have a return type, not even void.

class Customer {
    string name;
    int account_number;
    int balance;

    public:
    // Default Contructor
    Customer () {
        cout << "Hello Constructor\n";
        name = "Aaftba";
        account_number = 453;
        balance = 1003;
    }

    // Parameterized Constructor
    // Customer(string n, int acc_num, int bal) {
    //     name = n;
    //     account_number = acc_num;
    //     balance = bal;
    // }

    //Constructor Overloading
    Customer(string name, int account_number) {
        this->name = name; // Using 'this' pointer to differentiate between member variables and parameters
        this->account_number = account_number;
        balance = 0; // Default balance
    }
    
    void display() {
        cout << " " << name << " " << account_number << " " << balance << endl;
    }

    // Inline Costructor
    inline Customer(string a, int b, int c) : name(a), account_number(b), balance(c) {
        // This constructor uses an initializer list to initialize the member variables.
    }

    // Copy Constructor
    Customer(Customer& B) {
        name = B.name;
        account_number = B.account_number;
        balance = B.balance;
    }

};

int main() {
    Customer A1;

    Customer A2("Rohit", 123, 5000); // This will cause an error because there is no parameterized constructor defined.
    Customer A3("Aaftab", 456); // This will also cause an error because there is no constructor that takes two parameters defined.

    A1.display();
    A2.display();
    A3.display();

    Customer A4(A3); // This will call the copy constructor to create A4 as a copy of A3 A4.display();
    A4.display();
    return 0;
}