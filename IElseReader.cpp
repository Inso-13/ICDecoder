//
// Created by Inso on 2021/3/13.
//

#include "IElseReader.h"

void IElseReader::getWord(std::string &str) {
    char tempChar;
    int num_3l;

    for(int i=0;i<4;i++)
    {
        tempChar=m_ifs->get();
        str+=tempChar;
    }
    if(str!="else") {
        str = "";
        return;
    }
    while(true)
    {
        tempChar=m_ifs->get();
        if(IDictionary::isBlankSep(tempChar))
        {
            str+=tempChar;
            if(tempChar=='\n')
                str+='\n';
        }
        else
            break;
    }

    if(tempChar=='{')
    {
        str+=tempChar;
        num_3l=1;

        while ((tempChar=m_ifs->get())!=EOF&&num_3l)
        {
            str+=tempChar;
            if(tempChar=='\n')
            {
                str+='\n';
            }
            else if(tempChar=='}')
                num_3l--;
        }
    }
    else if(tempChar==';')
    {
        str+=tempChar;
        return;
    }
    else
    {
        do{
            str+=tempChar;
            tempChar=m_ifs->get();
        }while (tempChar!=';');
    }
}

bool IElseReader::forward(int base_pos, int end_pos) {
    IBlockReader iBlockReader(m_ifs,m_os,m_deep+1);
    ISentenceReader iSentenceReader(m_ifs,m_os,m_deep+1);
    ISingleStringReader iElseStringReader(m_ifs, m_os, m_deep + 1,"else");

    if(!iElseStringReader.read())
        return false;

    return !(!iBlockReader.read() && !iSentenceReader.read());
}


