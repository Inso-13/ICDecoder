//
// Created by Inso on 2021/3/13.
//

#ifndef ICDECODER_IIFALLREADER_H
#define ICDECODER_IIFALLREADER_H

#include "IAbstractReader.h"
#include "IIfReader.h"
#include "IElseIfReader.h"
#include "IElseReader.h"

class IIfAllReader : public IAbstractReader{
private:
    void getWord(std::string &str) override;
public:
    explicit IIfAllReader (std::ifstream* ifs, std::ostream* os, int deep) : IAbstractReader(ifs, os, deep, true) {
        m_dataType = "Whole \'If\' Block";
    }
    bool forward(int base_pos, int end_pos) override;
};

#endif //ICDECODER_IIFALLREADER_H
