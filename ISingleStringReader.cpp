//
// Created by Inso on 2021/3/13.
//

#include "ISingleStringReader.h"

void ISingleStringReader::getWord(std::string &str) {
    char tempChar;

    while((tempChar = this->m_ifs->get()) != EOF)
    {
        if(IDictionary::isLetter(tempChar)||tempChar==' ')
        {
            str+=tempChar;
        }
        else
            break;
    }
    if(str!=m_str)
        str="";
}
