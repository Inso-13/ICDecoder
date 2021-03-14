//
// Created by Inso on 2021/3/11.
//

#include "ITypeReader.h"

void ITypeReader::getWord(std::string &str) {
    char tempChar;

    while((tempChar = this->m_ifs->get()) != EOF)
    {
        if(IDictionary::isLetterOrNumberOrDL(tempChar))
        {
            str+=tempChar;
        }
        else
        {
            while(IDictionary::isBlankSep(tempChar)||tempChar=='*')
            {
                str+=tempChar;
                if(tempChar=='\n')
                    str+='\n';
                tempChar = this->m_ifs->get();
            }
            break;
        }
    }
    while(IDictionary::isBlankSep(str[str.length()-1]))
        str=str.substr(0,str.length()-1);

    if(!IDictionary::isBaseType(str))
    {
        str="";
    }

    if(!str.empty())
    {
        m_last=str;
    }
}
