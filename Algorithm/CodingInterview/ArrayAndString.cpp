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

std::shared_ptr<ICodingInterview> _GetTestCase(int _case);
void ArrayAndString::DoTest()
{
   auto _test = _GetTestCase(4);
   _test->Print();
}

std::shared_ptr<ICodingInterview> _GetTestCase(int _case)
{
   switch(_case)
   {
      case 1:
         return std::make_shared<FindUniqueString>();
      case 2:
         return std::make_shared<ReverseString>();
      case 3:
         return std::make_shared<FindPermutationString>();
      case 4:
         return std::make_shared<ChangeBlankCharacter>();
      case 5:
         return std::make_shared<CompressString>();
      case 6:
         return std::make_shared<RotationImage>();
      case 7:
         return std::make_shared<MakeZeroRowAndCol>();
      case 8:
         return std::make_shared<CheckRotatedString>();
      default:
         return nullptr;
   }
}