#pragma once
#include "../ICodingInterview.h"
#include <cstring>

class FindPermutationString : public ICodingInterview
{
public:
	FindPermutationString() : ICodingInterview("1-3 FindPermutationString") {}

public:
	virtual std::string Problem() override
	{
		std::string _desc;
		_desc += "문자열 두개를 입력으로 받아, 그중 하나가 다른 하나의 순열인지 판별하는 메소드를 작성하라.";
		return _desc;
	}

	char* _GetSortStr(const char* str)
  {
		int _str_len = static_cast<int>(strlen(str));
		char* _sort_str = new char[_str_len];
		strcpy(_sort_str, str);

		for (int i = 0 ; i < _str_len -1 ; ++i)
		{
			for (int j = i + 1; j < _str_len; ++j)
			{
					if (_sort_str[i] > _sort_str[j])
					{					
						 char temp = _sort_str[i];
						 _sort_str[i] = _sort_str[j];
						 _sort_str[j] = temp;
					}
			}		
		}

		return _sort_str;
  }

	virtual void Answer() override 
	{
		const char* _input1 = "abcde";
		const char* _input2 = "daecb";

		bool _result = false;
		if (strlen(_input1) != strlen(_input2))
		{
			std::cout << GetBooleanStr(_result) << ", 문자열 길이가 다름 --> 실패" << std::endl;
		}
		else
		{
			 char* _sort_str1 = _GetSortStr(_input1);
			 char* _sort_str2 = _GetSortStr(_input2);

			 bool _result = true;
			 for (int i = 0; i < static_cast<int>(strlen(_input1)); ++i)
			 {
				 if (_sort_str1[i] != _sort_str2[i])
				 {
					 _result = false;
					 break;
				 }
			 }

			 std::cout << GetBooleanStr(_result) << ", 문자열 비교 : " << _input1 << ", " << _input2 << std::endl;

			 delete[] _sort_str1;
			 delete[] _sort_str2;
		}
	}

	virtual void FixAnswer() override
	{
		const char* _input1 = "abcde";
		const char* _input2 = "daecb";

		bool _result = false;
		if (strlen(_input1) != strlen(_input2))
		{
			std::cout << GetBooleanStr(_result) << ", 문자열 길이가 다름 --> 실패" << std::endl;
		}
		else
		{
			 char* _str_counter = new char[256];

			 for (int i = 0; i < static_cast<int>(strlen(_input1)); ++i)
			 {
					_str_counter[static_cast<int>(_input1[i])]++; 
			 }
			 
			 bool _result = true;
			 for (int i = 0; i < static_cast<int>(strlen(_input1)); ++i)
			 {
				 if (--_str_counter[static_cast<int>(_input2[i])] < 0)
				 {
					 _result = false;
						break;
				 }
			 }

			 std::cout << "[정렬 없이 하는 방법]" << std::endl;
			 std::cout << "문자열 갯수를 센 후, 다음 문자열에서 그만큼 갯수 빼기" << std::endl;
			 std::cout << "문자열 타입 체크 필요 (ex 영문자, 유니코드)" << std::endl;
			 std::cout << GetBooleanStr(_result) << ", 문자열 비교 : " << _input1 << ", " << _input2 << std::endl;

			 delete[] _str_counter;
		}
	}

	virtual std::string Explanation() override
	{
		std::string _explanation;
		_explanation += "고민해볼점!" + NewLine;
		_explanation += "대소문자 구분 여부, 공백 문자 처리 관련" + NewLine;
		return _explanation;
	}
};