#include <iostream>
using namespace std;

class RollNumber
{
private:
    const int rollnum;

public:
    RollNumber(int val) : rollnum(val) {}
    void getObjectValue()
    {
        cout << this->rollnum << endl;
    }
};

int main()
{
    // Here is Only First Example Where Developer can Call Constructor
    RollNumber obj[2] = {RollNumber(0), RollNumber(1)};
    // This Above Can Also Be Wriiten As
    RollNumber obj2[2] = {1, 2};



    

    //RollNumber obj3[2]; // Error Because No Default Constructor is Wrriten





    obj[0].getObjectValue();
    obj[1].getObjectValue();

    obj2[0].getObjectValue();
    obj2[1].getObjectValue();

    return 0;
}

// obj[2] Is an Array Of Object. By Default, Default Constructor will be called.
