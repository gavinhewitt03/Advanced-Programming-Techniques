// Copyright 2023 ghewitt
// Implementation of the TrueFalseQuestion class

#include"truefalsequestion.h"
#include<iostream>
using std::cout;
using std::endl;
#include<string>
using std::string;

namespace csce240_program5 {

TrueFalseQuestion::TrueFalseQuestion(string q, bool a) {
  SetQuestion(q);
  answer_ = a;
}

// said to include a destructor but no need for one really
TrueFalseQuestion::~TrueFalseQuestion() {}

void TrueFalseQuestion::SetAnswer(bool a) {
  answer_ = a;
}

void TrueFalseQuestion::Print(bool v) const {
  // print question
  Question::Print();
  // prints answer if true
  if (v && answer_)
    cout << "Correct Answer: true" << endl;
  else if (v && !answer_)
    cout << "Correct Answer: false" << endl;
}

}  // end namespace csce240_program5
