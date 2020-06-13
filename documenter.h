#ifndef DOCUMENTER_H
#define DOCUMENTER_H

#include <iostream>
#include <string>
#include <memory>
#include "document.h"
#include "pmutilities.h"

/// The *Abstract builder* in the *Builder* pattern that is a collection
/// of every features necessary for document creation.
class Documenter // Abstract Builder
{
protected:
    /// Document object that the concrete builder will work on.
    std::auto_ptr<Document> document;
public:
    /// Constructor.
    Documenter();
    /// Virtual destructor.
    virtual ~Documenter();
    /// Gets the document object.
    ///
    /// @see document
    std::auto_ptr<Document> getDocument();
    /// document object initialisator.
    ///
    /// @see document
    void initDoc();
    /// Virtual function that sets the given document
    /// name in the SQLite application's db.
    virtual void setDocName() = 0;
    /// Virtual function that sets the given document
    /// number in the SQLite application's db.
    virtual void setDocNumber() = 0;
    /// Virtual function that sets the given document
    /// revision in the SQLite application's db.
    virtual void setDocRev() = 0;
    /// Virtual function that sets the given approving
    /// document number in the SQLite application's db.
    virtual void setApprDocNum() = 0;
    /// Virtual function that sets the given document
    /// made date in the SQLite application's db.
    virtual void setMadeDate() = 0;
    /// Virtual function that sets the given document
    /// review date in the SQLite application's db.
    virtual void setReviewDate() = 0;
    /// Virtual function that sets the given document
    /// approval date in the SQLite application's db.
    virtual void setApprDate() = 0;
    /// Virtual function that sets the given document
    /// project number in the SQLite application's db.
    virtual void setProjNum() = 0;
    /// Virtual function that sets the given document
    /// extension in the SQLite application's db.
    virtual void setDocExt() = 0;
    /// Virtual function that sets the given document
    /// path in the SQLite application's db.
    virtual void setDocPath() = 0;
    /// Virtual function that sets the docData container.
    virtual void setDocData() = 0;
    /// Virtual function that copies the right document
    /// template into the document's path.
    virtual void createFromTemp() = 0;
    /// Virtual function that fills the document with necessary data.
    virtual void fillDocument() = 0;
}; // builds any document from scratch
#endif // DOCUMENTER_H
