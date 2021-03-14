//
// Created by Inso on 2021/3/13.
//

#ifndef ICDECODER_ISINGLESTRINGREADER_H
#define ICDECODER_ISINGLESTRINGREADER_H


#include "IAbstractReader.h"

class ISingleStringReader : public IAbstractReader{
private:
    std::string m_str;

    void getWord(std::string &str) override;
public:
    explicit ISingleStringReader (std::ifstream* ifs, std::ostream* os, int deep,std::string str,std::string dataType="Keyword"): IAbstractReader(ifs, os, deep) {
        m_dataType = dataType;
        m_str = str;
    }
};

#endif //ICDECODER_ISINGLESTRINGREADER_H
