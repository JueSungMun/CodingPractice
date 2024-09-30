#include "ArrayAndString.h"
#include "Chapter1_ArrayAndString/1_1_FindUniqueString.h"
#include "Chapter1_ArrayAndString/1_2_ReverseString.h"
#include <memory>

void ArrayAndString::DoTest()
{
   auto _test = std::make_shared<ReverseString>();
   _test->Print();
}