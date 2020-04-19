#ifndef DOCSGENERATOR_H
#define DOCSGENERATOR_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "sqlite3.h"
#include "wx/wx.h"
#include "documenter.h"

class DocsGenerator // Director
{
private:
    Documenter* documenter;
public:
    DocsGenerator();
    ~DocsGenerator();

    void setDocumenter(Documenter*);
    std::auto_ptr<Document> getDocument();
    void generateDoc();
private:
};

#endif // DOCSGENERATOR_H

