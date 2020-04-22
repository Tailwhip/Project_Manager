#include "gendoclist.h"

GenDocList::GenDocList(PmUtilities::map_str &docData) : Documenter(){
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

void GenDocList::setDocData(){
    document->setDocData(docData);
}

void GenDocList::createFromTemp(){
    std::cout << "Creating " <<
    (*document->getDocData())[DbManager::getInstance().getDocNameHead()] <<
    " at " <<
    (*document->getDocData())[DbManager::getInstance().getDocPathHead()] <<
    " path" << std::endl;

    DbManager::getInstance().addDoc(*(document->getDocData()));


    boost::filesystem::path tempPath = PmUtilities::Path::toTemplates;
    tempPath += "/xlstemplate.xlsm";
    std::cout << "Path: " << tempPath << std::endl;
    boost::filesystem::copy_file(tempPath,
    (*document->getDocData())[DbManager::getInstance().getDocPathHead()]);

}

void GenDocList::fillDocument(){
    std::cout << "Filling the " <<
    (*document->getDocData())[DbManager::getInstance().getDocNameHead()] <<
    " document" << std::endl;


}
