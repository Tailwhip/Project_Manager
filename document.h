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

    void setDocName(const std::string&);
    void setDocNum(const std::string&);
    void setDocRev(const std::string&);
    void setApprDocNum(const std::string&);
    void setMadeDate(const std::string&);
    void setReviewDate(const std::string&);
    void setApprDate(const std::string&);
    void setProjNum(const std::string&);
    void setDocExt(const std::string&);
    void setDocPath(const std::string&);
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




