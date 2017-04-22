//
// Created by manab on 4/21/2017.
//

#include "ConfigurationTester.hpp"
#include "../Configuration.hpp"

void ConfigurationTester::testConfigurations() {
    Configuration configuration;
    //test add and remove
    configuration.add("Coolway", "4");
    configuration.add("otherway", "4.4");
    configuration.add("bigway", "44");
    configuration.removeByKey("bigway");

    std::cout << "Shouldn't be able to add duplicate key" << std::endl;
        configuration.add("Coolway","7");



    //Test conversions
    int check = 4;
    if(configuration.getValueAsInt("Coolway") != check){
        std::cout << "Bad conversion - int" << std::endl;
    }
    //Test conversions
    double check2 = 4.4;
    if(configuration.getValueAsDouble("otherway") != check2){
        std::cout << "Bad conversion - double:: " << configuration.getValueAsDouble("otherway") << std::endl;
    }
    std::string check3 = "4.4";
    if(configuration.getValueAsString("otherway") != check3){
        std::cout << "Bad conversion - string:: " << configuration.getValueAsString("otherway") << std::endl;
    }

    std::cout << "Configuration Test Complete" << std::endl;
}
