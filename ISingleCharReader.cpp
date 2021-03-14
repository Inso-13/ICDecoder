//
// Created by Inso on 2021/3/12.
//

#include "ISingleCharReader.h"

void ISingleCharReader::getWord(std::string &str) {
    char tempChar;
    if((tempChar = this->m_ifs->get()) != EOF)
    {
        if(tempChar==m_char)
        {
            str+=tempChar;
        }
    }
}
