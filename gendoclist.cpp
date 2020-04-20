#include "gendoclist.h"

GenDocList::GenDocList(std::map<std::string, std::string>& docData) : Documenter(){
    this->docData = docData;
}

GenDocList::~GenDocList(){

}

void GenDocList::setDocName(){
    document->setDocName(docData[DbManager::getInstance().getDocNameHead()]);
}

void GenDocList::setDocNumber(){
    document->setDocNum(docData[DbManager::getInstance().getDocNumHead()]);
}

void GenDocList::setDocRev(){
    document->setDocRev(docData[DbManager::getInstance().getDocRevHead()]);
}

void GenDocList::setApprDocNum(){
    document->setApprDocNum(docData[DbManager::getInstance().getApprDocNumHead()]);
}

void GenDocList::setMadeDate(){
    document->setMadeDate(docData[DbManager::getInstance().getDocMadeDateHead()]);
}

void GenDocList::setReviewDate(){
    document->setReviewDate(docData[DbManager::getInstance().getDocReviewDateHead()]);
}

void GenDocList::setApprDate(){
    document->setApprDate(docData[DbManager::getInstance().getDocApprDateHead()]);
}

void GenDocList::setProjNum(){
    document->setProjNum(docData[DbManager::getInstance().getProjNumberHead()]);
}

void GenDocList::setDocExt(){
    document->setDocExt(docData[DbManager::getInstance().getDocExtHead()]);
}

void GenDocList::setDocPath(){
    document->setDocPath(docData[DbManager::getInstance().getDocPathHead()]);
}

void GenDocList::createDocument(){
    document->createDocument();
}

void GenDocList::fillDocument(){
    document->fillDocument();
}
