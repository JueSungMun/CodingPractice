#pragma once
#include "../ICodingInterview.h"
#include <cstring>

class MakeZeroRowAndCol : public ICodingInterview
{
public:
	MakeZeroRowAndCol( ) : ICodingInterview("1-7 MakeZeroRowAndCol") {}

public:
	virtual std::string Problem( ) override
	{
		std::string _desc;
		_desc += "M * N 행렬을 순회하면서, 0인 원소를 발견하면" + NewLine;
		_desc += "해당 원소가 속한 행과 열의 모든 원소를 0으로 설정하는 알고리즘 작성 " + NewLine;
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