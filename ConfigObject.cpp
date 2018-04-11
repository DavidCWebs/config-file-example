#include "config.hpp"
std::map<std::string, std::string> config::values;

namespace config
{
    int myNum = 123;
    std::string some_config_string = "foo";
    int lines = 0;
}

bool config::loadConfigFromFile()
{
    const char * filepath = "./config.txt";
    std::string lines;
    std::ifstream myFile(filepath);
    if (!myFile) {
        std::cout << "Error opening file " << filepath << std::endl;
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
                config::values[key] = value;
        }
    }
    return true;
}
