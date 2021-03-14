//
// Created by Inso on 2021/3/13.
//

#include "IIfAllReader.h"

void IIfAllReader::getWord(std::string &str) {
    int base_len=str.length();
    int base_pos=m_ifs->tellg();
    int temp_len;
    char tempChar;

    IBoolReader::getBlock(m_ifs,str,"if");
    setPos(base_pos+str.length());

    if(str.length()-base_len) {
        while (true) {
            while(IDictionary::isBlankSep(tempChar=m_ifs->get()))
            {
                str+=tempChar;
                if(tempChar=='\n')
                    str+='\n';
            }
            setPos(base_pos+str.length());

            temp_len=str.length();

            IBoolReader::getBlock(m_ifs, str, "else if");
            setPos(base_pos+str.length());
            if(temp_len==str.length())
                break;
        }
        while(IDictionary::isBlankSep(tempChar=m_ifs->get()))
        {
            str+=tempChar;
            if(tempChar=='\n')
                str+='\n';
        }
        setPos(base_pos+str.length());

        IBoolReader::getBlock(m_ifs, str, "else", false);
    }
}

bool IIfAllReader::forward(int base_pos, int end_pos) {
    IIfReader iIfReader(m_ifs,m_os,m_deep+1);
    IElseIfReader iElseIfReader(m_ifs,m_os,m_deep+1);
    IElseReader iElseReader(m_ifs,m_os,m_deep+1);

    if(iIfReader.read())
    {
        while (iElseIfReader.read());
        iElseReader.read();
        return true;
    }
    else
        return false;
}
