#pragma once
#include "../ICodingInterview.h"

class FindUniqueString : public ICodingInterview
{
public:
  FindUniqueString() : ICodingInterview("1-1 FindUniqueString") {}

public:
  virtual std::string Problem() override
  {
    std::string _desc;
    _desc += "문자열에 포함된 문자들이 전부 유일한지를 검사하는 알고리즘을 구현하라.";
    _desc += NewLine;
    _desc += "다른 자료구조를 사용할 수 없는 상황이라면 어떻게 하겠는가?";
    return _desc;
  }

  virtual void Answer() override 
  {
    std::string _desc;
    _desc += "Q) 입력은 영어만 가능 \r\n";
    _desc += "Q) 입력 타입은 string, array? \r\n";
    _desc += "Q) 문자열의 최대 길이는!? \r\n";

    std::cout << _desc << std::endl;
    
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

  virtual std::string Explanation() override
  {
    std::string _explanation;
    _explanation += "A) 문자열 길이가 배열 크기를 초과할 경우, 검사 불필요 : 이미 중복됨 \r\n";
    _explanation += "A) Int arr -> Bool : 메모리 공간 줄임 \r\n";
    _explanation += "비트 연산자를 이용하면 좀 더 효율적으로 구성 가능 \r\n";
    _explanation += "A) 원본 문자열을 정렬 할 수 있다면, 처음부터 검색해가면서 처리 가능 (추가적인 메모리 공간 불필요)";

     return _explanation;
  }
};