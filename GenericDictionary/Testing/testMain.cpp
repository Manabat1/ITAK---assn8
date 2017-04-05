//
// Created by manab on 4/4/2017.
//

#include "DictionaryTester.hpp"
#include "KeyValueTester.hpp"

int main(){
    DictionaryTester dictionaryTester;
    KeyValueTester keyValueTester;

    keyValueTester.testKeyValueSetup();
    keyValueTester.testCopyConstructor();

    dictionaryTester.testDictionaryCreator();
    dictionaryTester.testCopyConstructor();
    dictionaryTester.testDictionaryExceptions();
    dictionaryTester.testDictionarysOfDictionarys();

    return 0;
}

