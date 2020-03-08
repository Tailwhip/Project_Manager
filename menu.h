#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <stdlib.h>
#include <conio.h>
#include <algorithm>

#include "documenter.h"

#ifndef _MENU_
#define _MENU_

using namespace std;

class Menu {

    typedef void (*void_fnc_ptr)(); // void (*)()

    unsigned choiceNum = 0;
    unsigned pointsCount = 0;
    const unsigned pointsCapacity = 100;
    struct menu_point {
        string name = nullptr;
        void_fnc_ptr functionality = nullptr;
        menu_point(const string & name, void_fnc_ptr functionality)
        : name(name), functionality(functionality) {}
        // order by name
        bool operator < (const menu_point& p) const {return name < p.name;}
    };
     vector<menu_point> points = {};
     vector<menu_point>::iterator it = points.begin();

public:
    Menu(vector<string> &, vector<void_fnc_ptr> &);
    ~Menu();
    // main function to generate the menu
    void show();
    // broadcasts all points names on the screen
    void refresh();
    // adds a new point to the list of points, functionality can be added later
    void addPoints(const string &, void_fnc_ptr = nullptr, unsigned = 0);
    // adds a new points to the list of points, functionalities can be added later
    void addPoints(vector<string> &, vector<void_fnc_ptr> = {}, unsigned = 0);
    // adds a functionality to the points with no functionality added yet
    void addFunctionality(void_fnc_ptr, unsigned);
    // sorts all points alphabetically by name
    void sortAlpha();
private:
    void fillPoints(vector<string> &, vector<void_fnc_ptr> &);
    void castFunctions();
    static void emptyFunction();
    bool confirmCheck();
    static bool sortFunction(const menu_point &left, const menu_point &right){return left < right;}
};

#endif // _MENU_
