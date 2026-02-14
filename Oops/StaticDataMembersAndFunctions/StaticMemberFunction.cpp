#include<iostream>
using namespace std;

class Customer {
    string name;
    int acc_number, balance;
    static int total_customer;

    public:

    Customer(string name, int acc_number, int balance) {
        this->name = name;
        this->acc_number = acc_number;
        this->balance = balance;
        total_customer++;
    }

    static void accessStatic() {
        cout<< total_customer << endl;
    }

    void display() {
        cout<<name<<" "<<acc_number<<" "<<balance<<" "<<total_customer<<endl;
    }

    void display_total() {
        cout<<total_customer<<endl;
    }
};

int Customer::total_customer = 0;

int main() {

    Customer A1("Alice", 1, 2000);
    Customer A2("Charlie", 2, 3000);
    Customer A3("Bob", 3, 4000);

    Customer::accessStatic();
    A1.display_total();

    return 0;
}