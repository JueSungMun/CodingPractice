#pragma once
#include "../IAlgorithm.h"

class ArrayAndString : public IAlgorithm
{
public:
  ArrayAndString() { PrintConstructor(); }
  ~ArrayAndString() { PrintDeconstructor(); }
  
  virtual void DoTest() override;

protected:
  virtual const char* GetClassName()  override { return "ArrayAndString"; }
};