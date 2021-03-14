//
// Created by Inso on 2021/3/11.
//

#include "IOperatorReader.h"

void IOperatorReader::getWord(std::string &str) {
    char tempChar;
    std::string tempStr;
    bool first_flag= true;

    while((tempChar = this->m_ifs->get()) != EOF)
    {
        if(IDictionary::isOperator(tempChar))
        {
            str += tempChar;
        }
        else if(first_flag&&IDictionary::isBracket1l(tempChar))
        {
            str += tempChar;
            while((tempChar = this->m_ifs->get()) != EOF)
            {
                if(IDictionary::isBlankSep(tempChar))
                {
                    str+=tempChar;
                    if(tempChar=='\n')
                        str+='\n';
                }
                else
                    break;
            }
            do
            {
                if(IDictionary::isLetterOrNumberOrDL(tempChar))
                {
                    str+=tempChar;
                }
                else
                {
                    break;
                }
            }while((tempChar = this->m_ifs->get()) != EOF);
            if(!IDictionary::isBaseType(str.substr(1,str.length()-1)))
            {
                str="";
            }
            else
            {
                do
                {
                    if(IDictionary::isBlankSep(tempChar))
                    {
                        str+=tempChar;
                        if(tempChar=='\n')
                            str+='\n';
                    }
                    else
                        break;
                }while((tempChar = this->m_ifs->get()) != EOF);
                if(IDictionary::isBracket1r(tempChar))
                {
                    str += tempChar;
                    m_type|=2;
                    break;
                }
                else
                    str="";
            }
        }
        else
        {
            break;
        }
        first_flag= false;
    }

    tempStr=str;
    int maxLen=tempStr.length();

    for(int i=0;i<maxLen;i++)
    {
        str=tempStr.substr(0,maxLen-i);
        if(IDictionary::isOperator0(str))
        {
            m_type|=1;
        }
        if(IDictionary::isOperator1(str))
        {
            m_type|=2;
        }
        if(IDictionary::isOperator2(str))
        {
            m_type|=4;
        }
        if(str==",")
        {
            m_type|=8;
        }
        if(m_type)
            break;
    }
}

