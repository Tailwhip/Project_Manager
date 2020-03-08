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
    vector<pointFunction> pointsFunctions
    {&Documenter::exampleFunc, nullptr, &Documenter::exampleFunc};

    Menu menu(pointNames, pointsFunctions);

    vector<string> pointNames2 = {"Point1", "Point2", "Point3","Z_point","A_Point"};

    vector<pointFunction> pointsFunctions2 (pointNames2.size(), &Documenter::exampleFunc);

    menu.addPoints(pointNames2, pointsFunctions2, 4);

    menu.addFunctionality(&Documenter::exampleFunc, 5);

    menu.sortAlpha();

    menu.show();

    return 0;
}
