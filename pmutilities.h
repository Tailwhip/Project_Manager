#ifndef PMUTILITIES_H
#define PMUTILITIES_H

#include <string>
#include <map>
#include <boost/filesystem.hpp>

namespace PmUtilities{

// typedefs
typedef std::map<std::string, std::string> map_str;
typedef std::pair<std::string, std::string> pair_str;

// paths
    namespace Path {
        const boost::filesystem::path toTemplates{"\mstemplates"};
        //D:\\Zajecia\\Projekty\\22-Project_Manager\\Project_Manager\\mstemplates\\
        //E:/00-Test_proj
    }

}

#endif // PMUTILITIES_H
