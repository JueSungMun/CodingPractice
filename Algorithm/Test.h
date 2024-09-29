#pragma once
#include "IAlgorithm.h"

class Test : public IAlgorithm
{
public:
	Test() { PrintConstructor(); }
	~Test() { PrintDeconstructor(); }
	virtual void DoTest() override {}
protected:
	virtual const char* GetClassName()  override { return "Test"; }
};
