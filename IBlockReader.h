//
// Created by Inso on 2021/3/13.
//

#ifndef ICDECODER_IBLOCKREADER_H
#define ICDECODER_IBLOCKREADER_H


#include "IAbstractReader.h"
#include "ISentenceReader.h"

class IBlockReader : public IAbstractReader{
private:
    void getWord(std::string &str) override;
    bool m_hasChild;
public:
    explicit IBlockReader(std::ifstream* ifs,std::ostream* os,int deep) : IAbstractReader(ifs, os, deep, true) {
        m_dataType = "Block";
        m_hasChild = false;
    }
    bool forward(int base_pos, int end_pos) override;
};

#endif //ICDECODER_IBLOCKREADER_H
