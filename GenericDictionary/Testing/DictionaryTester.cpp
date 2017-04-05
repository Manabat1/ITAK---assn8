//
// Created by manab on 4/4/2017.
//

#include <iostream>
#include "DictionaryTester.hpp"
#include "../Dictionary.hpp"

void DictionaryTester::testDictionaryCreator() {
    Dictionary<int,int> d1;
    Dictionary<float,std::string> d2(500);
    //Test default size
    if(d1.getCount() != 10){
        std::cout << "Default size not created properly" << std::endl;
    }
    if(d2.getCount() != 500){
        std::cout << "Generated size not created properly" << std::endl;
    }

    d2.add(4.4,"r");
    if(d2.getCount() != 501){
        std::cout << "added size not created properly" << std::endl;
    }

    std::cout << "Dictionary Creator Passed" << std::endl;
}

void DictionaryTester::testDictionaryExceptions() {
    Dictionary<int,int> d1;
    d1.add(6,7);
    if(d1.getValue(6) != 7){
        std::cout << "Value not proper" << std::endl;
    }
    d1.removeByKey(6);
    std::cout << "Key should be unfound" << std::endl;
    if(d1.getValue(6) == 7){
        std::cout << "Remove not proper" << std::endl;
    }
    std::cout << "Remove should be illegal" << std::endl;
    d1.removeByKey(5);

    d1.add(6,7);
    std::cout << "Adding identical key should be illegal" << std::endl;
    d1.add(6,8);
    //Legal remove
    d1.removeByIndex(0);
    //Illegal remove
    std::cout << "Should not be able to remove twice" << std::endl;
    d1.removeByIndex(0);
    d1.add(7,7);

    d1.setValueByKey(7,8);
    if(d1.getValue(7) != 8){
        std::cout << "Reset not proper :: "  << std::endl;
    }

    int count = d1.getCount();
    if(count != 11){
        std::cout << "Count not proper  " << std::endl;
    }

    KeyValue<int,int> kv1 = d1.getByIndex(0);
    if(kv1.getValue() != 8){
        std::cout << "KV not proper :: "  << std::endl;
    }
    KeyValue<int,int> kv2 = d1.getKeyValue(7);
    if(kv2.getValue() != 8){
        std::cout << "KV not proper :: " << std::endl;
    }
    //k1 == k2
    std::cout << "Dictionary Elements Passed" << std::endl;
}

void DictionaryTester::testDictionarysOfDictionarys() {
    Dictionary<int,Dictionary<int,std::string>*> d1;
    Dictionary<int,std::string>* d2 = new Dictionary<int,std::string>();
    d2->add(1,"Yo");
    d1.add(1,d2);
    KeyValue<int,Dictionary<int,std::string>*> keyValue = d1.getKeyValue(1);
    Dictionary<int,std::string>* d3 = d1.getValue(1);


    if(keyValue.getValue()->getValue(1) != d3->getValue(1)){
        std::cout << "KV of dictionary not same as Value"
                  << keyValue.getValue()->getValue(0)
                  << " :: "
                  << d3->getValue(0)
                  << std::endl;
    }

    std::cout << "Dictionary of Dictionaries Passed" << std::endl;
}

void DictionaryTester::testCopyConstructor() {
    Dictionary<int,int> d1;
    d1.add(4,4);
    d1.add(5,5);
    d1.add(6,4);
    Dictionary<int,int> d2(d1);

    if(d1.getValue(4) != d2.getValue(4)){
        std::cout << "INVALID" << std::endl;
    }
    if(d1.getValue(5) != d2.getValue(5)){
        std::cout << "INVALID" << std::endl;
    }
    if(d1.getValue(6) != d2.getValue(6)){
        std::cout << "INVALID" << std::endl;
    }

    Dictionary<std::string,std::string> d3;
    d3.add("One","four");
    d3.add("Two","four");
    d3.add("Three","OhNo");
    Dictionary<std::string,std::string> d4(d3);

    if(d3.getValue("One") != d4.getValue("One")){
        std::cout << "INVALID" << std::endl;
    }
    if(d3.getValue("Two") != d4.getValue("Two")){
        std::cout << "INVALID" << std::endl;
    }
    if(d3.getValue("Three") != d4.getValue("Three")){
        std::cout << "INVALID" << std::endl;
    }

    std::cout << "Dictionary Copy Constructor Passed" << std::endl;
}
