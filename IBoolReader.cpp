//
// Created by Inso on 2021/3/13.
//

#include "IBoolReader.h"

void IBoolReader::getWord(std::string &str) {
    getBlock(m_ifs,str,m_name);
}

bool IBoolReader::forward(int base_pos, int end_pos) {
    IBlockReader iBlockReader(m_ifs,m_os,m_deep+1);
    ISentenceReader iSentenceReader(m_ifs,m_os,m_deep+1);
    ISentenceReader iSentenceReader2(m_ifs,m_os,m_deep+1,')');
    ISingleCharReader iBracket1lReader(m_ifs, m_os, m_deep + 1,'(',"Bracket1l");
    ISingleStringReader iBoolStringReader(m_ifs, m_os, m_deep + 1,m_name);

    if(!iBoolStringReader.read())
        return false;
    if(!iBracket1lReader.read())
        return false;

    if(!iSentenceReader2.read())
        return false;

    return !(!iBlockReader.read() && !iSentenceReader.read());
}

void IBoolReader::getBlock(std::ifstream* ifs,std::string &str, const std::string &blockName, bool type) {
    char tempChar;
    int num_3l;
    int base_len = str.length();

    for(int i=0;i<blockName.length();i++)
    {
        tempChar=ifs->get();
        str+=tempChar;
    }
    if(str.substr(str.length()-blockName.length(),blockName.length())!=blockName) {
        str = str.substr(0,base_len);
        return;
    }

    while((tempChar=ifs->get())!=EOF)
    {
        str+=tempChar;
        if(!IDictionary::isBlankSep(tempChar))
            break;
        if(tempChar=='\n')
            str+='\n';
    }

    if(type)
    {
        if (tempChar != '(') {
            str = str.substr(0, base_len);
            return;
        }
        while ((tempChar = ifs->get()) != EOF) {
            str += tempChar;
            if (tempChar == ')')
                break;
        }
        while (true) {
            tempChar = ifs->get();
            if (IDictionary::isBlankSep(tempChar)) {
                str += tempChar;
                if (tempChar == '\n')
                    str += '\n';
            } else
                break;
        }
    }

    if(tempChar=='{')
    {
        if(type)
            str+=tempChar;
        num_3l=1;

        while ((tempChar=ifs->get())!=EOF&&num_3l)
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
            tempChar=ifs->get();
        }while (tempChar!=';');
    }
}
