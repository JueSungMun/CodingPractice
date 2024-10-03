#pragma once
#include "../ICodingInterview.h"
#include <cstring>

class ChangeBlankCharacter : public ICodingInterview
{
public:
	ChangeBlankCharacter( ) : ICodingInterview("1-4 ChangeBlankCharacter") {}

public:
	virtual std::string Problem( ) override
	{
		std::string _desc;
		_desc += "주어진 문자열 내의 모든 공백을 %20으로 바꾸는 메소드를 작성하라" + NewLine;
		_desc += "문자열 끝에 추가로 필요한 문자들을 더할 수 있는 충분한 공간이 있다고 가정" + NewLine;
		_desc += "공백을 포함하는 문자열의 길이도 주어진다고 가정" + NewLine;
		_desc += "ex) 입력 : Mr John Smith      , 13" + NewLine;
		_desc += "     출력 : Mr%20John%20Smith";
		return _desc;
	}

	virtual void Answer( ) override
	{
		 const char* _input = "Mr John Smith.";
		 char* _output = new char[strlen(_input) * 3 + 1];

		 int _last_idx = 0;
		 for (int i = 0; i < static_cast<int>(strlen(_input)); ++i)
		 {
				 if (_input[i] != ' ')
				 {
					  _output[_last_idx++] = _input[i];
				 }
			   else 
				 {
					  _output[_last_idx++] = '%';
					  _output[_last_idx++] = '2';
					  _output[_last_idx++] = '0';
				 }
		 }
		 _output[_last_idx] = '\0';
		 std::cout<< _input << ", " << _output << std::endl;

		 delete[] _output;
	}

	virtual void FixAnswer( ) override
	{
		 const char* _input = "Mr John Smith.";

		 int _space_cnt = 0;
		 for (int i = 0; i < static_cast<int>(strlen(_input)); ++i)
		 {
			  if (_input[i] == ' ')
					_space_cnt++;
		 }

		 int _output_len = strlen(_input) + _space_cnt * 2; // strlen에 끝문자 포함된 길이
		 char* _output = new char[_output_len];
		 memset(_output, ' ', _output_len);
     _output[_output_len--] = '\0'; // 먼저 끝문자 설정
		
		 for (int i = static_cast<int>(strlen(_input)) -1; i >= 0; i--)
		 {
				 if (_input[i] != ' ')
				 {
						_output[_output_len--] = _input[i];
				 }
				 else 
				 {
					  _output[_output_len--] = '2';
					  _output[_output_len--] = '0';
						_output[_output_len--] = '%';
				 }

			   // 왜 중간 출력 결과가 잘 안나오지!? 메모리 초기화가 안되서!? <-- memset이후 출력됨
			   std::cout<< _input[i] << ", " << _output_len << ", " << _output << std::endl;
		 }

		 std::cout<< _input << ", " << _output << std::endl;
		 delete[] _output;
	}

	virtual std::string Explanation( ) override
	{
		std::string _explanation;
		_explanation += "문자열 편집시에는 뒤에서 하는 편" + NewLine;
		_explanation += "공간에 여유가 있고, 어떤 문자를 덮어쓰는지 신경안써도 됨" + NewLine;
		return _explanation;
	}
};