#include "gendoclist.h"

GenDocList::GenDocList(std::map<std::string, std::string>& docData) : Documenter(){
    this->docData = docData;
}

GenDocList::~GenDocList(){

}

void GenDocList::setDocName(){
    document->setDocName(docData.at(DbManager::getInstance().getDocNameHead()));
}

void GenDocList::setDocNumber(){
    document->setDocNum(docData.at(DbManager::getInstance().getDocNumHead()));
}

void GenDocList::setDocRev(){
    document->setDocRev(docData.at(DbManager::getInstance().getDocRevHead()));
}

void GenDocList::setApprDocNum(){
    document->setApprDocNum(docData.at(DbManager::getInstance().getApprDocNumHead()));
}

void GenDocList::setMadeDate(){
    document->setMadeDate(docData.at(DbManager::getInstance().getDocMadeDateHead()));
}

void GenDocList::setReviewDate(){
    document->setReviewDate(docData.at(DbManager::getInstance().getDocReviewDateHead()));
}

void GenDocList::setApprDate(){
    document->setApprDate(docData.at(DbManager::getInstance().getDocApprDateHead()));
}

void GenDocList::setProjNum(){
    document->setProjNum(docData.at(DbManager::getInstance().getProjNumberHead()));
}

void GenDocList::setDocExt(){
    document->setDocExt(docData.at(DbManager::getInstance().getDocExtHead()));
}

void GenDocList::setDocPath(){
    document->setDocPath(docData.at(DbManager::getInstance().getDocPathHead()));
}

void GenDocList::createDocument(){
    document->createDocument();
}

void GenDocList::fillDocument(){
    document->fillDocument();
}
