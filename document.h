#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <iostream>
#include <string>
#include <map>
#include "dbmanager.h"
#include "pmutilities.h"

class Document //Product
{

public:
    Document();
    ~Document();

    PmUtilities::map_str *getDocData();

    std::string getDocName();
    std::string getDocNum();
    std::string getDocRev();
    std::string getApprDocNum();
    std::string getMadeDate();
    std::string getReviewDate();
    std::string getApprDate();
    std::string getProjNum();
    std::string getDocExt();
    std::string getDocPath();

    void setDocData(const PmUtilities::map_str &docData);

    void setDocName(const std::string &docName);
    void setDocNum(const std::string &docNum);
    void setDocRev(const std::string &docRev);
    void setApprDocNum(const std::string &apprDocNum);
    void setMadeDate(const std::string &madeDate);
    void setReviewDate(const std::string &reviewDate);
    void setApprDate(const std::string &apprDate);
    void setProjNum(const std::string &projNum);
    void setDocExt(const std::string &docExt);
    void setDocPath(const std::string &docPath);

private:
    PmUtilities::map_str docData;

    std::string docName;
    std::string docNum;
    std::string docRev;
    std::string apprDocNum;
    std::string madeDate;
    std::string reviewDate;
    std::string apprDate;
    std::string projNum;
    std::string docExt;
    std::string docPath;
};

#endif // DOCUMENT_H




