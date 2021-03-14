//
// Created by Inso on 2021/3/13.
//

#ifndef ICDECODER_IIFREADER_H
#define ICDECODER_IIFREADER_H

#include "IBoolReader.h"

class IIfReader : public IBoolReader{
public:
    IIfReader(std::ifstream* ifs, std::ostream* os, int deep): IBoolReader(ifs, os, deep,"if"){}
};

#endif //ICDECODER_IIFREADER_H
