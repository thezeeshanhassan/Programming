#include <iostream>
#include <cstring>

using namespace std;

class Name
{
    char *fname;
    char *lname;
    char mname;

public:
    Name(const char *f, const char m, const char *l)
    {
        fname = new char[strlen(f) + 1];
        lname = new char[strlen(l) + 1];
        mname = m;
        strcpy(fname, f);
        strcpy(lname, l);
    }

    Name(const Name &other)
    {
        fname = new char[strlen(other.fname) + 1];
        lname = new char[strlen(other.lname) + 1];
        strcpy(fname, other.fname);
        strcpy(lname, other.lname);
        mname = other.mname;
    }

    Name &operator=(const Name &other)
    {
        fname = new char[strlen(other.fname) + 1];
        lname = new char[strlen(other.lname) + 1];
        strcpy(fname, other.fname);
        strcpy(lname, other.lname);
        mname = other.mname;
    }

    void display()
    {
        cout << fname << " " << mname << ". " << lname << endl;
    }
};

class FullName : public Name
{
    char *prefix;

public:
    FullName(const char *pre, const char *f, const char m, const char *l) : Name(f, m, l)
    {
        prefix = new char[strlen(pre) + 1];
        strcpy(prefix, pre);
    }

    FullName(const FullName &other) : Name(other)
    {
        prefix = new char[strlen(other.prefix) + 1];
        strcpy(prefix, other.prefix);
    }

    FullName &operator=(const FullName &other)
    {
        if (this == &other) // Self-assignment check
            return *this;
        Name::operator=(other);
        delete[] prefix;
        prefix = new char[strlen(other.prefix) + 1];
        strcpy(prefix, other.prefix);
        return *this;
    }

    void display()
    {
        cout << prefix << " ";
        Name::display();
    }
};

int main()
{
    FullName obj("Mr. ", "Muhammad", 'Z', "Hassan");
    obj.display();

    FullName obj2(obj);
    obj2.display();

    FullName obj3 = obj2;
    obj3.display();
}