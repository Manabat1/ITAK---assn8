//
// Created by manab on 3/29/2017.
//

#ifndef DICTIONARY_DICTIONARY_HPP
#define DICTIONARY_DICTIONARY_HPP

#include <vector>
#include <string>
#include <iostream>
#include "KeyValue.hpp"

//Hashtable??

template<typename k, typename v>
class Dictionary {
public:
    Dictionary() {
        m_elements = 10;
    }

    Dictionary(int size) {
        m_elements = size;
    }

    ~Dictionary() {
        for (KeyValue<k, v> *kv : m_keyValues) {
            delete kv;
        }
    }

    Dictionary(const Dictionary<k, v> &d) {
        this->m_elements = d.getCount();
        m_hash = 0;
        for (KeyValue<k, v> *kv : d.m_keyValues) {
            add(kv->getKey(), kv->getValue());
        }
    }

    v getValue(k keyIn) const {

                //for (KeyValue<k, v>* kv : m_keyValues) {
                    for(int i = 0; i < m_keyValues.size(); i++){
                        KeyValue<k,v>* kv = m_keyValues[i];
                   // }
                    if (kv->getKey() == keyIn) {
                        return kv->getValue();
                    }
                }

            throw std::string("Key not found");

    }

    int getCount() const {
        return m_elements;
    }

    const KeyValue<k, v> &z(k keyIn) const {
        try {
            for (KeyValue<k, v> *kv : m_keyValues) {
                if (kv->getKey() == keyIn) {
                    return *kv;
                }
            }
            throw std::string("Key not found");
        } catch (std::string) {
            std::cout << "Key not found" << std::endl;
        }
    }

    void setValueByKey(k keyIn, v valueIn) const {
        try {
            for (KeyValue<k, v> *kv : m_keyValues) {
                if (kv->getKey() == keyIn) {
                    kv->setValue(valueIn);
                    return;
                }
            }
            throw std::string("Key not found :: Unable to set");
        } catch (std::string s) {
            std::cout << s << std::endl;
        }
    }

    void add(k keyIn, v valueIn) {
        try {
            for (KeyValue<k, v> *kv : m_keyValues) {
                if (kv->getKey() == keyIn) {
                    throw std::string("Cannot add key :: Duplicate Key");
                }
            }
        } catch (std::string s) {
            std::cout << s << std::endl;
            return;
        }

        m_keyValues.push_back(new KeyValue<k, v>(keyIn, valueIn, nextHash()));
        m_elements++;
    }

    void removeByKey(k keyIn) {
        try {
            int index = -1;
            for (int i = 0; i < m_keyValues.size(); i++) {
                KeyValue<k, v> *kv = m_keyValues[i];
                if (kv->getKey() == keyIn) {
                    index = i;
                    break;
                }
            }
            if (index == -1) {
                throw std::string("Invalid key to remove :: Not Found");
            }
            m_keyValues.erase(m_keyValues.begin() + index);
            m_elements--;
        } catch (std::string s) {
            std::cout << s << std::endl;
        }

    }

    void removeByIndex(unsigned int inIndex) {
        try {
            int index = -1;
            for (int i = 0; i < m_keyValues.size(); i++) {
                KeyValue<k, v> *kv = m_keyValues[i];
                if (inIndex == i) {
                    index = i;
                    break;
                }
            }
            if (index == -1) {
                throw std::string("Invalid key to remove :: Not Found");
            }
            m_keyValues.erase(m_keyValues.begin() + index);
            m_elements--;
        } catch (std::string s) {
            std::cout << s << std::endl;
        }
    }

    const KeyValue<k, v> &getByIndex(unsigned int inIndex) const {
        try {
            int index = -1;
            for (int i = 0; i < m_keyValues.size(); i++) {
                KeyValue<k, v> *kv = m_keyValues[i];
                if (inIndex == i) {
                    if (kv == nullptr) {
                        throw std::string("Invalid key found");
                    }
                    return *kv;
                }
            }
            if (index == -1) {
                throw std::string("Key not found by index");
            }
        } catch (std::string s) {
            std::cout << s << std::endl;
        }

    }

    const KeyValue<k, v> &operator[](unsigned int index) const {
        return getByIndex(index);
    };

    const void printElements(std::ostream& stream){
        for(KeyValue<k, v>* keyValue : m_keyValues){
            stream << "KEY: " <<keyValue->getKey() << "VALUE:" << keyValue->getValue() << std::endl;
        }
    }

    std::vector<KeyValue<k, v>*> m_keyValues;
private:
    unsigned int m_hash = 0;
    unsigned int m_elements = 0;

    unsigned int nextHash() {
        return m_hash++;
    };
};

#endif //DICTIONARY_DICTIONARY_HPP
