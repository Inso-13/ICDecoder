//
// Created by Inso on 2021/3/11.
//

#ifndef ICDECODER_IABSTRACTREADER_H
#define ICDECODER_IABSTRACTREADER_H
#include <iostream>
#include <fstream>
#include <set>
#include <iomanip>
#include "IDictionary.h"
class IAbstractReader{
private:
    virtual void getWord(std::string& str) = 0;
    bool m_silence;

protected:
    int m_deep;
    std::string m_dataType;
    std::ifstream* m_ifs;
    std::ostream* m_os;
    int prepare();

public:
    explicit IAbstractReader(std::ifstream* ifs, std::ostream* os, int deep,bool silence= false);
    bool readOver(int end_pos) {
        return end_pos-1 == m_ifs->tellg();
    }
    void setPos(int pos){
        if(m_ifs->tellg()==EOF)
            m_ifs->clear();
        m_ifs->seekg(pos,std::ios::beg);
    }

    bool read();

    int readBase(std::string& str);
    virtual bool forward(int base_pos,int end_pos);
};


#endif //ICDECODER_IABSTRACTREADER_H
