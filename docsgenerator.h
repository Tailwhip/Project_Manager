#ifndef DOCSGENERATOR_H
#define DOCSGENERATOR_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <boost/spirit/include/karma.hpp>
#include <memory>
#include "sqlite3.h"
#include "wx/wx.h"
#include "documenter.h"


using boost::spirit::karma::int_;
using boost::spirit::karma::generate;

class DocsGenerator // Director
{
private:
    Documenter* docsCreator;
public:
    DocsGenerator();
    ~DocsGenerator();

    void setDocumenter(Documenter*);
    std::auto_ptr<Document> getDocument();
    void generateDoc();
    //void CreateDB(std::vector<std::string> &);
private:
    /*
    static int Callback(void *, int , char **, char **);
    sqlite3 *database;
    char *zErrMsg = 0;
    int rc;
    std::string sql;
    */
};

#endif // DOCSGENERATOR_H

