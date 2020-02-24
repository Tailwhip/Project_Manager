#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <stdlib.h>
#include <conio.h>

#include "documenter.h"

#ifndef _MENU_
#define _MENU_

using namespace std;

class Menu {

    typedef void (*void_fnc_ptr)(); // void (*)()

    unsigned choiceNum = 0;
    unsigned pointsCount = 0;
    const unsigned pointsCapacity = 100;
    vector<string> pointsNames = {};
    vector<void_fnc_ptr> pointsFunctions = {};
    struct menu_point {
        string * name = nullptr;
        void_fnc_ptr functionality = nullptr;
        unsigned position = 0;
    };
     vector<menu_point> points = {};

public:
    Menu(vector<string> &, vector<void_fnc_ptr> &);
    ~Menu();
    void show(); // main function to generate the menu
    void refresh();
    void addPoints(const string &, unsigned = 0);
    void addPoints(vector<string> & , unsigned = 0);
    void addFunctionality(void_fnc_ptr, unsigned);
    void sortAlpha();

private:
    void fillPoints();
    void castFunctions();
    static void emptyFunction();
    bool confirmCheck();
    void quickSort();
};

#endif // _MENU_


