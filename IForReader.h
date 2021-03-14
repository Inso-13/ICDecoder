//
// Created by Inso on 2021/3/13.
//

#ifndef ICDECODER_IFORREADER_H
#define ICDECODER_IFORREADER_H


#include "IAbstractReader.h"
#include "ISingleStringReader.h"
#include "ISingleCharReader.h"
#include "ISentenceReader.h"
#include "IBlockReader.h"
#include "IBoolReader.h"

class IForReader : public IAbstractReader{
private:
    void getWord(std::string &str) override;
public:
    explicit IForReader(std::ifstream* ifs,std::ostream* os,int deep) : IAbstractReader(ifs, os, deep, true) {
        m_dataType = "\'For\' Block";
    }
    bool forward(int base_pos, int end_pos) override;
};

#endif //ICDECODER_IFORREADER_H
