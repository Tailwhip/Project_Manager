#include "document.h"

Document::Document(){

}

Document::~Document(){

}

std::string Document::getDocName(){
    return docName;
}

std::string Document::getDocNum(){
    return docNum;
}

std::string Document::getDocRev(){
    return docRev;
}

std::string Document::getApprDocNum(){
    return apprDocNum;
}

std::string Document::getMadeDate(){
    return madeDate;
}

std::string Document::getReviewDate(){
    return reviewDate;
}

std::string Document::getApprDate(){
    return apprDate;
}

std::string Document::getProjNum(){
    return projNum;
}

std::string Document::getDocExt(){
    return docExt;
}

std::string Document::getDocPath(){
    return docPath;
}

void Document::setDocName(const std::string& docName){
    this->docName = docName;
}

void Document::setDocNum(const std::string& docNum){
    this->docNum = docNum;
}

void Document::setDocRev(const std::string& docRev){
    this->docRev = docRev;
}

void Document::setApprDocNum(const std::string& apprDocNum){
    this->apprDocNum = apprDocNum;
}

void Document::setMadeDate(const std::string& reviewDate){
    this->reviewDate = reviewDate;
}

void Document::setReviewDate(const std::string& madeDate){
    this->madeDate = madeDate;
}

void Document::setApprDate(const std::string& apprDate){
    this->apprDate = apprDate;
}

void Document::setDocExt(const std::string& docExt){
    this->docExt = docExt;
}

void Document::setProjNum(const std::string& projNum){
    this->projNum = projNum;
}

void Document::setDocPath(const std::string& docPath){
    this->docPath = docPath;
}

void Document::createDocument(){
    std::cout << "CREATE DOCUMENT" << std::endl;
}

void Document::fillDocument(){
    std::cout << "FILL DOCUMENT" << std::endl;
}
