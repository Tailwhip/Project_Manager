#include "dbmanager.h"

DbManager DbManager::instance;

DbManager::DbManager(){
    dbPath = "data/projects.db";
}

DbManager::~DbManager(){
    closeDb();
}

void DbManager::createDb() {
    if (!boost::filesystem::exists(dbPath)) {
        std::cout << "Creating Database ..." << std::endl;
        rc = sqlite3_open(dbPath.c_str(), &database);

        sql = "CREATE TABLE PROJECTS("
            + headProjId + " INTEGER PRIMARY KEY,"
            + headProjName + " TEXT,"
            + headProjNumber + " TEXT,"
            + headProjPath + " TEXT);";

        rc = sqlite3_exec(database, sql.c_str(), writeCallback, NULL, &zErrMsg);

        sql = "CREATE TABLE DOCUMENTS("
            + headDocId + " INTEGER PRIMARY KEY,"
            + headDocName + " TEXT,"
            + headDocNumber + " TEXT,"
            + headDocRevision + " TEXT,"
            + headApprDocNumber + " TEXT,"
            + headDocMadeDate + " TEXT,"
            + headDocReviewDate + " TEXT,"
            + headDocApprDate + " TEXT,"
            + headProjNumber + " TEXT,"
            + headDocExt + " TEXT,"
            + headDocPath + " TEXT);";

        rc = sqlite3_exec(database, sql.c_str(), writeCallback, NULL, &zErrMsg);

        if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
        } else fprintf(stdout, "Database created successfully\n");
    } else {
        std::cout << "Database already exists! Opening the database..." << std::endl;
        openDb();
        return;
    }
}

void DbManager::openDb() {
    if (boost::filesystem::exists(dbPath)) {
        rc = sqlite3_open(dbPath.c_str(), &database);
        if (rc)
          fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(database));
        else
          fprintf(stdout, "Opened database successfully\n");

        // set the document last db id number
        sql = "SELECT " + headDocId + " FROM DOCUMENTS";
        rc = sqlite3_exec(database, sql.c_str(), readCallback, NULL, &zErrMsg);
        docId = bufferMax("second");
        dataBuffer.clear();

        // set the project last db id number
        sql = "SELECT " + headProjId + " FROM PROJECTS";
        rc = sqlite3_exec(database, sql.c_str(), readCallback, NULL, &zErrMsg);
        projId = bufferMax("second");

    } else {
        std::cout << "There's no database to open. Create one first!" << std::endl;
    }
}

void DbManager::closeDb() {
    sqlite3_close(database);
}

void DbManager::addProj(PmUtilities::map_str &projData) {

    // prevention to adding a project that already exists
    dataSelect(headProjNumber, tablesNames.at(0));
    BOOST_FOREACH(PmUtilities::db_container::value_type &i, dataBuffer) {
        if (projData[headProjNumber] == i.second) {
            wxString message;
            message.Printf(wxT("A project with this number already exists"));
            wxMessageBox(message);
            return;
        }
    }

    projId++;
    rc = sqlite3_open(dbPath.c_str(), &database);
    sql = "INSERT INTO "+ tablesNames.at(0) + " ("
        + headProjId + ","
        + headProjName + ","
        + headProjNumber + ","
        + headProjPath + ") VALUES ('"
        + std::to_string(projId) + "','"
        + projData[headProjName] + "','"
        + projData[headProjNumber] + "','"
        + projData[headProjPath] + "');";

    rc = sqlite3_exec(database, sql.c_str(), writeCallback, NULL, &zErrMsg);

    //wxString message;
    //message.Printf(wxT("Added Project:  %s"), sql.c_str());
    //wxMessageBox(message);
}

void DbManager::addDoc(PmUtilities::map_str &docData) {

    // prevention to adding a document that already exists
    dataSelect(headDocNumber, tablesNames.at(1));
    BOOST_FOREACH(PmUtilities::db_container::value_type &i, dataBuffer) {
        if (docData[headDocNumber] == i.second) {
            wxString message;
            message.Printf(wxT("The document with this number already exists in database"));
            wxMessageBox(message);
            return;
        }
    }

    docId++;
    rc = sqlite3_open(dbPath.c_str(), &database);
    sql = "INSERT INTO " + tablesNames.at(1) + " ("
        + headDocId + ","
        + headDocName + ","
        + headDocNumber + ","
        + headDocRevision + ","
        + headApprDocNumber + ","
        + headDocMadeDate + ","
        + headDocReviewDate + ","
        + headDocApprDate + ","
        + headProjNumber + ","
        + headDocExt + ","
        + headDocPath + ") VALUES ('"
        + std::to_string(docId) + "','"
        + docData[headDocName] + "','"
        + docData[headDocNumber] + "','"
        + docData[headDocRevision] + "','"
        + docData[headApprDocNumber] + "','"
        + docData[headDocMadeDate] + "','"
        + docData[headDocReviewDate] + "','"
        + docData[headDocApprDate] + "','"
        + docData[headProjNumber] + "','"
        + docData[headDocExt] + "','"
        + docData[headDocPath] + "');";

    rc = sqlite3_exec(database, sql.c_str(), writeCallback, NULL, &zErrMsg);
    /*
    wxString message;
    message.Printf(wxT("Document:  %s  added successfully!"), sql.c_str());
    wxMessageBox(message);
    */
}

