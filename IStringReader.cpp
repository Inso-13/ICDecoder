//
// Created by Inso on 2021/3/12.
//

#include "IStringReader.h"

void IStringReader::getWord(std::string &str) {
    char tempChar;
    int base_len=str.length();

    if((tempChar=m_ifs->get())!=EOF)
    {
        if(IDictionary::isQuotation2(tempChar))
        {
            str+=tempChar;
            while((tempChar=m_ifs->get())!=EOF)
            {
                if(IDictionary::isQuotation2(tempChar))
                {
                    str+=tempChar;
                    break;
                }
                else if(IDictionary::isQuotation1(tempChar))
                {
                    str=str.substr(0,base_len);

                    std::cerr<<"string_error";
                }
                else if(IDictionary::isSlash(tempChar))
                {
                    str+=tempChar;

                    int temp_pos=m_ifs->tellg();
                    int temp=ICharReader::readSpecialChar(m_ifs,str);
                    if(!temp)
                    {
                        str=str.substr(0,base_len);
                    }
                }
                else
                {
                    str+=tempChar;
                }
            }
        }
    }
}
