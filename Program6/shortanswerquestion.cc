// Copyright 2023 ghewitt
// Implementation of the ShortAnswerQuestion class

#include"shortanswerquestion.h"
#include<iostream>
using std::cout;
using std::endl;
#include<string>
using std::string;

namespace csce240_program5 {

ShortAnswerQuestion::ShortAnswerQuestion(string q, string a) : answer_("") {
  SetQuestion(q);
  SetAnswer(a);
}

// said to include a destructor but no pointer data members..
ShortAnswerQuestion::~ShortAnswerQuestion() {}

void ShortAnswerQuestion::SetAnswer(string a) {
  if (a.length() > 0)
    answer_ = a;
}

void ShortAnswerQuestion::Print(bool v) const {
  // prints question
  Question::Print(true);
  // prints correct answer if bool val true
  if (v)
    cout << "Correct Answer: " << answer_ << endl;
}
bool ShortAnswerQuestion::CheckAnswer(string s) {
  if (answer_ == s)
    return true;
  return false;
}

}  // end namespace csce240_program5
