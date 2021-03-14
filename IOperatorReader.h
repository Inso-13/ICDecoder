//
// Created by Inso on 2021/3/11.
//

#ifndef ICDECODER_IOPERATORREADER_H
#define ICDECODER_IOPERATORREADER_H

#include "IAbstractReader.h"
#include "ITypeReader.h"
#include "ISingleCharReader.h"

class IOperatorReader : public IAbstractReader{
private:
    int m_type;
    void getWord(std::string &str) override;
public:
    void setType(int type) {
        m_type=type;
    }

    int getType() {
        int temp=m_type;
        m_type=0;
        return temp;
    }

    explicit IOperatorReader(std::ifstream* ifs,std::ostream* os,int deep) : IAbstractReader(ifs, os, deep) {
        m_type = 0;
        m_dataType = "Operator";
    }
};

#endif //ICDECODER_IOPERATORREADER_H
