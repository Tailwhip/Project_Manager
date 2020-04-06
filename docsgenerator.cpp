#include "docsgenerator.h"

DocsGenerator::DocsGenerator(){

}

DocsGenerator::~DocsGenerator(){
}

int DocsGenerator::Callback(void *NotUsed, int argc, char **argv, char **azColName) {
   int i;
   for(i = 0; i<argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

void DocsGenerator::CreateDB(std::vector<std::string> &projectData) {
    rc = sqlite3_open("data/projects.db", &database);
    // Data verification
    if (rc)
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(database));
    else
      fprintf(stdout, "Opened database successfully\n");
    // Prepares PROJECTS table creation query
    sql = "CREATE TABLE PROJECTS("  \
      "PROJ_ID                           INT PRIMARY KEY    NOT NULL," \
      "PROJECT_NAME               TEXT                        NOT NULL," \
      "PROJECT_NUMBER          TEXT                        NOT NULL," \
      "PROJECT_PATH                TEXT                        NOT NULL);";
    // Creates PROJECTS table
    rc = sqlite3_exec(database, sql.c_str(), Callback, NULL, &zErrMsg);
    // Prepares DOCUMENTS table creation query
    sql = "CREATE TABLE DOCUMENTS("  \
      "DOC_ID                                  INT PRIMARY KEY   NOT NULL," \
      "DOCUMENT_NAME               TEXT                        NOT NULL," \
      "DOCUMENT_NUMBER          TEXT                        NOT NULL," \
      "DOCUMENT_PATH                TEXT                        NOT NULL);";
    // Creates DOCUMENTS table
    rc = sqlite3_exec(database, sql.c_str(), Callback, NULL, &zErrMsg);
    // Inserts a new project data into the PROJECTS table
    sql = "INSERT INTO PROJECTS VALUES(NULL, '"
            + projectData.at(0) + "','"
            + projectData.at(1) + "','"
            + projectData.at(2) + "');";
    rc = sqlite3_exec(database, sql.c_str(), Callback, NULL, &zErrMsg);

    wxString message;
    message.Printf(wxT("sql:  %s"), sql.c_str());
    wxMessageBox(message);

   if (rc != SQLITE_OK){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   } else
      fprintf(stdout, "Table created successfully\n");

    sqlite3_close(database);
}
