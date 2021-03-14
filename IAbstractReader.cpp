//
// Created by Inso on 2021/3/11.
//

#include "IAbstractReader.h"

int IAbstractReader::readBase(std::string& str) {
    int ret=0;
    str.clear();
    ret+=prepare();
    int base_pos = m_ifs->tellg();
    getWord(str);
    if(!str.length())
    {
        setPos(base_pos);
        return 0;
    }
    ret+=str.length();
    setPos(base_pos+str.length());
    return ret;
}

IAbstractReader::IAbstractReader(std::ifstream* ifs, std::ostream* os, int deep,bool silence) {
    m_silence = silence;
    m_ifs = ifs;
    m_deep = deep;
    m_os = os;
    m_dataType = "Object";
}

int IAbstractReader::prepare() {
    char tempChar;
    int ret=0;
    int cur_pos = m_ifs->tellg();

    while((tempChar = m_ifs->get()) != EOF)
    {
        if (tempChar=='\n')
        {
            ret+=2;
        }
        else if(IDictionary::isBlankSep(tempChar))
        {
            ret++;
        }
        else if(tempChar=='\\')
        {
            tempChar=m_ifs->get();
            if(tempChar=='\n')
                ret+=3;
            else
                break;
        }
        else
            break;
    }
    setPos(cur_pos+ret);
    return ret;
}


bool IAbstractReader::read() {
    std::string str;

    int base_pos = m_ifs->tellg();
    int len=readBase(str);
    if(!len)
        return false;
    int end_pos = base_pos+len;

    for(int i=0;i<m_deep;i++)
        *m_os<<"\t";
//        std::cout<<"\t\t      ";
//    *m_os << std::setw(20);
    m_os->setf(std::ios_base::left);
    *m_os << m_dataType<<": ";

    if(!m_silence)
    {
        bool dbFlag=0;
        for(auto ch:str)
        {
            if(ch=='\n'&&dbFlag==0)
                dbFlag=1;
            else if(ch=='\n'&&dbFlag==1)
            {
                dbFlag=0;
                continue;
            }
            *m_os<<ch;
        }
    }
    *m_os << std::endl;
    setPos(base_pos);
    if(forward(base_pos,end_pos))
    {
        setPos(end_pos);
        return true;
    }
    else
    {
        setPos(base_pos);
        return false;
    }
}

bool IAbstractReader::forward(int base_pos, int end_pos) {
    setPos(end_pos);
    return true;
}

