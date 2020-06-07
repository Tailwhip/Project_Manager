#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <iostream>
#include <string>
#include <map>
#include <memory>
#include "sqlite3.h"
#include <boost/filesystem.hpp>
#include <boost/foreach.hpp>
#include <stdexcept>
#include "pmutilities.h"

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
    void createDb();
    void openDb();
    void closeDb();
    void addProj(PmUtilities::map_str &projData);
    void addDoc(PmUtilities::map_str &docData);

    std::string getTableName(unsigned tableNumber);

/*
    SELECT CASES ANALYSIS:

        SELECT * FROM projects
            container: map<pair<string, string>, string>
            max args: 2

        SELECT * FROM projects WHERE proj_id = 14
        SELECT proj_path FROM projects WHERE proj_id BETWEEN 2 AND 5
        SELECT * FROM projects WHERE proj_path LIKE "c:/%"
            container: vector<string>
            max args: 5

        SELECT PROJ_PATH FROM PROJECTS WHERE PROJ_ID = 14
            container: string
*/

    void dataSelect(const std::string &data,
                    const std::string &tableName,
                    const std::string &identifierName = "",
                    const std::string &identifierUpperValue = "",
                    const std::string &identifierLowerValue = "",
                    const std::string &containWord = "");

    PmUtilities::db_container dataBuffer;

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

    std::string getProjIdHead();
    std::string getProjNameHead();
    std::string getProjNumberHead();
    std::string getProjPathHead();

private:
    static int writeCallback(void *NotUsed, int argc, char **argv, char **azColName);
    static int readCallback(void *data, int argc, char **argv, char **azColName);
    int bufferMax(const char* = "first");

    sqlite3 *database;
    char *zErrMsg = 0;
    int rc;
    std::string sql;
    int projId = 0;
    int docId = 0;
    std::string dbPath;

    std::vector<std::string> tablesNames {
        "PROJECTS",
        "DOCUMENTS"
    };

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
