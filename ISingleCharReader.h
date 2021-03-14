//
// Created by Inso on 2021/3/12.
//

#ifndef ICDECODER_ISINGLECHARREADER_H
#define ICDECODER_ISINGLECHARREADER_H

#include "IAbstractReader.h"
#include "IDictionary.h"
class ISingleCharReader : public IAbstractReader{
private:
    char m_char;

    void getWord(std::string &str) override;
public:
    explicit ISingleCharReader (std::ifstream* ifs, std::ostream* os, int deep,char ch,std::string dataType="SingleChar"): IAbstractReader(ifs, os, deep) {
        m_dataType = dataType;
        m_char = ch;
    }
};


#endif //ICDECODER_ISINGLECHARREADER_H
