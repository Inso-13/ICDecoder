//
// Created by Inso on 2021/3/11.
//

#include "INumberJudger.h"

bool INumberJudger::isNumber(std::string s)
{
	std::unordered_map<State, std::unordered_map<CharType, State>> transfer{
		{STATE_INITIAL, {
							{CHAR_SPACE, STATE_INITIAL},
							{CHAR_NUMBER, STATE_INTEGER},
							{CHAR_POINT, STATE_POINT_WITHOUT_INT},
							{CHAR_SIGN, STATE_INT_SIGN},
						}},
		{STATE_INT_SIGN, {
							 {CHAR_NUMBER, STATE_INTEGER},
							 {CHAR_POINT, STATE_POINT_WITHOUT_INT},
						 }},
		{STATE_INTEGER, {
							{CHAR_NUMBER, STATE_INTEGER},
							{CHAR_EXP, STATE_EXP},
							{CHAR_POINT, STATE_POINT},
							{CHAR_SPACE, STATE_END},
						}},
		{STATE_POINT, {
						  {CHAR_NUMBER, STATE_FRACTION},
						  {CHAR_EXP, STATE_EXP},
						  {CHAR_SPACE, STATE_END},
					  }},
		{STATE_POINT_WITHOUT_INT, {
									  {CHAR_NUMBER, STATE_FRACTION},
								  }},
		{STATE_FRACTION, {
							 {CHAR_NUMBER, STATE_FRACTION},
							 {CHAR_EXP, STATE_EXP},
							 {CHAR_SPACE, STATE_END},
						 }},
		{STATE_EXP, {
						{CHAR_NUMBER, STATE_EXP_NUMBER},
						{CHAR_SIGN, STATE_EXP_SIGN},
					}},
		{STATE_EXP_SIGN, {
							 {CHAR_NUMBER, STATE_EXP_NUMBER},
						 }},
		{STATE_EXP_NUMBER, {
							   {CHAR_NUMBER, STATE_EXP_NUMBER},
							   {CHAR_SPACE, STATE_END},
						   }},
		{STATE_END, {
						{CHAR_SPACE, STATE_END},
					}}};

	int len = s.length();
	State st = STATE_INITIAL;

	for (int i = 0; i < len; i++)
	{
		CharType typ = toCharType(s[i]);
		if (transfer[st].find(typ) == transfer[st].end())
		{
			return false;
		}
		else
		{
			st = transfer[st][typ];
		}
	}
	return st == STATE_INTEGER || st == STATE_POINT || st == STATE_FRACTION || st == STATE_EXP_NUMBER || st == STATE_END;
}