#include <iostream>
#include <String.h>
using namespace std;

class String
{
private:
    char *name;
    int length;

public:
    String() : name(nullptr), length(0) {}
    String(const char *aname);
    String(const String &obj);
    char &operator[](int index) const;
    friend String operator+(const String &lobj, const String &robj);
    friend ostream &operator<<(ostream &out, const String &str);
    friend istream &operator>>(istream &in, const String &str);
    bool ends_with(const char *str) const;
    String &operator=(const String &obj);
};

String &String::operator=(const String &obj)
{
    cout << "Assignment Operator Called" << endl;
    if (this != &obj)
    {
        delete[] name;
        length = obj.length;
        name = new char[obj.length + 1];
        for (int i{}; i < length; i += 1)
        {
            name[i] = obj.name[i];
        }
    }
    return *this;
}

String::String(const char *aname)
{
    length = strlen(aname);
    name = new char[strlen(aname) + 1];
    for (int i{}; i < strlen(aname); i += 1)
    {
        name[i] = aname[i];
    }
}

String::String(const String &obj)
{
    this->length = obj.length;
    this->name = new char[obj.length + 1];

    for (int i{}; i < length; i += 1)
    {
        name[i] = obj.name[i];
    }
}

String operator+(const String &lobj, const String &robj)
{
    char *newStr = new char[lobj.length + robj.length + 1];
    for (int i{}; i < lobj.length; i++)
    {
        newStr[i] = lobj.name[i];
    }
    for (int i{}; i < robj.length; i++)
    {
        newStr[lobj.length + i] = robj.name[i];
    }
    newStr[lobj.length + robj.length] = '\0';
    return newStr;
}

char &String::operator[](int index) const
{
    if (index < 0 || index >= this->length)
    {
        throw out_of_range("Index out of range");
    }

    return name[index];
}

bool String::ends_with(const char *str) const
{
    int strLength = strlen(str);
    if (strLength > this->length)
    {
        return false;
    }
    int startPoint{this->length - strLength};
    for (int i{}; i < strLength; i++)
    {
        if (name[startPoint + i] != str[i])
        {
            return false;
        }
    }
    return true;
}

ostream &operator<<(ostream &out, const String &str)
{
    out << str << endl;
    return out;
}

ostream &operator<<(ostream &out, const char *str)
{
    for (int i{}; i < strlen(str); i++)
    {
        out << str[i];
    }
    return out;
}

istream &operator>>(istream &in, const String &str)
{
    char *newstr = new char[100];
    in >> newstr;
    return in;
}

void doSomething(String aString)
{
    cout << "Hello";
    cout << aString;
}

int main()
{
    String names[10] = {"Akhuwat", "College", "Kasur"};
    names[4] = names[0] + names[1] + names[2];

    cout << names[4] << endl;

    names[4][6] = 'Z';
    cout << names[4] << endl;
    // doSomething(names[4]);
    // int size();
    // cin >> names[3];
    cout << names[2] << endl;

    // if (names[2].ends_with("abc12"))
    // {
    //     cout << names[2] << " Ends With ABC12" << endl;
    // }
    // else
    // {
    //     cout << names[2] << " Does Not Ends With ABC12" << endl;
    // }
    // return 0;
}