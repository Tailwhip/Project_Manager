#include "docsgenerator.h"

DocsGenerator::DocsGenerator() : documenter(NULL) {

}

DocsGenerator::~DocsGenerator(){
}

void DocsGenerator::setDocumenter(Documenter* documenter){
    this->documenter = documenter;
}

std::auto_ptr<Document> DocsGenerator::getDocument(){
    return documenter->getDocument();
}

void DocsGenerator::generateDoc(){

    this->documenter->initDoc();

    this->documenter->setDocName();
    this->documenter->setDocNumber();
    this->documenter->setDocRev();
    this->documenter->setApprDocNum();
    this->documenter->setMadeDate();
    this->documenter->setReviewDate();
    this->documenter->setApprDate();
    this->documenter->setProjNum();
    this->documenter->setDocExt();
    this->documenter->setDocPath();
    this->documenter->createDocument();
    this->documenter->fillDocument();
}
