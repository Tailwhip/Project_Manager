#include "menu.h"

/*-------------------------PUBLIC------------------------------*/
Menu::Menu(vector<string> & pointsNames, vector<void_fnc_ptr> & pointsFunctions){
    this->pointsNames = pointsNames;
    this->pointsCount = pointsNames.size();
    this->pointsFunctions = pointsFunctions;
    fillPoints();
}

Menu::~Menu(){
    cout << "\n\n\n\nSeek and destroy!" << endl;
}

void Menu::show(){
    do {
        refresh();
        choiceNum = static_cast<unsigned>(getch());
        castFunctions();
    } while (choiceNum != 27);
}

void Menu::refresh() {
    //system("cls");
    cout << "MENU: " << endl;
    for (unsigned i = 0; i < pointsNames.size(); i++){
        cout << i + 1 << ". " << pointsNames[i] << endl;
    }
}

void Menu::addPoints(const string & pointName, unsigned position){
    if (position > pointsCapacity || position > this->pointsNames.size()){
        cout << "The position must be within the range!" << endl;
        return;
    } else if (position == 0) {
        pointsNames.push_back(pointName);
        pointsFunctions.push_back(&emptyFunction);
    } else {
        vector<string>::iterator it1 = pointsNames.begin();
        vector<void_fnc_ptr>::iterator it2 = pointsFunctions.begin();
        it1 += position - 1;
        it2 += position - 1;
        pointsNames.insert(it1, pointName);
        pointsFunctions.insert(it2, &emptyFunction);
    }
}

void Menu::addPoints(vector<string> & pointsNames, unsigned position){
    vector<string>::iterator it1 = this->pointsNames.begin();
    vector<void_fnc_ptr>::iterator it2 = this->pointsFunctions.begin();
    if (position > pointsCapacity || position > this->pointsNames.size()){
        cout << "The position must be within the range!" << endl;
        return;
    } else if (position == 0) {
        it1 = this->pointsNames.end();
        it2 = this->pointsFunctions.end();
        this->pointsNames.insert(it1, pointsNames.begin(), pointsNames.end());
        pointsFunctions.insert(it2, pointsNames.size(), &emptyFunction);
    } else {
        it1 += position - 1;
        it2 += position - 1;
        this->pointsNames.insert(it1, pointsNames.begin(), pointsNames.end());
        this->pointsFunctions.insert(it2, pointsNames.size(), &emptyFunction);
    }
}

void Menu::addFunctionality(void_fnc_ptr functionality, unsigned position) {
    vector<void_fnc_ptr>::iterator it = this->pointsFunctions.begin();
    it += position - 1;

    if (position > pointsCapacity || position > this->pointsNames.size() || position == 0){
        cout << "The position must be within the range!" << endl;
        return;
    } else if (pointsFunctions[position-1] == &emptyFunction){
        this->pointsFunctions.insert(it, functionality);
    } else {
        cout << "There's already some function! Want to replace?" << endl;
        if (confirmCheck()){
            this->pointsFunctions.insert(it, functionality);
        };
    }
}

void sortAlpha(){

}

/*-------------------------PRIVATE------------------------------*/
void Menu::fillPoints(){
    for (unsigned i = 0; i < pointsNames.size(); i++){
        points.push_back({&pointsNames.at(i), pointsFunctions.at(i), i+1});
        cout << "Names: " << *points[i].name << endl;
        cout << "Functions: " << endl;
        points[i].functionality();
        cout << "Positions: " << points[i].position << endl;
    }
}


void Menu::castFunctions(){
    for (unsigned i = 0; i < pointsNames.size(); i++){
        if (choiceNum == (i + 49)){
            pointsFunctions[i]();
        }
    }
}

void Menu::emptyFunction(){
    cout << "This is a tasty burger!" << endl;
}

bool Menu::confirmCheck(){
    char confirm = 0;
    do {
        confirm = getch();
        if (confirm== 13){
            cout << "Confirmed" << endl;
            return true;
        }
    }while(confirm != 27);
    cout << "Rejected" << endl;
    return false;
}
