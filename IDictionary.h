//
// Created by Inso on 2021/3/11.
//

#ifndef ICDECODER_IDICTIONARY_H
#define ICDECODER_IDICTIONARY_H
#include <set>
#include <string>
#include <vector>
#include <map>

class IDictionary {
private:
public:
    static bool isBlankSep(char ch);
    static bool isSentenceSep(char ch);
    static bool isLetter(char ch);
    static bool isLetterOrDL(char ch);
    static bool isNumber(char ch);
    static bool isNumber8(char ch);
    static bool isNumber16(char ch);
    static bool isLetterOrNumber(char ch);
    static bool isOperator(char ch);
    static bool isOperator0(std::string str);
    static bool isOperator1(std::string str);
    static bool isOperator2(std::string str);
    static bool isBaseType(std::string str);
    static bool isLetterOrNumberOrDL(char ch);
    static bool isRealNumberContext(char ch);
    static bool isBracket1l(char ch);
    static bool isBracket1r(char ch);
    static bool isBracket2l(char ch);
    static bool isBracket2r(char ch);
    static bool isQuestion(char ch);
    static bool isColon(char ch);
    static bool isQuotation1(char ch);
    static bool isQuotation2(char ch);
    static bool isSlash(char ch);
    static bool isSimpleTransfer(char ch);
    static void addPointer(std::string str);
    static std::map<std::string,std::string> dic;
    static std::map<std::string,std::string> fun;
};


#endif //ICDECODER_IDICTIONARY_H
