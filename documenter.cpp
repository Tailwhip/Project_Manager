#include "documenter.h"

void Documenter::exampleFunc(){
    cout << "FUNCTION! " << endl;
    Documenter doc;
    doc.anotherFunction();
}

void Documenter::anotherFunction(){
    cout << "ANOTHER FUNCTION! " << endl;
}
