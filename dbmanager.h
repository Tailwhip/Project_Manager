#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <iostream>
#include <string>
#include <map>
#include <memory>
#include "sqlite3.h"
#include <boost/filesystem.hpp>

class DbManager // Singleton
{
private:
    DbManager();
    DbManager(const DbManager &);
    DbManager& operator=(const DbManager &);
    ~DbManager();
public:
    static DbManager& getInstance();
    static DbManager instance;
    void createDb(std::vector<std::string> &);
    void openDb();
    void closeDb();
    void addProj(std::map<std::string, std::string> &);
    void addDoc(std::map<std::string, std::string> &);

    std::string getDocIdHead();
    std::string getDocNameHead();
    std::string getDocNumHead();
    std::string getDocRevHead();
    std::string getApprDocNumHead();
    std::string getDocMadeDateHead();
    std::string getDocReviewDateHead();
    std::string getDocApprDateHead();
    std::string getDocExtHead();
    std::string getDocPathHead();
    std::string getProjNumberHead();

private:
    static int writeCallback(void *, int, char **, char **);
    static int readCallback(void *, int, char **, char **);
    void readFromDb();
    sqlite3 *database;
    char *zErrMsg = 0;
    int rc;
    std::string sql;
    unsigned projId = 0;
    unsigned docId = 0;
    std::string dbPath;
    std::map<std::string, std::string> dataBuffer;

    std::string headDocId = "DOC_ID";
    std::string headDocName = "DOC_NAME";
    std::string headDocNumber = "DOC_NUMBER";
    std::string headDocRevision = "DOC_REV";
    std::string headApprDocNumber = "APR_DOC_NUM";
    std::string headDocMadeDate = "DOC_MADE_DATE";
    std::string headDocReviewDate = "DOC_REVIEW_DATE";
    std::string headDocApprDate = "DOC_APPR_DATE";
    std::string headDocExt = "DOC_EXT";
    std::string headDocPath = "DOC_PATH";

    std::string headProjId = "PROJ_ID";
    std::string headProjName = "PROJ_NAME";
    std::string headProjNumber = "PROJ_NUM";
    std::string headProjPath = "PROJ_PATH";
};
#endif // DBMANAGER_H
