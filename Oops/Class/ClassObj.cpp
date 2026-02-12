#include<iostream>
using namespace std;

class Obj {
    char c;
    int a;
    char b;
    double d;
};

int main() {

    Obj O;

    cout << "Size of Object O: " << sizeof(O) << " bytes" << endl;
    return 0;
}