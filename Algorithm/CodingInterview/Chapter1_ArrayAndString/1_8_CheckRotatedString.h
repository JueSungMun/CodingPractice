#pragma once
#include "../ICodingInterview.h"
#include <cstring>

class CheckRotatedString : public ICodingInterview
{
public:
	CheckRotatedString( ) : ICodingInterview("1-8 CheckRotatedString") {}

public:
	virtual std::string Problem( ) override
	{
		std::string _desc;
		_desc += "한 단어가 다른 단어에 포함된 문자열인지 판별하는 isSubstring이라는 메소드가 있을때" + NewLine;
		_desc += "s1과 s2 두 문자열이 주어졌을때" + NewLine;
	    _desc += "s2가 s1을 회전 시킨 결과인지 판별하는 코드를 isSubstring 메소드를 한번만 호출하여 작성 " + NewLine;
		_desc += "ex) waterbottle --> erbottlewat을 회전시켜 얻을 수 있는 문자열";
		return _desc;
	}

	virtual void Answer( ) override
	{

	}

	virtual void FixAnswer( ) override
	{
	}

	virtual std::string Explanation( ) override
	{
		std::string _explanation;
		return _explanation;
	}
};