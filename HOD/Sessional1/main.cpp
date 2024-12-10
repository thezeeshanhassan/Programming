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
    friend String operator+(const String &lobj, const String &robj);
    char &operator[](int index);

    void printString()
    {
        cout << name << endl;
    }


    friend istream &operator>>(istream &is, String &obj)
    {
        char buffer[100]; 
        is >> buffer;
        obj.length = strlen(buffer);
        obj.name = new char[obj.length + 1];
        strcpy(obj.name, buffer);
        return is;
    }

    friend ostream &operator<<(ostream &os, const String &obj)
    {
        os << obj.name;
        return os;
    }

    bool ends_with(const char *suffix)
    {
        int suffixLength = strlen(suffix);
        if (suffixLength > length)
            return false;
        return strcmp(name + length - suffixLength, suffix) == 0;
    }
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

int main()
{
    String names[10] = {"Akhuwat", "College", "Kasur"};
    names[4] = names[0] + names[1] + names[2];

    names[4].printString();

    names[4][6] = 'Z';
    names[4].printString();

    int size();
    // cin >> names[3];

    // if (names[3].ends_with("abc12"))
    // {
    //     cout << names[3] << " Ends With ABC12" << endl;
    // }
    // else
    // {
    //     cout << names[3] << " Does Not Ends With ABC12" << endl;
    // }
    // return 0;
}