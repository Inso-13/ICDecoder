//
// Created by Inso on 2021/3/11.
//

#ifndef ICDECODER_ITYPEREADER_H
#define ICDECODER_ITYPEREADER_H


#include "IAbstractReader.h"

class ITypeReader : public IAbstractReader{
private:
    void getWord(std::string &str) override;
    std::string m_last;
public:
    explicit ITypeReader(std::ifstream* ifs,std::ostream* os,int deep) : IAbstractReader(ifs, os, deep) {
        m_dataType = "Type";
        m_last="";
    }
    std::string getLastType() {
        return m_last;
    }
};

#endif //ICDECODER_ITYPEREADER_H
