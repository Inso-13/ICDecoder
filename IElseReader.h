//
// Created by Inso on 2021/3/13.
//

#ifndef ICDECODER_IELSEREADER_H
#define ICDECODER_IELSEREADER_H

#include "IAbstractReader.h"
#include "ISingleStringReader.h"
#include "ISentenceReader.h"
#include "IBlockReader.h"

class IElseReader : public IAbstractReader{
private:
    void getWord(std::string &str) override;
public:
    explicit IElseReader (std::ifstream* ifs, std::ostream* os, int deep) : IAbstractReader(ifs, os, deep, true) {
        m_dataType = "\'Else\' Block";
    }
    bool forward(int base_pos, int end_pos) override;
};
#endif //ICDECODER_IELSEREADER_H
