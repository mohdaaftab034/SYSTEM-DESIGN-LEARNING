#include <iostream>

using namespace std;

class Student
{
public:
    string name;
    int age, roll_number;
    string grade;

    // Function Getter and Setter
public:
    void setName(string s)
    {
        name = s;
    }
    void setAge(int a)
    {
        age = a;
    }

    void setRollNumber(int r)
    {
        roll_number = r;
    }

    void setGrade(string g)
    {
        grade = g;
    }

    void getName()
    {
        cout << "Name: " << name << endl;
    }

    void getAge()
    {
        cout << "Age: " << age << endl;
    }

    void getRollNumber()
    {
        cout << "Roll Number: " << roll_number << endl;
    }

    void getGrade()
    {
        cout << "Grade: " << grade << endl;
    }
};

int main()
{
    // Student S1;
    // S1.setName("John Doe");
    // S1.setAge(20);
    // S1.setRollNumber(12345);
    // S1.setGrade("A");
    // S1.getName();
    // S1.getAge();
    // S1.getRollNumber();
    // S1.getGrade();

    // Dymanic Object Creation
    Student *S2 = new Student();
    S2->setName("Jane Doe");
    S2->setAge(22);
    S2->setRollNumber(54321);
    S2->setGrade("A+");
    S2->getName();
    S2->getAge();
    S2->getRollNumber();
    S2->getGrade();

    return 0;
}