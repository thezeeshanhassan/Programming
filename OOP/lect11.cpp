#include <iostream>
using namespace std;

class Student
{
    const int rollNo;
    float gpa;
    static int noOfStudents;

public:
    Student(int arollNo) : rollNo(arollNo)
    {
        gpa = 3.8;
        noOfStudents += 1;
    }
    // To access Private Static Data Member Only to Access Static Data Members
    static int getnoOfStudents()
    {
        return noOfStudents;
    }
    int getRollNo()
    {
        return rollNo;
    }
    // Static Variable Initilize Just only One Time (Below is Example)
    void func(int i)
    {
        static int a = i;
        cout << a << endl;
    }
};

// Static Varible Defination
int Student::noOfStudents = 0;

int main()
{
    int a = Student::getnoOfStudents();
    cout << a << endl;
    cout << "Number of Students are " << Student::getnoOfStudents() << endl;
    Student student(12);
    cout << "Number of Students are " << Student::getnoOfStudents() << endl;

    student.func(1);
    student.func(2);
}

// Data Members GET Value at the Time of their lifetime assigning in Member Initialization List


// Problem
// We want to give roll number at the time of object creation that later not be modified (Mean it should be constant)
// Member Initilizaion List
