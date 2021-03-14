//
// Created by Inso on 2021/3/13.
//

#include "IBlockReader.h"

void IBlockReader::getWord(std::string &str) {
    char tempChar;
    int num_3l;

    tempChar=m_ifs->get();
    if(tempChar=='{')
    {
        str+=tempChar;
        m_hasChild= true;
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
}

bool IBlockReader::forward(int base_pos, int end_pos) {
    ISentenceReader iSentenceReader(m_ifs,m_os,m_deep+1);
    IBlockReader iBlockReader(m_ifs,m_os,m_deep+1);
    ISingleCharReader iBracket3lReader(m_ifs, m_os, m_deep + 1,'{',"Bracket3l");
    ISingleCharReader iBracket3rReader(m_ifs, m_os, m_deep + 1,'}',"Bracket3r");
    setPos(base_pos);
    if(iBracket3lReader.read())
    {
        if(!iBlockReader.read())
        {
            while(iSentenceReader.read());
        }
        if(!iBracket3rReader.read())
        {
            std::cerr<<"Illegal Block";
            return false;
        }
        return true;
    }
    return false;
}
