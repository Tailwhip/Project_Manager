#ifndef GENDOCLIST_H
#define GENDOCLIST_H

#include <iterator>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>
#include <boost/range/iterator_range.hpp>
#include <boost/foreach.hpp>
#include "wx/wx.h"
#include "wx/msw/ole/automtn.h"
#include "documenter.h"
#include "dbmanager.h"
#include "pmutilities.h"

/// *Concrete builder* class in the *Builder* pattern responsible for
/// creating the **Documents list** document.
///
/// Derives from the **Abstract builder** - **Documenter** class.
/// Builds a **Documents list** document from scratch.
class GenDocList : public Documenter // (Concrete) Documents List Builder
{
public:
    /// Constructor for creating **Documents list** document.
    ///
    /// Using a data about the document (document name, document number etc.) as an argument.
    GenDocList(PmUtilities::map_str &docData);
    /// Virtual destructor
    virtual ~GenDocList();
    /// Overwritten virtual function that sets the given document
    /// name in the SQLite application's db.
    void setDocName();
    /// Overwritten virtual function that sets the given document
    /// number in the SQLite application's db.
    void setDocNumber();
    /// Overwritten virtual function that sets the given document
    /// revision in the SQLite application's db.
    void setDocRev();
    /// Overwritten virtual function that sets the given approving
    /// document number in the SQLite application's db.
    void setApprDocNum();
    /// Overwritten virtual function that sets the given document
    /// made date in the SQLite application's db.
    void setMadeDate();
    /// Overwritten virtual function that sets the given document
    /// review date in the SQLite application's db.
    void setReviewDate();
    /// Overwritten virtual function that sets the given document
    /// approval date in the SQLite application's db.
    void setApprDate();
    /// Overwritten virtual function that sets the given document
    /// project number in the SQLite application's db.
    void setProjNum();
    /// Overwritten virtual function that sets the given document
    /// extension in the SQLite application's db.
    void setDocExt();
    /// Overwritten virtual function that sets the given document
    /// path in the SQLite application's db.
    void setDocPath();
    /// Overwritten virtual function that sets the docData container.
    ///
    /// @see docData
    void setDocData();
    /// Overwritten virtual function that copies the right .xls document
    /// template into the document's path.
    ///
    /// In case of **Documents list** document a document's path is the same
    /// as the project's path.
    void createFromTemp();
    /// Overwritten virtual function that fills the document with
    /// the data using private fillMetrics() and fillData() functions.
    ///
    /// @see fillMetrics() fillData()
    void fillDocument();

private:
    /// Container for the document data that are going to the db.
    PmUtilities::map_str docData;
    /// Fills the metrics with the data about the document
    /// (document name, document number etc.).
    void fillMetrics();
    /// Fills the "Data" .xls template sheet with the grouped list of project documents.
    ///
    /// The function works recursively.
    void fillData(boost::filesystem::path &projectPath, int groupLevel);
    /// Object dedicated to execute VBA automation commands.
    wxAutomationObject excelObject;
    /// Iterator for rows in the document.
    ///
    /// Is used for inserting next document on the **Documents list**.
    int rowsIterator = 0;
    /// Checks if the document is a temporary file.
    ///
    /// Temporary files should not be placed in the **Documents list**.
    bool isTemp(std::string &fileName) const;
    /// Function that runs the VBA macro inserting document on the right place
    /// in the **Documents list**.
    void groupFile(const std::string &fileName, const int groupLevel);
};
#endif // GENDOCLIST_H
