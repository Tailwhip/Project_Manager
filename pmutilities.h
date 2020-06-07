#ifndef PMUTILITIES_H
#define PMUTILITIES_H

#include <string>
#include <map>
#include <boost/filesystem.hpp>

namespace PmUtilities {

// typedefs
typedef std::pair<std::string, std::string> pair_db; // 1st - db column name; 2nd - table_id
typedef std::map<pair_db, std::string> map_db; // 1st - db coordinates; 2nd - the data avlue
typedef std::map<std::string, std::string> map_str; // 1st - db column name; 2nd db value
typedef std::vector<pair_db> db_container; // a container for data read from db
// paths
    namespace Path {
        const boost::filesystem::path toTemplates{"\mstemplates"};
        //D:\\Zajecia\\Projekty\\22-Project_Manager\\Project_Manager\\mstemplates\\
        //E:/00-Test_proj
    }
}

#endif // PMUTILITIES_H
