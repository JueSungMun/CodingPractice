#pragma once
#include "../ICodingInterview.h"
#include <cstring>

class ReverseString : public ICodingInterview
{
public:
   ReverseString() : ICodingInterview("1-2 ReverseString") {}

public:
  virtual std::string Problem() override
  {
    std::string _desc;
    _desc += "널 문자로 끝나는 문자열을 뒤집는 reverse(char* str) 함수를 C나 C++로 구현하라.";
    return _desc;
  }

  virtual void Answer() override 
  {
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

     delete[] _output;
  }

  virtual void FixAnswer() override
  {
      const char* input = "abcdefghijklmn";
  
      // Find End index
      int str_len = 0;
      while (input[str_len] != '\0')
      {
          str_len++;
      }

      char* result = new char[str_len + 1];
#if defined(_MSC_VER)
      strcpy_s(result, str_len +1, input);
#else
      strcpy(result, input);
#endif
      char* reverse = result;

      // Swap
      for (int i = 0; i < str_len; ++i)
      {
          int _matching_idx = str_len - 1 - i;
          if (i >= _matching_idx)
              break;

		  char temp = input[i];
          result[i] = reverse[_matching_idx];
		  reverse[_matching_idx] = temp;
      }

      std::cout << "InputStr : " << input << ", Result: " << result << std::endl;
      delete[] result;
  }

  virtual std::string Explanation() override
  {
    std::string _explanation;
    _explanation += "A) 문자열 Swap";
     return _explanation;
  }
};