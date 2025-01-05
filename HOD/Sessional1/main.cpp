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
    bool ends_with(const char *str) const;
    String &operator=(const String &obj);
    char &operator[](int index);
    int size() const;

    friend String operator+(const String &lobj, const String &robj);
    friend ostream &operator<<(ostream &out, const String &obj);
    friend istream &operator>>(istream &in, String &str);
};

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
String &String::operator=(const String &obj)
{
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

char &String::operator[](int index)
{
    if (index < 0 || index >= this->length)
    {
        throw out_of_range("Index out of range");
    }

    return name[index];
}

int String::size() const
{
    cout << "Size of string Function Invked" << endl;
    return length;
}

ostream &operator<<(ostream &out, const String &str)
{
    out << str.name;
    return out;
}

istream &operator>>(istream &in, String &str)
{
    char buffer[100];
    in >> buffer;
    str.length = strlen(buffer);
    str.name = new char[str.length + 1];
    for (int i{}; i < str.length; i += 1)
    {
        str.name[i] = buffer[i];
    }
    
    return in;
}
void doSomething(String aString)
{
    cout << aString << endl;
}

int main()
{
    String names[10] = {"Akhuwat", "College", "Kasur"};
    names[4] = names[0] + names[1] + names[2];

    cout << names[4] << endl;

    names[4][6] = 'Z';
    cout << names[4] << endl;
    cout << names[2] << endl;
    // doSomething(names[4]);
    int size();
    cin >> names[3];
    cout << names[3] << endl;
    if (names[3].ends_with("abc12"))
    {
        cout << names[3] << " Ends With ABC12" << endl;
    }
    else
    {
        cout << names[3] << " Does Not Ends With ABC12" << endl;
    }
    return 0;
}