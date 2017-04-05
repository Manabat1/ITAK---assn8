//
// Created by manab on 4/4/2017.
//

#include <iostream>
#include "KeyValueTester.hpp"
#include "../KeyValue.hpp"

void KeyValueTester::testKeyValueSetup() {
    //INT STRING KEY VALUE
    KeyValue<int,int> keyValue1(1,2,3);
    if(keyValue1.getValue() != 2){
        std::cout << "Value getter got " << keyValue1.getValue() << std::endl;
    }
    if(keyValue1.getKey() != 1){
        std::cout << "Key getter got " << keyValue1.getKey() << std::endl;
    }
    if(keyValue1.getIv() != 3){
        std::cout << "IV getter got " << keyValue1.getIv() << std::endl;
    }
    keyValue1.setValue(4);
    if(keyValue1.getValue() != 4){
        std::cout << "Value getter got " << keyValue1.getValue() << std::endl;
    }

    //STRING STRING KEY VALUE
    KeyValue<std::string,std::string> keyValue2("Key","Value",1);
    if(keyValue2.getValue() != "Value"){
        std::cout << "Value getter got " << keyValue1.getValue() << std::endl;
    }
    if(keyValue2.getKey() != "Key"){
        std::cout << "Key getter got " << keyValue1.getKey() << std::endl;
    }
    if(keyValue2.getIv() != 1){
        std::cout << "IV getter got " << keyValue1.getIv() << std::endl;
    }
    keyValue2.setValue("Value 2");
    if(keyValue2.getValue() != "Value 2"){
        std::cout << "Value getter got " << keyValue1.getValue() << std::endl;
    }
    std::cout << "KeyValue Tester Passed" << std::endl;
}

void KeyValueTester::testCopyConstructor() {
    KeyValue<int,int> k1(1,2,3);
    KeyValue<int,int> k2(k1);

    if(k1.getValue() != k2.getValue()){
        std::cout << "INVALID" << std::endl;
    }
    if(k1.getIv() != k2.getIv()){
        std::cout << "INVALID" << std::endl;
    }
    if(k1.getValue() != k2.getValue()){
        std::cout << "INVALID" << std::endl;
    }

    KeyValue<std::string,std::string> k3("Hi","Bye",3);
    KeyValue<std::string,std::string> k4(k3);

    if(k3.getValue() != k4.getValue()){
        std::cout << "INVALID" << std::endl;
    }
    if(k3.getIv() != k4.getIv()){
        std::cout << "INVALID" << std::endl;
    }
    if(k3.getValue() != k4.getValue()){
        std::cout << "INVALID" << std::endl;
    }

    std::cout << "KeyValue Copy Constructor Passed" << std::endl;
}

