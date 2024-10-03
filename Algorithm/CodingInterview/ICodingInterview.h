#pragma once
#include <string>

const std::string NewLine = "\r\n";

class ICodingInterview
{
public:
  ICodingInterview(const char* _title) { m_Title = _title; }
  virtual ~ICodingInterview() { }

public:
  virtual std::string Problem() = 0;
  virtual void Answer() = 0;
  virtual void FixAnswer() {}
  virtual std::string Explanation() = 0;
  virtual void Print()
  {
    std::cout << "--------------------------------" << std::endl;
    std::cout << "[Title] : " << m_Title << std::endl;
    std::cout << "Problems : " << std::endl;
    std::cout << Problem() << std::endl;
    Answer();
    std::cout << "--------------------------------" << std::endl;
    FixAnswer();
    std::cout << "--------------------------------" << std::endl;
    std::cout << "Explanation : " << std::endl;
    std::cout << Explanation() << std::endl;
  }

  std::string GetBooleanStr(bool _value)
  {
    return _value ? "true" : "false";
  }

protected:
  std::string m_Title;
};