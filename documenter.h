#include <iostream>

#ifndef _DOCUMENTER_
#define _DOCUMENTER_


using namespace std;

class Documenter // Builder
{
public:

    static void exampleFunc();

    void anotherFunction();
    /*
    void zbudujCzescA() = 0;
    void zbudujCzescB() = 0;
    Produkt pobierzWynik() = 0;
    */
};
// builds any document from scratch

#endif // _DOCUMENTER_
