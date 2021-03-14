//
// Created by Inso on 2021/3/11.
//

#include "INumberReader.h"
void INumberReader::getWord(std::string &str) {
    INumberJudger iNumberJudger;
    std::string tempStr;
    char tempChar;
    while((tempChar = this->m_ifs->get()) != EOF)
    {
        if(IDictionary::isRealNumberContext(tempChar))
        {
            tempStr+=tempChar;
        }
        else
        {
            break;
        }
    }
    int maxLen=tempStr.length();
    for(int i=0;i<maxLen;i++)
    {
        str=tempStr.substr(0,maxLen-i);
        if(iNumberJudger.isNumber(str))
        {
            break;
        }
    }
}
