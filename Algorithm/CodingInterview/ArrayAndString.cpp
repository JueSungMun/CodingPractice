#include "ArrayAndString.h"
#include "Chapter1_ArrayAndString/1_1_FindUniqueString.h"
#include "Chapter1_ArrayAndString/1_2_ReverseString.h"
#include "Chapter1_ArrayAndString/1_3_FindPermutationString.h"
#include "Chapter1_ArrayAndString/1_4_ChangeBlankCharacter.h"
#include "Chapter1_ArrayAndString/1_5_CompressString.h"
#include "Chapter1_ArrayAndString/1_6_RotationImage.h"
#include "Chapter1_ArrayAndString/1_7_MakeZeroRowAndCol.h"
#include "Chapter1_ArrayAndString/1_8_CheckRotatedString.h"

#include <memory>

void ArrayAndString::DoTest()
{
   auto _test = std::make_shared<ReverseString>();
   _test->Print();
}