#include <iostream>
#include<string>
using namespace std;

class Name
{
private:
    char *fname;
    char *mname;
    char *lname;

public:
    Name(const char *f, const char *m = "", const char *l = "")
    {
        fname = new char[strlen(f) + 1];
        strcpy(fname, f);
    }
};
