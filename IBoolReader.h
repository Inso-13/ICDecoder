//
// Created by Inso on 2021/3/13.
//

#ifndef ICDECODER_IBOOLREADER_H
#define ICDECODER_IBOOLREADER_H


#include "IAbstractReader.h"
#include "ISingleCharReader.h"
#include "ISingleStringReader.h"
#include "ISentenceReader.h"
#include "IBlockReader.h"

class IBoolReader : public IAbstractReader{
private:
    void getWord(std::string &str) override;
    std::string m_name;

public:
    explicit IBoolReader (std::ifstream* ifs, std::ostream* os, int deep,std::string name) : IAbstractReader(ifs, os, deep,true) {
        m_name = name;
        m_dataType = name + " Block";
    }
    bool forward(int base_pos, int end_pos) override;
    static void getBlock(std::ifstream* ifs,std::string& str,const std::string& blockName,bool type= true);
};

#endif //ICDECODER_IBOOLREADER_H
