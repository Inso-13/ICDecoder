//
// Created by Inso on 2021/3/13.
//

#include "IForReader.h"

void IForReader::getWord(std::string &str) {
    IBoolReader::getBlock(m_ifs,str,"for");
}

bool IForReader::forward(int base_pos, int end_pos) {
    IBlockReader iBlockReader(m_ifs,m_os,m_deep+1);
    ISentenceReader iSentenceReader(m_ifs,m_os,m_deep+1);
    ISentenceReader iSentenceReader2(m_ifs,m_os,m_deep+1,')');
    ISingleCharReader iBracket1lReader(m_ifs, m_os, m_deep + 1,'(',"Bracket1l");
    ISingleStringReader iForStringReader(m_ifs, m_os, m_deep + 1,"for");

    if(!iForStringReader.read())
        return false;
    if(!iBracket1lReader.read())
        return false;

    if(!iSentenceReader.read())
        return false;
    if(!iSentenceReader.read())
        return false;
    if(!iSentenceReader2.read())
        return false;

    return !(!iBlockReader.read() && !iSentenceReader.read());
}
