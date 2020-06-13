#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <iostream>
#include <string>
#include <map>
#include "dbmanager.h"
#include "pmutilities.h"

/// The *Product* class in the *Builder* which is a template for every document.
class Document //Product
{

public:
    /// Constructor.
    Document();
    /// Destructor.
    ~Document();
    /// Document data containter.
    PmUtilities::map_str *getDocData();
    /// Gets the document name.
    std::string getDocName();
    /// Gets the document number.
    std::string getDocNum();
    /// Gets the document revision number.
    std::string getDocRev();
    /// Gets the approval document number.
    std::string getApprDocNum();
    /// Gets the made date of the document.
    std::string getMadeDate();
    /// Gets the review date of the document.
    std::string getReviewDate();
    /// Gets the approval date of the document.
    std::string getApprDate();
    /// Gets the project number that the document belongs to.
    std::string getProjNum();
    /// Gets the document extension.
    std::string getDocExt();
    /// Gets the document path.
    std::string getDocPath();
    /// Sets the data about the document.
    ///
    /// @see docData
    void setDocData(const PmUtilities::map_str &docData);
    /// Sets the document name.
    void setDocName(const std::string &docName);
    /// Sets the document number.
    void setDocNum(const std::string &docNum);
    /// Sets the document revision number.
    void setDocRev(const std::string &docRev);
    /// Sets the approval document number.
    void setApprDocNum(const std::string &apprDocNum);
    /// Sets the made date of the document.
    void setMadeDate(const std::string &madeDate);
    /// Sets the review date of the document.
    void setReviewDate(const std::string &reviewDate);
    /// Sets the approval date of the document.
    void setApprDate(const std::string &apprDate);
    /// Sets the project number that the document belongs to.
    void setProjNum(const std::string &projNum);
    /// Sets the document extension.
    void setDocExt(const std::string &docExt);
    /// Sets the document path.
    void setDocPath(const std::string &docPath);

private:
    /// Container for the data about the document.
    PmUtilities::map_str docData;
    /// Document name.
    std::string docName;
    /// Document number.
    std::string docNum;
    /// Document revision.
    std::string docRev;
    /// Approval document number.
    std::string apprDocNum;
    /// Document made date.
    std::string madeDate;
    /// Document review date.
    std::string reviewDate;
    /// Document approval date.
    std::string apprDate;
    /// Project number that the document belongs to.
    std::string projNum;
    /// Document extension.
    std::string docExt;
    /// Document path.
    std::string docPath;
};

#endif // DOCUMENT_H




