//
// Created by Inso on 2021/3/12.
//

#ifndef ICDECODER_ICHARREADER_H
#define ICDECODER_ICHARREADER_H

#include "IAbstractReader.h"

class ICharReader : public IAbstractReader{
private:
    void getWord(std::string &str) override;
public:
    explicit ICharReader(std::ifstream* ifs,std::ostream* os,int deep) : IAbstractReader(ifs, os, deep) {
        m_dataType = "Char";
    }
    static int readSpecialChar(std::ifstream* ifs,std::string &str);
};

#endif //ICDECODER_ICHARREADER_H
