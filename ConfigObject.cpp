#include "ConfigObject.hpp"

ConfigObject::ConfigObject(const char * inConfigFilepath) : configFilepath(inConfigFilepath) {
    std::cout << "config file path " << configFilepath << std::endl;
    loadConfigFromFile();
}

bool ConfigObject::loadConfigFromFile()
{
    std::string lines;
    std::ifstream myFile(configFilepath);
    if (!myFile) {
        std::cout << "Error opening file " << configFilepath << std::endl;
    }
    while (std::getline(myFile, lines)) {
        if (lines.empty() || lines.find("//") == 0 || lines.find("#") == 0)
            continue;
        std::istringstream lineStream(lines);
        std::string key;
        // In the following context getline() extracts characters from input
        // stream for each line until the specified delimitation character '='
        // is found. In this way, everything up to '=' is assigned to the `key`
        // string variable.
        if(std::getline(lineStream, key, '=')) {
            std::string value;
            // Everything up to the newline assigned to value
            if(std::getline(lineStream, value))
                values[key] = value;
        }
    }
    return true;
}

std::map<std::string, std::string> ConfigObject::getValues()
{
    return values;
}
