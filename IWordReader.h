//
// Created by Inso on 2021/3/11.
//

#ifndef ICDECODER_IWORDREADER_H
#define ICDECODER_IWORDREADER_H

#include "IAbstractReader.h"
#include "IDictionary.h"

class IWordReader : public IAbstractReader{
private:
    void getWord(std::string &str) override;
    std::string m_last_id;

public:
    bool m_isNew;
    explicit IWordReader(std::ifstream* ifs,std::ostream* os,int deep): IAbstractReader(ifs, os, deep) {
        m_dataType = "Identifier";
        m_last_id = "";
        m_isNew= false;
    }
    std::string getDataType() {
        std::string tempStr=m_dataType;
        m_dataType="Identifier";
        return tempStr;
    }
    void setDataType(std::string dt)
    {
        m_dataType = dt;
    }
    std::string getLastId() {
        return m_last_id;
    }
};


#endif //ICDECODER_IWORDREADER_H
