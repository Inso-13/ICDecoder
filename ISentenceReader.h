//
// Created by Inso on 2021/3/11.
//

#ifndef ICDECODER_ISENTENCEREADER_H
#define ICDECODER_ISENTENCEREADER_H

#include <vector>
#include "IAbstractReader.h"
#include "IDictionary.h"
#include "IWordReader.h"
#include "INumberReader.h"
#include "IOperatorReader.h"
#include "ITypeReader.h"
#include "ISingleCharReader.h"
#include "ICharReader.h"
#include "IStringReader.h"
#include "ICallReader.h"

class ISentenceReader : public IAbstractReader{
private:
    void getWord(std::string &str) override;
    bool m_isDefine;
    char m_seg;
    std::string m_defining;
    enum State
    {
        STATE_BEGIN,
        STATE_LEFT_WAIT,
        STATE_LEFT_OR_RIGHT,
        STATE_LEFT_OR_RIGHT_OR_NULL,
        STATE_LEFT_ID_WAIT,
        STATE_LEFT_OVER,
        STATE_RIGHT_OVER,
        STATE_END,
    };
public:
    explicit ISentenceReader(std::ifstream* ifs,std::ostream* os,int deep,char seg=';') : IAbstractReader(ifs, os, deep) {
        m_dataType = "Sentence";
        m_isDefine = false;
        m_defining = "";
        m_seg=seg;
    }
    bool forward(int base_pos, int end_pos) override;
};


#endif //ICDECODER_ISENTENCEREADER_H
