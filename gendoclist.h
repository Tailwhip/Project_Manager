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
//#include "wx/wxAutoExcel.h"
#include "wx/wx.h"
#include "wx/msw/ole/automtn.h"
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
    void fillMetrics();

    void fillData(boost::filesystem::path &projectPath, int groupLevel);
    wxAutomationObject excelObject;
    static int rowsIterator;
    bool isTemp(std::string &fileName) const;
    void groupFile(const std::string &fileName, const int groupLevel);

};
// builds any document from scratch

#endif // GENDOCLIST_H
