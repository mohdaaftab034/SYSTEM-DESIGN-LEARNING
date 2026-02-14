#include<iostream>
using namespace std;

class Customer {
    string name;
    int acc_number, balance;
    static int total_customers; // Static data member to keep track of total customers

    public:
    Customer(string name, int acc_number, int balance) {
        this->name = name;
        this->acc_number = acc_number;
        this->balance = balance;
        total_customers++; // Increment total customers when a new customer is created
    }

    void display() {
        cout << "Name: " << name << ", Account Number: " << acc_number << ", Balance: " << balance << ", Total Customers: " << total_customers << endl;
    }

    void display_total() {
        cout<<total_customers<<endl;
    }
};

int Customer::total_customers = 0; // Initialize static data member

int main() {
    Customer A1("Alice", 12345, 1000);
    Customer A2("Bob", 67890, 2000);
    Customer A3("Charlie", 54321, 1500);
    A1.display();
    A2.display();
    A3.display();
    A2.display_total();
    return 0;
}