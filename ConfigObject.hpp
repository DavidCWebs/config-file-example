#ifndef CONFIG_OBJECT_H
#define CONFIG_OBJECT_H
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>

class ConfigObject
{
    const char * configFilepath;
    std::map<std::string, std::string> values;
public:
    ConfigObject(const char * configFilepath);
    bool loadConfigFromFile();
    std::map<std::string, std::string> getValues();
};

#endif
