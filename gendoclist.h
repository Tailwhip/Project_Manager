#ifndef GENDOCLIST_H
#define GENDOCLIST_H

#include <iostream>
#include <string>
#include <map>
#include "documenter.h"
#include "dbmanager.h"


class GenDocList : public Documenter // Documents List Builder
{
public:
    GenDocList(std::map<std::string, std::string>&);
    virtual ~GenDocList();

    void setDocName();
    void setDocNumber();
    void setDocRev();
    void setApprDocNum();
    void setMadeDate();
    void setReviewDate();
    void setApprDate();
    void setProjNum();
    void setDocExt();
    void setDocPath();
    void createDocument();
    void fillDocument();

private:
    std::map<std::string, std::string> docData;
};
// builds any document from scratch

#endif // GENDOCLIST_H
