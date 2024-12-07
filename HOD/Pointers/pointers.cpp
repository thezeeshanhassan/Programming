#include <iostream>
using namespace std;

int main()
{
    char s[] = "Gorm";
    cout<<*s<<endl;


    char *p = "12";
    // In Above p array [] is constant also but we not have to mention it we
    // can not change its 
    // content OR "12" (Object) is Also constant

    // Pointer to Constant
    const char *pc = s; // Object is Constant
    // pc[3] = 'g'; Error
    pc = p;
    cout<<pc;


    // Constant Pointer
    char *const cp = s;
    cp[1] = 'a';
    // cp = p; Pointer is Constant


    // Constant Pointer to Constant Object

    const char *const cpc = s;
    // Object Is Also Constant
    // Pointer is Also Constant



    int i{7};
    int q = &i;

    

}