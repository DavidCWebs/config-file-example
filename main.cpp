#include "config.hpp"
#include <iostream>

int main(void)
{
    std::cout << "myNum = " << config::myNum << std::endl;
    config::loadConfigFromFile();
    for(auto& kv : config::values)
        std::cout << kv.first << " has value " << kv.second << std::endl;
        std::cout << "----" << std::endl;
    return 0;
}
