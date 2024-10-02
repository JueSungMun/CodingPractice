#pragma once
#include "../ICodingInterview.h"
#include <cstring>

class CompressString : public ICodingInterview
{
public:
	CompressString( ) : ICodingInterview("1-5 CompressString") {}

public:
	virtual std::string Problem( ) override
	{
		std::string _desc;
		_desc += "같은 문자가 연속으로 반복될 경우, 그 횟수를 사용해 문자열을 압축하는 메소드를 작성하라" + NewLine;
		_desc += "압출 결과로 만들어지는 문자열이 원래 문자열보다 짧아지지 않은 경우엔, 원래 문자열을 그대로 반환" + NewLine;
		_desc += "ex) 입력 : aabccccccccaaa" + NewLine;
		_desc += "     출력 : a3b1c8a3";
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