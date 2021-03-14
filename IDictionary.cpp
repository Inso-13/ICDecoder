//
// Created by Inso on 2021/3/11.
//

#include "IDictionary.h"

std::map<std::string,std::string> IDictionary::dic;
std::map<std::string,std::string> IDictionary::fun{{"printf", "int"}, {"scanf", "int"},{"puts","int"}};

bool IDictionary::isBlankSep(char ch) {
    return ch==' '||ch=='\n'||ch=='\t'||ch=='\r';
}

bool IDictionary::isSentenceSep(char ch) {
    return ch==';';
}

bool IDictionary::isLetter(char ch) {
    return ch>='a'&&ch<='z'||ch>='A'&&ch<='Z';
}

bool IDictionary::isNumber(char ch) {
    return ch>='0'&&ch<='9';
}

bool IDictionary::isLetterOrNumber(char ch) {
    return isLetter(ch)||isNumber(ch);
}

bool IDictionary::isLetterOrDL(char ch) {
    return isLetter(ch)||ch=='_';
}

bool IDictionary::isLetterOrNumberOrDL(char ch) {
    return isLetterOrDL(ch)||isNumber(ch);
}

bool IDictionary::isRealNumberContext(char ch) {
    return isLetterOrNumberOrDL(ch)||ch=='+'||ch=='-'||ch=='.';
}

bool IDictionary::isOperator(char ch) {
    std::set<char> operators({'+','-','*','/','?',':','<','>','!','|','&','=','%','~','^',',','.'});
    return operators.find(ch)!=operators.end();
}

bool IDictionary::isBaseType(std::string str) {
    std::set<std::string> baseTypes({"int","float","double","short","unsigned","struct","enum","char","bool"});
    int maxLen = str.length();
    std::string tempStr =str;

    for(int i=0;i<=maxLen;i++)
    {
        tempStr=str.substr(0,maxLen-i);
        if(baseTypes.find(tempStr)!=baseTypes.end())
            break;
    }
    if(tempStr.empty())
        return false;

    for(int i=tempStr.length()+1;i<maxLen;i++)
    {
        if(!(isBlankSep(str[i])||str[i]=='*'))
            return false;
    }
    return true;
}

bool IDictionary::isOperator0(std::string str) {
    std::set<std::string> operator0({"++","--"});
    return operator0.find(str)!=operator0.end();
}

bool IDictionary::isOperator1(std::string str) {
    std::set<std::string> operator1({"+","-","~","&","!","++","--","*"});
    return operator1.find(str)!=operator1.end();
}

bool IDictionary::isOperator2(std::string str) {
    std::set<std::string> operator2({"+","-","*","/","%","<",">","|","&","^","||","&&",".",",","=","!=","<<",">>",\
                                     ">=","<=","==","->","+=","-=","*=","/=","&=","|=","<<=",">>="});
    return operator2.find(str)!=operator2.end();
}

bool IDictionary::isBracket1l(char ch) {
    return ch=='(';
}

bool IDictionary::isBracket1r(char ch) {
    return ch==')';
}

bool IDictionary::isBracket2l(char ch) {
    return ch=='[';
}

bool IDictionary::isBracket2r(char ch) {
    return ch==']';
}

bool IDictionary::isQuestion(char ch) {
    return ch=='?';
}

bool IDictionary::isColon(char ch) {
    return ch==':';
}

bool IDictionary::isQuotation1(char ch) {
    return ch=='\'';
}

bool IDictionary::isQuotation2(char ch) {
    return ch=='\"';
}

bool IDictionary::isSlash(char ch) {
    return ch=='\\';
}

bool IDictionary::isNumber8(char ch) {
    return ch<='7'&&ch>='0';
}

bool IDictionary::isNumber16(char ch) {
    return ch<='9'&&ch>='0'||ch>='a'&&ch<='f'||ch>='A'&&ch<='F';
}

bool IDictionary::isSimpleTransfer(char ch) {
    return ch=='o'||ch=='n'||ch=='r'||ch=='t'||ch=='v'||ch=='a'||ch=='b'||ch=='f'||ch=='\''||ch=='\"'||ch=='\\'||ch=='?';
}

void IDictionary::addPointer(std::string str) {
    dic.find(str)->second+='*';
}
