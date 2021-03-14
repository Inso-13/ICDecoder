//
// Created by Inso on 2021/3/11.
//

#ifndef ICDECODER_INUMBERJUDGER_H
#define ICDECODER_INUMBERJUDGER_H

#include <string>
#include <unordered_map>

class INumberJudger
{
public:
	enum State
	{
		STATE_INITIAL,
		STATE_INT_SIGN,
		STATE_INTEGER,
		STATE_POINT,
		STATE_POINT_WITHOUT_INT,
		STATE_FRACTION,
		STATE_EXP,
		STATE_EXP_SIGN,
		STATE_EXP_NUMBER,
		STATE_END,
	};
	enum CharType
	{
		CHAR_NUMBER,
		CHAR_EXP,
		CHAR_POINT,
		CHAR_SIGN,
		CHAR_SPACE,
		CHAR_ILLEGAL,
	};
	CharType toCharType(char ch)
	{
		if (ch >= '0' && ch <= '9')
		{
			return CHAR_NUMBER;
		}
		else if (ch == 'e' || ch == 'E')
		{
			return CHAR_EXP;
		}
		else if (ch == '.')
		{
			return CHAR_POINT;
		}
		else if (ch == '+' || ch == '-')
		{
			return CHAR_SIGN;
		}
		else if (ch == ' ')
		{
			return CHAR_SPACE;
		}
		else
		{
			return CHAR_ILLEGAL;
		}
	}
	bool isNumber(std::string s);
};

#endif //ICDECODER_INUMBERJUDGER_H
