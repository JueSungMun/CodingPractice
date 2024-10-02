#pragma once
#include "../ICodingInterview.h"
#include <cstring>

class ChangeBlankCharacter : public ICodingInterview
{
public:
	ChangeBlankCharacter( ) : ICodingInterview("1-4 ChangeBlankCharacter") {}

public:
	virtual std::string Problem( ) override
	{
		std::string _desc;
		_desc += "주어진 문자열 내의 모든 공백을 %20으로 바꾸는 메소드를 작성하라" + NewLine;
		_desc += "문자열 끝에 추가로 필요한 문자들을 더할 수 있는 충분한 공간이 있다고 가정" + NewLine;
		_desc += "공백을 포함하는 문자열의 길이도 주어진다고 가정" + NewLine;
		_desc += "ex) 입력 : Mr John Smith      , 13" + NewLine;
		_desc += "     출력 : Mr%20John%20Smith";
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