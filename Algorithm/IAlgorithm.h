#pragma once
#include <iostream>
#include <stdarg.h>

class IAlgorithm
{
public:
	IAlgorithm() { PrintConstructor(); }
	virtual ~IAlgorithm() { PrintDeconstructor();  }

public:
	virtual void DoTest() = 0;
	
	std::string Format(const char* _format_str, ...)
	{
		char str[100];
		va_list vargs;
		va_start(vargs, _format_str);
#if defined(_MSC_VER)
		vsprintf_s(str, _format_str, vargs);
#else
		vsprintf(str, _format_str, vargs);
#endif
		va_end(vargs);
		return str;
	}

protected:
	virtual const char* GetClassName() { return "IAlgorithm"; }

	void PrintConstructor() 
	{
		std::cout << "[" << GetClassName() << "] Construct" << std::endl;
	}
	void PrintDeconstructor()
	{
		std::cout << "[" << GetClassName() << "] Deconstruct" << std::endl;
	}
};
