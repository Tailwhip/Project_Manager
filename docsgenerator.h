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

/// The *Director* class in the *Builder* pattern.
///
/// An instance of the **DocGenerator** has to be created to builds any document that is needed.
class DocsGenerator // Director
{
public:
    /// Constructor that defines the **documenter** member
    ///
    /// @see Documenter
    DocsGenerator();
    /// Destructor
    ~DocsGenerator();
    /// Sets the document builder
    void setDocumenter(Documenter* documenter);
    /// Gets a built document
    std::auto_ptr<Document> getDocument();
    /// Generates any document given as an argument for
    /// the **setDocumenter()**
    void generateDoc();

private:
    /// Instance of an *Abstract builder* class object
    Documenter* documenter;
    /// passes the createFromTemp() function implemented in
    /// any given concrete document builder.
    ///
    /// That function copies the right template into the document's path.
    void createFromTemp();
    /// passes the fillDocument() function implemented in any
    /// given concrete document builder.
    ///
    /// That function fills the document with
    /// the data depending on sort of document.
    void fillDocument();
};

#endif // DOCSGENERATOR_H

