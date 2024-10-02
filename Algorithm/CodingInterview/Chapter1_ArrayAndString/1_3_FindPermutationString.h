#pragma once
#include "../ICodingInterview.h"
#include <cstring>

class FindPermutationString : public ICodingInterview
{
public:
	FindPermutationString() : ICodingInterview("1-3 FindPermutationString") {}

public:
	virtual std::string Problem() override
	{
		std::string _desc;
		_desc += "문자열 두개를 입력으로 받아, 그중 하나가 다른 하나의 순열인지 판별하는 메소드를 작성하라.";
		return _desc;
	}

	virtual void Answer() override 
	{
	}

	virtual void FixAnswer() override
	{
	}

	virtual std::string Explanation() override
	{
		std::string _explanation;
		return _explanation;
	}
};