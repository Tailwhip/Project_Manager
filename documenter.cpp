#include "documenter.h"

Documenter::Documenter() {

}

Documenter::~Documenter() {

}

std::auto_ptr<Document> Documenter::getDocument() {
    return document;
}

void Documenter::initDoc() {
    document.reset(new Document);
}
