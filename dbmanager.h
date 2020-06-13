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

/// A class created as a singleton. Can be considered as an API to the application's database.
class DbManager // Singleton
{
private:
    /// Constructor
    DbManager();
    //DbManager(const DbManager &);
    //DbManager& operator=(const DbManager &);
    /// Destructor
    ~DbManager();
public:
    /// Function that allows to work on class.
    ///
    /// Any other member or variable should be invoked through this.
    static DbManager& getInstance();
    /// Creates SQLite db for the application.
    void createDb();
    /// Opens SQLite db created for the application.
    void openDb();
    /// Closes SQLite db created for the application.
    void closeDb();
    /// Allows to put a new project data into the SQLite db.
    void addProj(PmUtilities::map_str &projData);
    /// Allows to put a new document data into the SQLite db.
    void addDoc(PmUtilities::map_str &docData);
    /// Is used for getting a table name from *tablesNames* list
    /// @see tablesNames
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
    /// Wrapper for the sql SELECT operation
    ///
    /// is used to get any data from the SQLite db
    /// depending on used parameters the structure of querry are:
    /// SELECT data FROM tableName
    /// SELECT data FROM tableName WHERE identifierName = identifierUpperValue
    /// SELECT data FROM tableName WHERE identifierName BETWEEN identifierUpperValue AND identifierLowerValue
    /// SELECT data FROM tableName WHERE identifierName LIKE containWord
    /// @param data                 name of data that you want to get
    /// @param tableName            name of table that you are reaching for
    /// @param identifierName       name of the identifier for the data placement in the table
    /// @param identifierUpperValue value of the identifier for locating the data or an upper value
    ///                             if you are looking for the data between some values range
    /// @param identifierLowerValue lower value if you are looking for the data between some values range
    /// @param containWord          a word that the data you are looking for contains
    void dataSelect(const std::string &data,
                    const std::string &tableName,
                    const std::string &identifierName = "",
                    const std::string &identifierUpperValue = "",
                    const std::string &identifierLowerValue = "",
                    const std::string &containWord = "");
    /// Container for the SELECT operation data
    ///
    /// @see dataSelect() PmUtilities::db_container
    PmUtilities::db_container dataBuffer;
    /// gets the **Document id** table head name
    std::string getDocIdHead();
    /// gets the **Document name** table head name
    std::string getDocNameHead();
    /// gets the **Document number** table head name
    std::string getDocNumHead();
    /// gets the **Document revision** table head name
    std::string getDocRevHead();
    /// gets the **Approving document number** table head name
    std::string getApprDocNumHead();
    /// gets the **Document made date** table head name
    std::string getDocMadeDateHead();
    /// gets the **Document review date** table head name
    std::string getDocReviewDateHead();
    /// gets the **Document approving date** table head name
    std::string getDocApprDateHead();
    /// gets the **Document extension** table head name
    std::string getDocExtHead();
    /// gets the **Document path** table head name
    std::string getDocPathHead();

    /// gets the **Project id** table head name
    std::string getProjIdHead();
    /// gets the **Project name** table head name
    std::string getProjNameHead();
    /// gets the **Project number** table head name
    std::string getProjNumberHead();
    /// gets the **Project path** table head name
    std::string getProjPathHead();

private:
    /// Static instance of the class for the singleton's purpose
    static DbManager instance;
    /// Call back function used to write into the SQLite db
    static int writeCallback(void *NotUsed, int argc, char **argv, char **azColName);
    /// Call back function used to read data from the SQLite db
    static int readCallback(void *data, int argc, char **argv, char **azColName);
    /// gets the maximum int value from the buffer
    int bufferMax(const char* = "first");
    /// SQLite db object
    sqlite3 *database;
    /// SQLite error message value
    char *zErrMsg = 0;
    /// handle to communicate with SQLite db
    int rc;
    /// string for writing down the SQL querry
    std::string sql;
    /// the last id number of projects in db
    int projId = 0;
    /// the last id number of documents in db
    int docId = 0;
    /// path to the application SQLite db
    std::string dbPath;
    /// vector of tables names in the db
    std::vector<std::string> tablesNames {
        "PROJECTS",
        "DOCUMENTS"
    };

    /// name of the **Document id** table name
    std::string headDocId = "DOC_ID";
    /// name of the **Document name** table name
    std::string headDocName = "DOC_NAME";
    /// name of the **Document number** table name
    std::string headDocNumber = "DOC_NUMBER";
    /// name of the **Document revision** table name
    std::string headDocRevision = "DOC_REV";
    /// name of the **Approving document number** table name
    std::string headApprDocNumber = "APR_DOC_NUM";
    /// name of the **Document made date** table name
    std::string headDocMadeDate = "DOC_MADE_DATE";
    /// name of the **Document review date** table name
    std::string headDocReviewDate = "DOC_REVIEW_DATE";
    /// name of the **Document approving date** table name
    std::string headDocApprDate = "DOC_APPR_DATE";
    /// name of the **Document extension** table name
    std::string headDocExt = "DOC_EXT";
    /// name of the **Document path** table name
    std::string headDocPath = "DOC_PATH";

    /// name of the **Project id** table name
    std::string headProjId = "PROJ_ID";
    /// name of the **Project name** table name
    std::string headProjName = "PROJ_NAME";
    /// name of the **Project number** table name
    std::string headProjNumber = "PROJ_NUM";
    /// name of the **Project path** table name
    std::string headProjPath = "PROJ_PATH";
};
#endif // DBMANAGER_H
