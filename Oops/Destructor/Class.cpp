#include<iostream>
using namespace std;

class Customer {
    string name;
    int *data;

    public:
    Customer() {
        name = "Aaftab";
        data = new int;
        *data = 100; // Assigning a value to the dynamically allocated integer
        cout << "Hello Constructor\n";
    }

    ~Customer() {
        cout << "Hello Destructor\n";
        delete data; // Deallocating the dynamically allocated array
    }
};

int main() {
    Customer A1;
}