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

    fillMetrics();
    fillData();
}

void GenDocList::fillMetrics() {
    wxAutomationObject excelObject;
    unsigned argsCount = 10;
    wxVariant params[10] = {"FillMetrics", "Made Name and Surname", //xlstemplate.xlsm!
        (*document->getDocData())[DbManager::getInstance().getDocMadeDateHead()],
        "Reviewed Name and Surname",
        (*document->getDocData())[DbManager::getInstance().getDocReviewDateHead()],
        "Approved Name and Surname",
        (*document->getDocData())[DbManager::getInstance().getDocApprDateHead()],
        (*document->getDocData())[DbManager::getInstance().getDocNumHead()],
        (*document->getDocData())[DbManager::getInstance().getDocRevHead()],
        (*document->getDocData())[DbManager::getInstance().getDocNameHead()]};

    if (excelObject.CreateInstance("Excel.Application")) {
        excelObject.CallMethod("Workbooks.Open", (*document->getDocData())[DbManager::getInstance().getDocPathHead()]);
        excelObject.CallMethod("Application.Run", argsCount, params);
        excelObject.CallMethod("ActiveWorkbook.Save");
        excelObject.CallMethod("Application.Quit");
        std::cout << "MACRO DONE!" << std::endl;
    }
}

void GenDocList::fillData() {

    std::string pathHead = DbManager::getInstance().getProjPathHead();
    std::string tableName = DbManager::getInstance().getTableName(0);
    std::string projNumHead = DbManager::getInstance().getProjNumberHead();
    std::string projNumVal = (*document->getDocData())[DbManager::getInstance().getProjNumberHead()];

    DbManager::getInstance().dataSelect(pathHead, tableName, projNumHead, projNumVal);

    std::string p = DbManager::getInstance().dataBuffer.at(0).second;

    //boost::filesystem::path p (path);   // p reads clearer than argv[1] in the following code

    //using namespace std;
    //using namespace boost::filesystem;

    try {
        if (boost::filesystem::exists(p)) {    // does p actually exist?
            if (boost::filesystem::is_regular_file(p))       // is p a regular file?
                std::cout << p << " size is " << boost::filesystem::file_size(p) << '\n';

            else if (boost::filesystem::is_directory(p)) {     // is p a directory?
                std::cout << p << " is a directory containing:\n";

                std::copy(boost::filesystem::directory_iterator(p), boost::filesystem::directory_iterator(),  // directory_iterator::value_type
                     std::ostream_iterator<boost::filesystem::directory_entry>(std::cout, "\n"));  // is directory_entry, which is
                // converted to a path by the
                // path stream inserter
            }
            else
                std::cout << p << " exists, but is neither a regular file nor a directory\n";
        }
        else
            std::cout << p << " does not exist\n";
    }

    catch (const boost::filesystem::filesystem_error& ex) {
        std::cout << ex.what() << '\n';
    }

}





























