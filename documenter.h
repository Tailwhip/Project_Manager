#ifndef DOCUMENTER_H
#define DOCUMENTER_H

#include <iostream>
#include <string>
#include <memory>
#include "document.h"


class Documenter // Abstract Builder
{
protected:
    std::auto_ptr<Document> document;
public:
    Documenter();
    virtual ~Documenter();
    std::auto_ptr<Document> getDocument();

    void initDoc();

    virtual void setDocName() = 0;
    virtual void setDocNumber() = 0;
    virtual void setDocRev() = 0;
    virtual void setApprDocNum() = 0;
    virtual void setMadeDate() = 0;
    virtual void setReviewDate() = 0;
    virtual void setApprDate() = 0;
    virtual void setProjNum() = 0;
    virtual void setDocExt() = 0;
    virtual void setDocPath() = 0;
    virtual void createDocument() = 0;
    virtual void fillDocument() = 0;
}; // builds any document from scratch
#endif // DOCUMENTER_H
