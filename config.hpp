#ifndef CONFIG_H
#define CONFIG_H
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>

//https://stackoverflow.com/a/10892523/3590673
namespace config
{
    extern int myNum;
    extern std::string some_config_string;
    extern int lines;
    extern std::map<std::string, std::string> values;

    bool loadConfigFromFile();
}

#endif