void DbManager::dataSelect(const std::string &data,
                           const std::string &tableName,
                           const std::string &identifierName,
                           const std::string &identifierUpperValue,
                           const std::string &identifierLowerValue,
                           const std::string &containWord) {

    rc = sqlite3_open(dbPath.c_str(), &database);
    if (identifierName == "" && identifierUpperValue == "" &&
        identifierLowerValue == "" && containWord == "") {
                    sql = "SELECT " + data + " FROM " + tableName;
    } else if (identifierName != "" && identifierUpperValue != "" &&
               identifierLowerValue == "" && containWord == "") {
                    sql = "SELECT " + data + " FROM " + tableName + " WHERE "
                    + identifierName + " = \"" + identifierUpperValue + "\"";
    } else if (identifierName != "" && identifierUpperValue != "" &&
               identifierLowerValue != "" && containWord == "") {
                    sql = "SELECT " + data + " FROM " + tableName + " WHERE "
                    + identifierName + " BETWEEN " + identifierUpperValue + " AND "
                    + identifierUpperValue;
    } else if (identifierName != "" && identifierUpperValue == "" &&
               identifierLowerValue == "" && containWord != "") {
                    sql = "SELECT " + data + " FROM " + tableName + " WHERE "
                    + identifierName + " LIKE """ + containWord + """";
    } else {
        std::cout << "Wrong data select! " << std::endl;
    }
    //std::cout << sql << std::endl;
    rc = sqlite3_exec(database, sql.c_str(), readCallback, NULL, &zErrMsg);
}

int DbManager::writeCallback(void *NotUsed, int argc, char **argv, char **azColName) {
    for(unsigned i = 0; i < argc; i++) {
        //printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int DbManager::readCallback(void *data, int argc, char **argv, char **azColName) {
    //fprintf(stderr, "%s: ", (const char*)data);
    std::cout << "Reading data ..." << std::endl;
    DbManager::getInstance().dataBuffer.clear();

    for(unsigned i = 0; i < argc; i++) {
        std::cout << "[read] azColName: " << azColName[i] << std::endl;
        std::cout << "[read] argv: " << argv[i] << std::endl;
        DbManager::getInstance().dataBuffer.push_back(std::make_pair(azColName[i], argv[i]));
    }

    return 0;
}

// a function to get the maximum number from data buffer
int DbManager::bufferMax(const char* position) {
    int result = 0;
    int compVar = 0;
    try {
        if (position == "first") { // returns the first of pair of the data
            BOOST_FOREACH(PmUtilities::db_container::value_type &i, dataBuffer) {
                compVar = std::stoi(i.first);
                if (compVar > result) result = compVar;
            }
            return result;

        } else if (position == "second") { // returns the second of pair of the data
            BOOST_FOREACH(PmUtilities::db_container::value_type &i, dataBuffer) {
                compVar = std::stoi(i.second);
                if (compVar > result) result = compVar;
            }
            return result;

        } else std::cout<<"Wrong max function argument!" << std::endl;
            return 0;

    } catch (std::invalid_argument& e) {
        throw std::invalid_argument("Wrong value for comparison!");
        //std::cout<<"Wrong value for comparison!" << std::endl;
    } catch (std::out_of_range& e) {
        throw std::out_of_range("Comparison value out of range!");
        //std::cout<<"Comparison value out of range!" << std::endl;
    }
}


std::string DbManager::getTableName(unsigned tableNumber) {
    return tablesNames.at(tableNumber);
}

DbManager& DbManager::getInstance() {
    return instance;
}

std::string DbManager::getDocIdHead() {
    return this->headDocId;
}

std::string DbManager::getDocNameHead() {
    return this->headDocName;
}

std::string DbManager::getDocNumHead() {
    return this->headDocNumber;
}

std::string DbManager::getDocRevHead() {
    return this->headDocRevision;
}

std::string DbManager::getApprDocNumHead() {
    return this->headApprDocNumber;
}

std::string DbManager::getDocMadeDateHead() {
    return this->headDocMadeDate;
}

std::string DbManager::getDocReviewDateHead() {
    return this->headDocReviewDate;
}

std::string DbManager::getDocApprDateHead() {
    return this->headDocApprDate;
}

std::string DbManager::getDocExtHead() {
    return this->headDocExt;
}

std::string DbManager::getDocPathHead() {
    return this->headDocPath;
}

std::string DbManager::getProjIdHead() {
    return this->headProjId;
}

std::string DbManager::getProjNameHead() {
    return this->headProjName;
}

std::string DbManager::getProjNumberHead() {
    return this->headProjNumber;
}

std::string DbManager::getProjPathHead() {
    return this->headProjPath;
}
