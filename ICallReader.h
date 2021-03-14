//
// Created by Inso on 2021/3/14.
//

#ifndef ICDECODER_ICALLREADER_H
#define ICDECODER_ICALLREADER_H


#include "IAbstractReader.h"
#include "ISentenceReader.h"
#include "ISingleStringReader.h"

class ICallReader : public IAbstractReader{
private:
    std::string m_funName;
    void getWord(std::string &str) override;
public:
    explicit ICallReader(std::ifstream* ifs,std::ostream* os,int deep) : IAbstractReader(ifs, os, deep) {
        m_dataType = "Function Call";
        m_funName = "";
    }
    bool forward(int base_pos, int end_pos) override;
};

#endif //ICDECODER_ICALLREADER_H
