#ifndef GENDOCLIST_H
#define GENDOCLIST_H

#include <iostream>
#include <string>
#include <map>
#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>
#include <boost/foreach.hpp>
#include "wx/wxAutoExcel.h"
#include "documenter.h"
#include "dbmanager.h"
#include "pmutilities.h"


class GenDocList : public Documenter // (Concrete) Documents List Builder
{
public:
    GenDocList(PmUtilities::map_str &);
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

    void setDocData();
    void createFromTemp();
    void fillDocument();

private:
    PmUtilities::map_str docData;

};
// builds any document from scratch

#endif // GENDOCLIST_H
