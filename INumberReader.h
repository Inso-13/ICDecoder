//
// Created by Inso on 2021/3/11.
//

#ifndef ICDECODER_INUMBERREADER_H
#define ICDECODER_INUMBERREADER_H


#include "IAbstractReader.h"
#include "INumberJudger.h"

class INumberReader : public IAbstractReader{
private:
    void getWord(std::string &str) override;
public:
    explicit INumberReader(std::ifstream* ifs,std::ostream* os,int deep) : IAbstractReader(ifs, os, deep) {
        m_dataType = "Number";
    }
};


#endif //ICDECODER_INUMBERREADER_H
