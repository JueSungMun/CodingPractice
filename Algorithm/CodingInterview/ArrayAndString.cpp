#include "ArrayAndString.h"
#include <string.h>

void ArrayAndString::DoTest()
{
   _1_1_FindUniqueString();
   _1_2_ReverseString();
}

void ArrayAndString::_1_1_FindUniqueString()
{
   /*
   Problems:
      문자열에 포함된 문자들이 전부 유일한지를 검사하는 알고리즘을 구현하라.
      다른 자료구조를 사용할 수 없는 상황이라면 어떻게 하겠는가?
   Answer:
      Q) 입력은 영어만 가능
      Q) 입력 타입은 string, array?
      Q) 문자열의 최대 길이는!?

      1, 3, 5, 4, 6, 19, 22
      미리 배열을 잡아두고, Count 검사 <-- 불 필요한 메모리를 잡는 단점 있음
      A) 문자열 길이가 배열 크기를 초과할 경우, 검사 불필요 : 이미 중복됨
      A) Int arr -> Bool : 메모리 공간 줄임
         비트 연산자를 이용하면 좀 더 효율적으로 구성 가능
      A) 원본 문자열을 정렬 할 수 있다면, 처음부터 검색해가면서 처리 가능 (추가적인 메모리 공간 불필요)
   */
    std::string _input = "abcdea";
    bool* _cnt_arr = new bool [256];
    bool _result = false;

    if (_input.length() > 256)
    {
       _result = true;
    }
    else 
    {
       for (int i = 0; i < static_cast<int>(_input.size()); ++i)
       {
          int _int_idx = static_cast<int>(_input[i]);
          if (_cnt_arr[_int_idx])
          {
             _result = true;
             break;
          }
   
          _cnt_arr[_int_idx] = true;
       }
    }
   
    std::cout << "InputStr : " << _input << ", Result: " << _result << std::endl;
}

void ArrayAndString::_1_2_ReverseString()
{
   /*
   Problems : 널 문자로 끝나는 문자열을 뒤집는 reverse(char* str) 함수를 C나 C++로 구현하라
   Answer
     - Q) string을 사용해도 되는지?
   */
   const char* _input = "abcde";
   int _strlen = strlen(_input);

   char* _output = new char[_strlen + 1];
   int _last_idx = _strlen - 1;
   // Idx를 다루기 때문에 0 ~ _strlen - 1 사용
   for (int i = _last_idx; i >= 0; i--)
   {
      _output[_last_idx -i] = _input[i];
   }

   _output[_strlen] = '\0';

   std::cout << "InputStr : " << _input << ", Result: " << _output << std::endl;
}