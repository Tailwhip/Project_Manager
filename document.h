#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <iostream>
#include <string>


class Document //Product
{
public:
    Document();
    ~Document();

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

    void setDocName(std::string);
    void setDocNum(std::string);
    void setDocRev(std::string);
    void setApprDocNum(std::string);
    void setMadeDate(std::string);
    void setReviewDate(std::string);
    void setApprDate(std::string);
    void setProjNum(std::string);
    void setDocExt(std::string);
    void setDocPath(std::string);
    void createDocument();
    void fillDocument();

private:
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




