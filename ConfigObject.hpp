#ifndef CONFIG_OBJECT_H
#define CONFIG_OBJECT_H
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>

namespace config
{
    extern int myNum;
    extern std::string some_config_string;
    extern int lines;
    extern std::map<std::string, std::string> values;

    bool loadConfigFromFile();
}

#endif
