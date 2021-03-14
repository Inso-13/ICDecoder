//
// Created by Inso on 2021/3/11.
//

#include "ISentenceReader.h"

bool ISentenceReader::forward(int base_pos, int end_pos) {
    std::vector<int> states;

    IWordReader iWordReader(m_ifs,m_os,m_deep+1);
    INumberReader iNumberReader(m_ifs,m_os,m_deep+1);
    IOperatorReader iOperatorReader(m_ifs,m_os,m_deep+1);
    ITypeReader iTypeReader(m_ifs,m_os,m_deep+1);
    ISingleCharReader iSegReader(m_ifs, m_os, m_deep + 1,m_seg,"Segment");
    ISingleCharReader iBracket1lReader(m_ifs, m_os, m_deep + 1,'(',"Bracket1l");
    ISingleCharReader iBracket1rReader(m_ifs, m_os, m_deep + 1,')',"Bracket1r");
    ISingleCharReader iBracket2lReader(m_ifs, m_os, m_deep + 1,'[',"Bracket2l");
    ISingleCharReader iBracket2rReader(m_ifs, m_os, m_deep + 1,']',"Bracket2r");
    ISingleCharReader iBracket3lReader(m_ifs, m_os, m_deep + 1,'{',"Bracket3l");
    ISingleCharReader iBracket3rReader(m_ifs, m_os, m_deep + 1,'}',"Bracket3r");
    ICharReader iCharReader(m_ifs,m_os,m_deep+1);
    IStringReader iStringReader(m_ifs,m_os,m_deep+1);
    ICallReader iCallReader(m_ifs,m_os,m_deep+1);
    State cur_state = STATE_BEGIN;

    while (true)
    {
        if(cur_state==STATE_BEGIN)
        {
            if(iTypeReader.read())
            {
                cur_state=STATE_LEFT_ID_WAIT;
                m_isDefine= true;
            }
            else if(iCallReader.read())
                cur_state=STATE_RIGHT_OVER;
            else if(iWordReader.read())
            {
                if(iWordReader.m_isNew)
                {
                    std::cerr<<"Undefined Symbol: "<<iWordReader.getLastId();
                    return false;
                }
                cur_state=STATE_LEFT_OVER;
            }
            else if(iCharReader.read()||iNumberReader.read()||iStringReader.read())
                cur_state=STATE_RIGHT_OVER;
            else if(iOperatorReader.read())
            {
                int operator_type = iOperatorReader.getType();
                if(operator_type&2)
                {
                    cur_state=STATE_LEFT_WAIT;
                }
                else
                {
                    std::cerr<<"error!";
                    return false;
                }
            }
            else if(iBracket1lReader.read())
            {
                states.push_back(1);
                cur_state=STATE_LEFT_OR_RIGHT;
            }
            else if(iSegReader.read())
            {
                cur_state=STATE_END;
            }
            else
            {
                std::cerr<<"error!";
                return false;
            }
        }
        else if(cur_state==STATE_END)
        {
            return true;
        }
        else if(cur_state==STATE_LEFT_OVER)
        {
            if(iSegReader.read()&&states.empty())
                cur_state=STATE_END;
            else if(iOperatorReader.read())
            {
                int operator_type = iOperatorReader.getType();
                if(operator_type&1)
                {
                    cur_state=STATE_LEFT_OVER;
                }
                else if(operator_type&4)
                {
                    if(operator_type&8&&m_seg==',')
                        cur_state=STATE_END;
                    else if(operator_type&8&&m_isDefine&&states.empty())
                        cur_state=STATE_LEFT_ID_WAIT;
                    else
                        cur_state=STATE_LEFT_OR_RIGHT;
                }
                else
                {
                    std::cerr<<"error!";
                    return false;
                }
            }
            else if(iBracket2lReader.read())
            {
                if(m_isDefine&&states.empty())
                {
                    IDictionary::addPointer(m_defining);
                    cur_state=STATE_LEFT_OR_RIGHT_OR_NULL;
                }
                else
                {
                    cur_state=STATE_LEFT_OR_RIGHT;
                }
                states.push_back(2);
            }
            else if(iBracket1rReader.read())
            {
                if(states.empty()&&m_seg==')')
                {
                    cur_state=STATE_END;
                }
                else if(states.back()==1)
                {
                    cur_state=STATE_LEFT_OVER;
                    states.pop_back();
                }
                else
                {
                    std::cerr<<"Bracket mismatch";
                }
            }
            else if(iBracket2rReader.read())
            {
                if(states.back()==2)
                {
                    cur_state=STATE_LEFT_OVER;
                    states.pop_back();
                }
                else
                {
                    std::cerr<<"Bracket mismatch";
                }
            }
            else if(iBracket3rReader.read())
            {
                if(states.back()==3)
                {
                    cur_state=STATE_LEFT_OVER;
                    states.pop_back();
                }
                else
                {
                    std::cerr<<"Bracket mismatch";
                }
            }
            else
            {
                std::cerr<<"error!";
                return false;
            }
        }
        else if(cur_state==STATE_RIGHT_OVER)
        {
            if(iSegReader.read()&&states.empty())
                cur_state=STATE_END;
            else if(iOperatorReader.read())
            {
                int operator_type = iOperatorReader.getType();
                if(operator_type&4)
                {
                    if(operator_type&8&&m_seg==',')
                        cur_state=STATE_END;
                    else if(operator_type&8&&m_isDefine&&states.empty())
                        cur_state=STATE_LEFT_ID_WAIT;
                    else
                        cur_state=STATE_LEFT_OR_RIGHT;
                }
                else
                {
                    std::cerr<<"error!";
                    return false;
                }
            }
            else if(iBracket1rReader.read())
            {
                if(states.empty()&&m_seg==')')
                {
                    cur_state=STATE_END;
                }
                else if(states.back()==1)
                {
                    cur_state=STATE_RIGHT_OVER;
                    states.pop_back();
                }
                else
                {
                    std::cerr<<"Bracket mismatch";
                }
            }
            else if(iBracket2rReader.read())
            {
                if(states.back()==2)
                {
                    cur_state=STATE_RIGHT_OVER;
                    states.pop_back();
                }
                else
                {
                    std::cerr<<"Bracket mismatch";
                }
            }
            else if(iBracket3rReader.read())
            {
                if(states.back()==3)
                {
                    cur_state=STATE_RIGHT_OVER;
                    states.pop_back();
                }
                else
                {
                    std::cerr<<"Bracket mismatch";
                }
            }
            else
            {
                std::cerr<<"error!";
                return false;
            }
        }
        else if(cur_state==STATE_LEFT_WAIT)
        {
            if(iWordReader.read())
            {
                if(iWordReader.m_isNew)
                {
                    std::cerr<<"Undefined Symbol: "<<iWordReader.getLastId();
                    return false;
                }
                cur_state=STATE_LEFT_OVER;
            }
            else if(iBracket1lReader.read())
            {
                states.push_back(1);
                cur_state=STATE_LEFT_WAIT;
            }
            else
            {
                std::cerr<<"error!";
                return false;
            }
        }
        else if(cur_state==STATE_LEFT_ID_WAIT)
        {
            if(iWordReader.read())
            {
                cur_state=STATE_LEFT_OVER;
                if(iWordReader.m_isNew)
                {
                    m_defining = iWordReader.getLastId();
                    IDictionary::dic.insert(std::make_pair(m_defining,iTypeReader.getLastType()));
                }
                else
                {
                    std::cerr<<"Multiple definitions for "<<iWordReader.getLastId();
                    return false;
                }
            }
            else
            {
                std::cerr<<"error!";
                return false;
            }
        }
        else if(cur_state==STATE_LEFT_OR_RIGHT)
        {
            if(iCallReader.read())
                cur_state=STATE_RIGHT_OVER;
            else if(iWordReader.read())
            {
                if(iWordReader.m_isNew)
                {
                    std::cerr<<"Undefined Symbol: "<<iWordReader.getLastId();
                    return false;
                }
                cur_state=STATE_LEFT_OVER;
            }
            else if(iCharReader.read()||iNumberReader.read()||iStringReader.read())
                cur_state=STATE_RIGHT_OVER;
            else if(iOperatorReader.read())
            {
                int operator_type = iOperatorReader.getType();
                if(operator_type&2)
                {
                    cur_state=STATE_LEFT_OR_RIGHT;
                }
                else
                {
                    std::cerr<<"error!";
                    return false;
                }
            }
            else if(iBracket1lReader.read())
            {
                states.push_back(1);
                cur_state=STATE_LEFT_OR_RIGHT;
            }
            else if(iBracket3lReader.read())
            {
                states.push_back(3);
                cur_state=STATE_LEFT_OR_RIGHT;
            }
            else
            {
                std::cerr<<"error!";
                return false;
            }
        }
        else if(cur_state==STATE_LEFT_OR_RIGHT_OR_NULL)
        {
            if(iWordReader.read())
            {
                if(iWordReader.m_isNew)
                {
                    std::cerr<<"Undefined Symbol: "<<iWordReader.getLastId();
                    return false;
                }
                cur_state=STATE_LEFT_OVER;
            }
            else if(iCharReader.read()||iNumberReader.read())
                cur_state=STATE_RIGHT_OVER;
            else if(iOperatorReader.read())
            {
                int operator_type = iOperatorReader.getType();
                if(operator_type&2)
                {
                    cur_state=STATE_LEFT_OR_RIGHT;
                }
                else
                {
                    std::cerr<<"error!";
                    return false;
                }
            }
            else if(iBracket1lReader.read())
            {
                states.push_back(1);
                cur_state=STATE_LEFT_OR_RIGHT;
            }
            else if(iBracket3lReader.read())
            {
                states.push_back(3);
                cur_state=STATE_LEFT_OR_RIGHT;
            }
            else if(iBracket2rReader.read())
            {
                if(states.back()==2)
                {
                    cur_state=STATE_LEFT_OVER;
                    states.pop_back();
                }
                else
                {
                    std::cerr<<"Bracket mismatch";
                }
            }
            else
            {
                std::cerr<<"error!";
                return false;
            }
        }
    }
}

void ISentenceReader::getWord(std::string &str) {
    char tempChar;
    int num3=0;

    while((tempChar = m_ifs->get()) != EOF)
    {
        if(tempChar!=m_seg)
        {
            str+=tempChar;
            if(tempChar=='\n')
            {
                str+='\n';
            }
            else if(tempChar=='{')
                num3++;
            else if(tempChar=='}')
                num3--;
            if(num3<0)
            {
                str="";
                return;
            }
        }
        else
        {
            str+=tempChar;
            return;
        }
    }
    if(!str.empty()&&str[str.length()-1]!=m_seg)
    {
        str="";
    }
}
