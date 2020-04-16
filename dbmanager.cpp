#include "dbmanager.h"

DbManager DbManager::instance;

DbManager::DbManager(){
    dbPath = "data/projects.db";
    openDb();
}

DbManager::~DbManager(){
    closeDb();
}

void DbManager::createDb(std::vector<std::string> &projectData) {

    if ( !boost::filesystem::exists(dbPath.c_str())) {
        std::cout << "Can't find my file!" << std::endl;
        return;
    }
    rc = sqlite3_open(dbPath.c_str(), &database);

    sql = "CREATE TABLE PROJECTS("
    + headProjId + "INTEGER PRIMARY KEY,"
    + headProjName + "TEXT,"
    + headProjNumber + "TEXT,"
    + headProjPath + "TEXT);";

    rc = sqlite3_exec(database, sql.c_str(), writeCallback, NULL, &zErrMsg);

    sql = "CREATE TABLE DOCUMENTS("
    + headDocId + "INTEGER PRIMARY KEY,"
    + headDocName + "TEXT,"
    + headDocNumber + "TEXT,"
    + headDocRevision + "TEXT,"
    + headApprDocNumber + "TEXT,"
    + headDocMadeDate + "TEXT,"
    + headDocReviewDate + "TEXT,"
    + headDocApprDate + "TEXT,"
    + headProjNumber + "TEXT,"
    + headDocExt + "TEXT,"
    + headDocPath + "TEXT);";

    rc = sqlite3_exec(database, sql.c_str(), writeCallback, NULL, &zErrMsg);

   if (rc != SQLITE_OK) {
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   } else
      fprintf(stdout, "Table created successfully\n");
}

void DbManager::openDb() {
    rc = sqlite3_open("data/projects.db", &database);

    if (rc)
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(database));
    else
      fprintf(stdout, "Opened database successfully\n");

    sql = "SELECT " + headDocId + " FROM PROJECTS";
    rc = sqlite3_exec(database, sql.c_str(), writeCallback, NULL, &zErrMsg);
    docId = std::stoi(dataBuffer["0"]);
    std::cout << "DocID: " << docId << std::endl;
    sql = "SELECT " + headProjId + " FROM PROJECTS";
    rc = sqlite3_exec(database, sql.c_str(), writeCallback, NULL, &zErrMsg);
    projId = std::stoi(dataBuffer["0"]);
}

void DbManager::closeDb() {
    sqlite3_close(database);
}

void DbManager::addDoc(std::map<std::string, std::string> & docData) {
    docId++;
    sql = "INSERT INTO DOCUMENTS("
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
    + headDocPath + ") VALUES ("
    + std::to_string(docId) + ","
    + docData[headDocName] + ","
    + docData[headDocNumber] + ","
    + docData[headDocRevision] + ","
    + docData[headApprDocNumber] + ","
    + docData[headDocMadeDate] + ","
    + docData[headDocReviewDate] + ","
    + docData[headDocApprDate] + ","
    + docData[headProjNumber] + ","
    + docData[headDocExt] + ","
    + docData[headDocPath] + ");";

    rc = sqlite3_exec(database, sql.c_str(), writeCallback, NULL, &zErrMsg);

    wxString message;
    message.Printf(wxT("Added document:  %s"), sql.c_str());
    wxMessageBox(message);
}

void DbManager::addProj(std::map<std::string, std::string> & projData) {
    projId++;
    sql = "INSERT INTO PROJECTS ("
    + headProjId + ","
    + headProjName + ","
    + headProjNumber + ","
    + headProjPath + ")"
    ") VALUES ( '"
    + std::to_string(projId) + ","
    + projData[headProjName] + ","
    + projData[headProjNumber] + ","
    + projData[headProjPath] + ");";

    rc = sqlite3_exec(database, sql.c_str(), writeCallback, NULL, &zErrMsg);

    wxString message;
    message.Printf(wxT("Added Project:  %s"), sql.c_str());
    wxMessageBox(message);
}


DbManager& DbManager::getInstance(){
    return instance;
}

std::string DbManager::getDocIdHead(){
    return this->headDocId;
}

std::string DbManager::getDocNameHead(){
    return this->headDocName;
}

std::string DbManager::getDocNumHead(){
    return this->headDocNumber;
}

std::string DbManager::getDocRevHead(){
    return this->headDocRevision;
}

std::string DbManager::getApprDocNumHead(){
    return this->headApprDocNumber;
}

std::string DbManager::getDocMadeDateHead(){
    return this->headDocMadeDate;
}

std::string DbManager::getDocReviewDateHead(){
    return this->headDocReviewDate;
}

std::string DbManager::getDocApprDateHead(){
    return this->headDocApprDate;
}

std::string DbManager::getDocExtHead(){
    return this->headDocExt;
}

std::string DbManager::getDocPathHead(){
    return this->headDocPath;
}

std::string DbManager::getProjNumberHead(){
    return this->headProjNumber;
}

int DbManager::writeCallback(void *NotUsed, int argc, char **argv, char **azColName) {
    int i;
    for(i = 0; i<argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int DbManager::readCallback(void *data, int argc, char **argv, char **azColName) {
    int i;
    fprintf(stderr, "%s: ", (const char*)data);
    for(i = 0; i<argc; i++){
        DbManager::getInstance().dataBuffer[azColName[i]] = argv[i]; // cast??
    }
    printf("\n");
    return 0;
}

void DbManager::readFromDb() {

}
