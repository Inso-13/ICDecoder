//
// Created by Inso on 2021/3/14.
//

#include "ICallReader.h"

void ICallReader::getWord(std::string &str) {
    char tempChar;

    while((tempChar=m_ifs->get())!=EOF)
    {
        if(!IDictionary::isLetterOrNumberOrDL(tempChar))
            break;
        str+=tempChar;
    }
    if(IDictionary::fun.find(str)==IDictionary::fun.end())
    {
        str="";
        return;
    }
    else
        m_funName=str;
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
    }while((tempChar=m_ifs->get())!=EOF);

    if(tempChar=='(')
        str+=tempChar;
    else
    {
        str="";
        return;
    }

    while((tempChar=m_ifs->get())!=EOF)
    {
        str+=tempChar;
        if(tempChar==')')
            break;
    }
}

bool ICallReader::forward(int base_pos, int end_pos) {
    ISentenceReader iSentenceReader2(m_ifs,m_os,m_deep+1,')');
    ISentenceReader iSentenceReader3(m_ifs,m_os,m_deep+1,',');
    ISingleCharReader iBracket1lReader(m_ifs, m_os, m_deep + 1,'(',"Bracket1l");
    ISingleStringReader iFunReader(m_ifs, m_os, m_deep + 1,m_funName,"Function");

    if(!iFunReader.read())
        return false;
    if(!iBracket1lReader.read())
        return false;
    while(iSentenceReader3.read());

    return iSentenceReader2.read();
}
