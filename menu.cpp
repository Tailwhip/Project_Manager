#include "menu.h"

/*-------------------------PUBLIC-----------------------------------------------------------------------------------*/

Menu::Menu(vector<string> & pointsNames, vector<void_fnc_ptr> & pointsFunctions){
    fillPoints(pointsNames, pointsFunctions);
}

Menu::~Menu(){
    cout << "\n\n\n\nSeek and destroy!" << endl;
}

void Menu::show() {
    do {
        refresh();
        choiceNum = static_cast<unsigned>(getch()); // get keyboard button
        castFunctions();
    } while (choiceNum != 27); // until escape button is pushed
}

void Menu::refresh() {
    system("cls");
    cout << "MENU: " << endl;
    // show point by point
    for (unsigned i = 0; i < points.size(); i++) {
        cout << i + 1 << ". " << points[i].name << endl;
    }
}

void Menu::addPoints(const string & pointName, void_fnc_ptr functionality, unsigned position) {
    // check if the position is within the range of menu points
    if (position > pointsCapacity || position > points.size() + 1){
        cout << "The position must be within the range!" << endl;
        return;
    }
    // 1st condition - no function / no position
    // put emptyFunction at the end of the points vector
    if (functionality == nullptr && position == 0) {
        points.push_back({pointName, &emptyFunction});
    }// 2nd condition - no function / position
    // put emptyFunction at specified position in the points vector
    else if (functionality == nullptr && position != 0) {
        it = points.begin() + position - 1;
        points.insert(it, {pointName, &emptyFunction});
    }// 3rd condition - function / no position
    // put functionality at the end of the points vector
    else if (functionality != nullptr && position == 0){
        points.push_back({pointName, functionality});
    } // 4th condition - function / position
    // put functionality at the end of the points vector
    else if (functionality != nullptr && position != 0){
        it = points.begin() + position - 1;
        points.insert(it, {pointName, functionality});
    }
}

void Menu::addPoints(vector<string> & pointsNames, vector<void_fnc_ptr> pointsFunctions,
                     unsigned position){
    // check if the position is within the range of menu points
    if (position > pointsCapacity || position > points.size() + 1){
        cout << "The position must be within the range!" << endl;
        return;
    }

    // check if there's the same number of points names and it's functions
    if (!pointsFunctions.empty())
        if (pointsNames.size() != pointsFunctions.size()) {
            cout << "All points have to own their functions!" << endl;
            exit(0);
        }

    // a temporary buffer of adding points
    vector<menu_point> pointsBuffer;
    // 1st condition - no functions / no positions
    if (pointsFunctions.empty() && position == 0) {
        // fills the temporary buffer with the pointsNames and emptyFunctions
        for (unsigned i = 0; i < pointsNames.size(); i++)
            pointsBuffer.push_back({pointsNames.at(i), &emptyFunction});
        it = points.end();
        // insert the temporary buffer at the end of  bool operator()(const menu_point* left, const menu_point* right) const {return left < right;}points vector
        points.insert(it, pointsBuffer.begin(), pointsBuffer.end());
    } // 2nd condition - functions / no positions
    else if (!pointsFunctions.empty() && position == 0) {
        // put new point names and functions into the temporary buffer
        // if any of pointsFunctions element is empty then put the emptyFunction into the temporary buffer
        for (unsigned i = 0; i < pointsNames.size(); i++) {
            if (pointsFunctions.at(i) != nullptr)
                pointsBuffer.push_back({pointsNames.at(i), pointsFunctions.at(i)});
            else
                pointsBuffer.push_back({pointsNames.at(i), &emptyFunction});
        }
        it = points.end();
        // insert the temporary buffer at the end of points vector
        points.insert(it, pointsBuffer.begin(), pointsBuffer.end());
    } // 3rd condition - no functions / positions
    // (1st condition with adding points at specified position)
    else if (pointsFunctions.empty() && position != 0) {
         for (unsigned i = 0; i < pointsNames.size(); i++)
            pointsBuffer.push_back({pointsNames.at(i), &emptyFunction});
        it = points.begin() + position - 1;
        points.insert(it, pointsBuffer.begin(), pointsBuffer.end());
    } // 4th condition - functions / positions
    // (2nd condition with adding points at specified position)
    else if (!pointsFunctions.empty() && position != 0) {
        for (unsigned i = 0; i < pointsNames.size(); i++) {
            if (pointsFunctions.at(i) != nullptr)
                pointsBuffer.push_back({pointsNames.at(i), pointsFunctions.at(i)});
            else
                pointsBuffer.push_back({pointsNames.at(i), &emptyFunction});
        }
        it = points.begin() + position - 1;
        points.insert(it, pointsBuffer.begin(), pointsBuffer.end());
    }
}

void Menu::addFunctionality(void_fnc_ptr functionality, unsigned position) {
    // checking if the position is within the range of menu points
    if (position > pointsCapacity || position > points.size() || position == 0){
        cout << "The position must be within the range!" << endl;
        return;
    }
    // if the position of the function to be added already have a function ask if it should be replaced
    if (points[position-1].functionality != &emptyFunction) {
        cout << "There's already some function! Want to replace?" << endl;
        if (confirmCheck())
            points[position-1].functionality = functionality;
    } else points[position-1].functionality = functionality;
}

void Menu::sortAlpha() {
    std::sort(points.begin(), points.end(), Menu::sortFunction);
}

/*-------------------------PRIVATE--------------------------------------------------------------------------------------------*/

void Menu::fillPoints(vector<string> & pointsNames, vector<void_fnc_ptr> & pointsFunctions){
    for (unsigned i = 0; i < pointsNames.size(); i++) {
    // check if there's the same number of points names and it's functions
    if (!pointsFunctions.empty())
        if (pointsNames.size() != pointsFunctions.size()) {
            cout << "All points have to own their functions!" << endl;
            exit(0);
        }
    // fill the points vector with points names and if is not empty then also with the points functions
    // if its empty then use an empty function
        if (pointsFunctions.at(i) == nullptr)
            points.push_back({pointsNames.at(i), &emptyFunction});
        else
            points.push_back({pointsNames.at(i), pointsFunctions.at(i)});
    }
}

void Menu::castFunctions() {
    // look for the function of the pushed button and cast it
    for (unsigned i = 0; i < points.size(); i++){
        if (choiceNum == (i + 49)){
            points[i].functionality();
        }
    }
}

void Menu::emptyFunction() {
    cout << "This is a tasty burger!" << endl;
}

bool Menu::confirmCheck(){
    char confirm = 0;
    do {
        confirm = getch();
        // look for an enter button to be pushed
        if (confirm== 13) {
            cout << "Confirmed" << endl;
            return true;
        }
    } while(confirm != 27); // until escape button is pushed
    cout << "Rejected" << endl;
    return false;
}
