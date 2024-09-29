#pragma once
#include "IAlgorithm.h"

class Test_Atan2 : public IAlgorithm
{
public:
	Test_Atan2() { PrintConstructor(); }
	~Test_Atan2() { PrintDeconstructor(); }
	virtual void DoTest() override
	{
		_DoTestAtan2(1.0f, 1.0f);
		_DoTestAtan2(1.0f, -1.0f);
		_DoTestAtan2(-1.0f, 1.0f);
		_DoTestAtan2(-1.0f, -1.0f);
	}

protected:
	virtual const char* GetClassName()  override { return "Test_Atan2"; }

private:
	void _DoTestAtan2(float x, float y)
	{
		float _result = UE4Math::FMath::Atan2(y, x) * (180.f / PI);
		std::cout << Format("[%4.f Degree] x = (%.3f), y = (%.3f)", _result, x, y) << std::endl;
	}
};