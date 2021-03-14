//
// Created by Inso on 2021/3/11.
//

#include "IWordReader.h"

void IWordReader::getWord(std::string &str) {
    char tempChar;
    tempChar = this->m_ifs->get();
    if(!IDictionary::isLetterOrDL(tempChar))
    {
        return;
    }
    else
    {
        str+=tempChar;
    }
    while((tempChar = this->m_ifs->get()) != EOF)
    {
        if(IDictionary::isLetterOrNumberOrDL(tempChar))
        {
            str+=tempChar;
        }
        else
        {
            break;
        }
    }
    if(IDictionary::isBaseType(str))
    {
        str="";
        std::cerr<<"error!";
        exit(1);
    }

    m_last_id=str;
    auto it = IDictionary::dic.find(str);

    if(it!=IDictionary::dic.end())
    {
        m_isNew = false;
        m_dataType = "Identifier -> " + it->second;
    }
    else
    {
        m_isNew= true;
        m_dataType = "New Identifier";
    }
}
