//
// Created by Inso on 2021/3/13.
//

#ifndef ICDECODER_IELSEIFREADER_H
#define ICDECODER_IELSEIFREADER_H

#include "IBoolReader.h"

class IElseIfReader : public IBoolReader{
public:
    IElseIfReader(std::ifstream* ifs, std::ostream* os, int deep): IBoolReader(ifs, os, deep,"else if"){}
};

#endif //ICDECODER_IELSEIFREADER_H
