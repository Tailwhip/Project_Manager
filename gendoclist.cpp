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

void GenDocList::setDocData() {
    document->setDocData(docData);
}

void GenDocList::createFromTemp() {

    std::cout << "Creating " <<
    (*document->getDocData())[DbManager::getInstance().getDocNameHead()] <<
    " at " <<
    (*document->getDocData())[DbManager::getInstance().getDocPathHead()] <<
    " path" << std::endl;

    DbManager::getInstance().addDoc(*(document->getDocData()));

    boost::filesystem::path tempPath = PmUtilities::Path::toTemplates;
    tempPath /= "xlstemplate.xlsm";
    //std::cout << tempPath.make_preferred() << std::endl;

    boost::filesystem::path docPath{(*document->getDocData())[DbManager::getInstance().getDocPathHead()]};
    std::cout << docPath.make_preferred() << std::endl;
    ///TODO: Ask to replace if the file already exists
    boost::filesystem::copy_file(tempPath, docPath, boost::filesystem::copy_option::overwrite_if_exists);
}

void GenDocList::fillDocument() {
    std::cout << "Filling the " <<
    (*document->getDocData())[DbManager::getInstance().getDocNameHead()] <<
    " document" << std::endl;

    //boost::filesystem::ofstream ofs{(*document->getDocData())[DbManager::getInstance().getDocPathHead()]};

    //wxExcelApplication app = wxExcelApplication::GetInstance((*document->getDocData())[DbManager::getInstance().getDocPathHead()]);

    wxAutomationObject excelObject;
    unsigned argsCount = 10;
    wxVariant params[10] = {"xlstemplate.xlsm!FillMetrics", "Made Name and Surname",
        (*document->getDocData())[DbManager::getInstance().getDocMadeDateHead()],
        "Reviewed Name and Surname",
        (*document->getDocData())[DbManager::getInstance().getDocReviewDateHead()],
        "Approved Name and Surname",
        (*document->getDocData())[DbManager::getInstance().getDocApprDateHead()],
        (*document->getDocData())[DbManager::getInstance().getDocNumHead()],
        (*document->getDocData())[DbManager::getInstance().getDocRevHead()],
        (*document->getDocData())[DbManager::getInstance().getDocNameHead()]};

  if (excelObject.GetInstance("Excel.Application")) {
        excelObject.CallMethod( "Application.Run", argsCount, params);
        std::cout << "MACRO DONE!" << std::endl;
  }

}
































