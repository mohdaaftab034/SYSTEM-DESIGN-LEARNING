#include<iostream>
using namespace std;

class NoSingleton {
    public:
        NoSingleton() {
            cout << "NoSingleton constructor called" << endl;
        }
};

int main () {

    NoSingleton* s1 = new NoSingleton();
    NoSingleton* s2 = new NoSingleton();

    if(s1 == s2) {
        cout << "Both pointers point to the same instance" << endl;
    } else {
        cout << "Both pointers point to different instances" << endl;
    }

    return 0;
}