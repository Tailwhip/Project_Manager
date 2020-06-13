#include "gendoclist.h"


GenDocList::GenDocList(PmUtilities::map_str &docData) : Documenter() {
    this->docData = docData;
}

GenDocList::~GenDocList() {
    //excelObject.CallMethod("Application.Quit");
}

void GenDocList::setDocName() {
    document->setDocName(docData[DbManager::getInstance().getDocNameHead()]);
}

void GenDocList::setDocNumber() {
    document->setDocNum(docData[DbManager::getInstance().getDocNumHead()]);
}

void GenDocList::setDocRev() {
    document->setDocRev(docData[DbManager::getInstance().getDocRevHead()]);
}

void GenDocList::setApprDocNum() {
    document->setApprDocNum(docData[DbManager::getInstance().getApprDocNumHead()]);
}

void GenDocList::setMadeDate() {
    document->setMadeDate(docData[DbManager::getInstance().getDocMadeDateHead()]);
}

void GenDocList::setReviewDate() {
    document->setReviewDate(docData[DbManager::getInstance().getDocReviewDateHead()]);
}

void GenDocList::setApprDate() {
    document->setApprDate(docData[DbManager::getInstance().getDocApprDateHead()]);
}

void GenDocList::setProjNum() {
    document->setProjNum(docData[DbManager::getInstance().getProjNumberHead()]);
}

void GenDocList::setDocExt() {
    document->setDocExt(docData[DbManager::getInstance().getDocExtHead()]);
}

void GenDocList::setDocPath() {
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

    //DbManager::getInstance().addDoc(*(document->getDocData()));

    boost::filesystem::path tempPath = PmUtilities::Path::toTemplates;
    tempPath /= "xlstemplate.xlsm";

    boost::filesystem::path docPath{(*document->getDocData())[DbManager::getInstance().getDocPathHead()]};
    //std::cout << docPath.make_preferred() << std::endl;
    ///TODO: Ask to replace if the file already exists
    boost::filesystem::copy_file(tempPath, docPath, boost::filesystem::copy_option::overwrite_if_exists);
}

void GenDocList::fillDocument() {
    std::cout << "Filling the " <<
    (*document->getDocData())[DbManager::getInstance().getDocNameHead()] <<
    " document" << std::endl;
    rowsIterator = 1;
    if (excelObject.CreateInstance("Excel.Application")) {

        excelObject.CallMethod("Workbooks.Open", (*document->getDocData())[DbManager::getInstance().getDocPathHead()]);

        fillMetrics();

        std::string pathHead = DbManager::getInstance().getProjPathHead();
        std::string tableName = DbManager::getInstance().getTableName(0);
        std::string projNumHead = DbManager::getInstance().getProjNumberHead();
        std::string projNumVal = (*document->getDocData())[DbManager::getInstance().getProjNumberHead()];

        DbManager::getInstance().dataSelect(pathHead, tableName, projNumHead, projNumVal);

        boost::filesystem::path projectPath = DbManager::getInstance().dataBuffer.at(0).second;

        int groupLevel = 0;

        fillData(projectPath, groupLevel);

        excelObject.CallMethod("ActiveWorkbook.Save");
        excelObject.CallMethod("Application.Quit");
    }
}

void GenDocList::fillMetrics() {
    unsigned argsCount = 10;
    wxVariant params[argsCount] =
        {"FillMetrics", "Made Name and Surname", //xlstemplate.xlsm!
        (*document->getDocData())[DbManager::getInstance().getDocMadeDateHead()],
        "Reviewed Name and Surname",
        (*document->getDocData())[DbManager::getInstance().getDocReviewDateHead()],
        "Approved Name and Surname",
        (*document->getDocData())[DbManager::getInstance().getDocApprDateHead()],
        (*document->getDocData())[DbManager::getInstance().getDocNumHead()],
        (*document->getDocData())[DbManager::getInstance().getDocRevHead()],
        (*document->getDocData())[DbManager::getInstance().getDocNameHead()]
        };

        excelObject.CallMethod("Application.Run", argsCount, params);
        //std::cout << "Filling metrics - DONE!" << std::endl;
}

void GenDocList::fillData(boost::filesystem::path &projectPath, int groupLevel) {

    if (groupLevel < 8) { // prevention to exceed max excel grouping level
        groupLevel++;
    }

    std::cout << "Project Path: " << projectPath << "\n";

    try {
        if (boost::filesystem::exists(projectPath)) {    // does projectPath actually exist?
            if (boost::filesystem::is_regular_file(projectPath)) {  // is the projectPath a regular file?
                std::cout << projectPath << " size is " << boost::filesystem::file_size(projectPath) << '\n';
                /*
                std::string fileName = (projectPath.filename()).string();
                if (!isTemp(fileName)) {
                    //groupFile(fileName, groupLevel);
                }
                */
            } else if (boost::filesystem::is_directory(projectPath)) {     // is the projectPath a directory?
                std::cout << projectPath << " is a directory containing:\n";

                    for(auto& entry : boost::make_iterator_range(boost::filesystem::directory_iterator(projectPath), {})) {
                        std::cout << entry << "\n";
                        std::cout << "Iterator: " << rowsIterator << "\n";

                        std::string fileName = (entry.path().filename()).string();

                        if (!isTemp(fileName)) {
                            groupFile(fileName, groupLevel);
                        }

                        boost::filesystem::path newPath = projectPath;
                        newPath /= fileName;
                        fillData(newPath, groupLevel);
                    }
            } else
                std::cout << projectPath << " exists, but is neither a regular file nor a directory\n";
        } else
            std::cout << projectPath << " does not exist\n";
    } catch (const boost::filesystem::filesystem_error& ex) {
        std::cout << ex.what() << '\n';
    }
}

bool GenDocList::isTemp(std::string &fileName) const {
    if (fileName[0] == '~') {
        std::cout << fileName <<" file name first sign is: " << fileName[0] << std::endl;
        return true;
    } else
        return false;
}

void GenDocList::groupFile(const std::string &fileName, const int groupLevel) {

    unsigned argsCount = 4;

    wxVariant params[argsCount] =
        {"GroupData", fileName, std::to_string(groupLevel), std::to_string(rowsIterator)};
    excelObject.CallMethod("Application.Run", argsCount, params);

    rowsIterator++;
}

























