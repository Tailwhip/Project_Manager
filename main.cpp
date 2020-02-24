#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>

#include "documenter.h"
#include "menu.h"


using namespace std;

int main() {

    typedef void (*pointFunction)(); // void (*)()

    vector<string> pointNames = {"New Project", "Update project", "Delete project"};
    vector<pointFunction> pointsFunctions = {&Documenter::exampleFunc, &Documenter::exampleFunc,
    &Documenter::exampleFunc};

    Menu menu(pointNames, pointsFunctions);

    vector<string> pointNames2 = {"Point", "Point2", "Point3"};
    menu.addPoints(pointNames2, 3);

    menu.addFunctionality(&Documenter::exampleFunc, 1);

    menu.show();

    //void (Documenter::*functionPtr)() = &docer.exampleFunc;
    //menu.addFunctionality(& Documenter::exampleFunc, 1);
    return 0;
}

/*
// sposób wykorzystania
int main()
{
  Dyrektor *director = new Dyrektor();
  Budowniczy *builder = new BudowniczyJakis();
  Produkt *product;
  director.Konstruuj(builder);
  product = builder.pobierzWynik();
}
*/
