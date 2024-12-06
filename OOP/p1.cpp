#include <iostream>
using namespace std;

class Student
{
    const int rollNo;
    float gpa;
    static int variable;

public:
    Student(int arollNo) : rollNo(arollNo) { gpa = 3.8; }
    int getRollNo()
    {
        return rollNo;
    }
};

// Static Varible Defination
int Student::variable = 1;

int main()
{
    Student student(12);
    cout << "Roll Number is " << student.getRollNo();
}

// Data Members GET Value at the Time of their lifetime assigning in Member Initialization List

// Problem
// We want to give roll number at the time of object creation that later not be modified (Mean it should be constant)