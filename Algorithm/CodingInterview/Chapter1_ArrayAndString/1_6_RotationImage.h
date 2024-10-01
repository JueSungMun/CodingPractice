#pragma once
#include "../ICodingInterview.h"
#include <cstring>

class RotationImage : public ICodingInterview
{
public:
	RotationImage( ) : ICodingInterview("1-6 RotationImage") {}

public:
	virtual std::string Problem( ) override
	{
		std::string _desc;
		_desc += "이미지를 표현하는 N*N 행렬이 있다." + NewLine;
		_desc += "이미지의 각 픽셀은 4바이트로 표현, " + NewLine;
		_desc += "이미지를 90도로 회전시키는 메소드 작성" + NewLine;
		_desc += "부가적인 행렬을 사용하지 않고서도 할 수 있는가!?";
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
	}
};