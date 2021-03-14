//
// Created by Inso on 2021/3/12.
//

#include "ICharReader.h"

void ICharReader::getWord(std::string &str) {
    char tempChar;
    int base_len=str.length();
    int base_pos=m_ifs->tellg();

    tempChar=m_ifs->get();
    if(IDictionary::isQuotation1(tempChar))
    {
        str+=tempChar;
        tempChar=m_ifs->get();
        if(tempChar=='\\')
        {
            str+=tempChar;
            if(!readSpecialChar(m_ifs,str))
                str=str.substr(0,base_len);
            else
            {
                setPos(base_pos+str.length()-base_len);
                tempChar=m_ifs->get();
                if(IDictionary::isQuotation1(tempChar))
                {
                    str+=tempChar;
                }
                else
                    str=str.substr(0,base_len);
            }
        }
        else if(!(tempChar=='\''||tempChar=='\"'))
        {
            str+=tempChar;
            tempChar=m_ifs->get();
            if(IDictionary::isQuotation1(tempChar))
                str+=tempChar;
            else
                str=str.substr(0,base_len);
        }
        else
            str=str.substr(0,base_len);
    }
}

int ICharReader::readSpecialChar(std::ifstream *ifs,std::string &str) {
    char tempChar;
    int base_pos=ifs->tellg();
    int base_len=str.length();

    tempChar=ifs->get();
    if(IDictionary::isSimpleTransfer(tempChar))
    {
        str+=tempChar;
    }
    else if(tempChar=='x')
    {
        str+=tempChar;
        for(int i=0;i<3;i++)
        {
            tempChar=ifs->get();
            if(IDictionary::isNumber16(tempChar))
            {
                str+=tempChar;
            }
            else
            {
                if(i==0)
                    str=str.substr(0,base_len);
                break;
            }
        }
    }
    else if(IDictionary::isNumber8(tempChar))
    {
        str+=tempChar;
        for(int i=0;i<2;i++)
        {
            tempChar=ifs->get();
            if(IDictionary::isNumber8(tempChar))
            {
                str+=tempChar;
            }
            else
            {
                break;
            }
        }
    }
    return str.length()-base_len;
}
