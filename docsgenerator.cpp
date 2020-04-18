#include "docsgenerator.h"

DocsGenerator::DocsGenerator() : docsCreator(nullptr) {

}

DocsGenerator::~DocsGenerator(){
}

void DocsGenerator::setDocumenter(Documenter* docsCreator){
    this->docsCreator = docsCreator;
}

std::auto_ptr<Document> DocsGenerator::getDocument(){
    return docsCreator->getDocument();
}

void DocsGenerator::generateDoc(){
    this->docsCreator->setDocName();
    this->docsCreator->setDocNumber();
    this->docsCreator->setDocRev();
    this->docsCreator->setApprDocNum();
    this->docsCreator->setMadeDate();
    this->docsCreator->setReviewDate();
    this->docsCreator->setApprDate();
    this->docsCreator->setProjNum();
    this->docsCreator->setDocExt();
    this->docsCreator->setDocPath();
    this->docsCreator->createDocument();
    this->docsCreator->fillDocument();
}
