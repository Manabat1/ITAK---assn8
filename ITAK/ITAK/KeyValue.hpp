//
// Created by manab on 3/29/2017.
//

#ifndef DICTIONARY_KEYVALUE_HPP
#define DICTIONARY_KEYVALUE_HPP

template <typename k, typename v>
class KeyValue{
public:
    KeyValue(const k key,const v value,const unsigned int iv)
            :
            m_key(key),
            m_value(value),
            m_iv(iv)
    {
    }
    KeyValue<k,v>(const KeyValue<k,v>& keyValue){
            m_key= keyValue.getKey();
            m_value = keyValue.getValue();
            m_iv = keyValue.getIv();
    }
    k getKey() const{
        return m_key;
    }

    v getValue() const{
        return m_value;
    }

    unsigned int getIv() const{
        return m_iv;
    }

    void setValue(const v newValue){
        m_value = newValue;
    }

private:
    k m_key;
    v m_value;
    unsigned int m_iv;
};
#endif //DICTIONARY_KEYVALUE_HPP
