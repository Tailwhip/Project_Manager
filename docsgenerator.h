#ifndef DOCSGENERATOR_H
#define DOCSGENERATOR_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include "sqlite3.h"
#include "wx/wx.h"


class DocsGenerator // Director
{
public:

    DocsGenerator();
    ~DocsGenerator();

//private:
    void CreateDB(std::vector<std::string> &);
private:
    static int Callback(void *, int , char **, char **);
    sqlite3 *database;
    char *zErrMsg = 0;
    int rc;
    std::string sql;
    //std::string quotes("','");
    /*
  void Konstruuj(Budowniczy *budowniczy)
  {
    budowniczy.zbudujCzescA();
    budowniczy.zbudujCzescB();
  }
  */
};

#endif // DOCSGENERATOR_H

