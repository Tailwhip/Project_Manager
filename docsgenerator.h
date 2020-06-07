#ifndef DOCSGENERATOR_H
#define DOCSGENERATOR_H

#include <exception>
#include <boost/exception/all.hpp>

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "sqlite3.h"
#include "wx/wx.h"
#include "documenter.h"
#include "pmutilities.h"

class DocsGenerator // Director
{
private:
    Documenter* documenter;
public:
    DocsGenerator();
    ~DocsGenerator();

    void setDocumenter(Documenter* documenter);
    std::auto_ptr<Document> getDocument();
    void generateDoc();
private:
    void createFromTemp();
    void fillDocument();

};

#endif // DOCSGENERATOR_H

