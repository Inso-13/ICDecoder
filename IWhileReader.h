//
// Created by Inso on 2021/3/13.
//

#ifndef ICDECODER_IWHILEREADER_H
#define ICDECODER_IWHILEREADER_H

#include "IBoolReader.h"

class IWhileReader : public IBoolReader{
public:
    IWhileReader(std::ifstream* ifs, std::ostream* os, int deep): IBoolReader(ifs, os, deep,"while"){}
};


#endif //ICDECODER_IWHILEREADER_H
