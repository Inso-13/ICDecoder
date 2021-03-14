//
// Created by Inso on 2021/3/12.
//

#ifndef ICDECODER_ISTRINGREADER_H
#define ICDECODER_ISTRINGREADER_H

#include "IAbstractReader.h"
#include "ICharReader.h"

class IStringReader : public IAbstractReader{
private:
    void getWord(std::string &str) override;
public:
    explicit IStringReader(std::ifstream* ifs,std::ostream* os,int deep) : IAbstractReader(ifs, os, deep) {
        m_dataType = "Const String";
    }
};

#endif //ICDECODER_ISTRINGREADER_H
