#include <iostream>
#include <String.h>
using namespace std;

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

char &String::operator[](int index)
{
    if (index < 0 || index >= this->length)
    {
        throw out_of_range("Index out of range");
    }

    return name[index];
}

ostream &String::operator<<(ostream &os, const String &str)
{
    os << str.name;
    return os;
}