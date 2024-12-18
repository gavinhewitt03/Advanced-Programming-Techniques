// Copyright 2023 ghewitt
// Implementation of the MultipleChoiceQuestion class

#include"multiplechoicequestion.h"
#include<string>
using std::string;
#include<iostream>
using std::cout;
using std::endl;

namespace csce240_program5 {

MultipleChoiceQuestion::MultipleChoiceQuestion(string q, int num,
string * ans, bool * c_ans) {
  SetQuestion(q);
  if (!(num >= 0))
    return;
  num_ans_ = num;
  // need to populate dynamically allocated data mems w arguments
  answers_ = new string[num_ans_];
  cor_ans_ = new bool[num_ans_];
  // check if all but last 2 provided
  if (num >= 0 && ans == nullptr && c_ans == nullptr) {
    for (int i = 0; i < num_ans_; ++i) {
      // default values specified in header file
      answers_[i] = "";
      cor_ans_[i] = true;
    }
  // checks if all but last arg provided
  } else if (num >= 0 && ans != nullptr && c_ans == nullptr) {
    for (int i = 0; i < num_ans_; ++i) {
      // populates answers with specified answers and cor_ans with
      // default value stated in header file
      answers_[i] = ans[i];
      cor_ans_[i] = true;
    }
  // checks that all args were provided
  } else if (num >= 0 && ans != nullptr && c_ans != nullptr) {
    for (int i = 0; i < num_ans_; ++i) {
      // populates both dynamically allocated data members with corresponding
      // values from the dynamically allocated arguments
      answers_[i] = ans[i];
      cor_ans_[i] = c_ans[i];
    }
  }
}

MultipleChoiceQuestion::~MultipleChoiceQuestion() {
  // frees up dynamically allocated memory :)
  if (answers_ != nullptr)
    delete [] answers_;
  if (cor_ans_ != nullptr)
    delete [] cor_ans_;
}

MultipleChoiceQuestion::MultipleChoiceQuestion(const MultipleChoiceQuestion&
tocopy) {
  SetQuestion(tocopy.GetQuestion());
  num_ans_ = tocopy.num_ans_;
  answers_ = new string[num_ans_];
  cor_ans_ = new bool[num_ans_];
  // memberwise copy data members
  for (int i = 0 ; i < num_ans_; ++i) {
    answers_[i] = tocopy.answers_[i];
    cor_ans_[i] = tocopy.cor_ans_[i];
  }
}

void MultipleChoiceQuestion::SetAnswerChoices(int num, string * ans,
bool * c_ans) {
  if (!(num >= 0))
    return;
  num_ans_ = num;
  if (answers_ != nullptr)
    delete [] answers_;
  if (cor_ans_ != nullptr)
    delete [] cor_ans_;
  answers_ = new string[num_ans_];
  cor_ans_ = new bool[num_ans_];
  for (int i = 0; i < num_ans_; ++i) {
    answers_[i] = ans[i];
    cor_ans_[i] = c_ans[i];
  }
}

void MultipleChoiceQuestion::SetNumberOfAnswers(int num) {
  if (num > 0)
    num_ans_ = num;
}

MultipleChoiceQuestion& MultipleChoiceQuestion:: operator =
(const MultipleChoiceQuestion& rightoperand) {
  SetQuestion(rightoperand.GetQuestion());
  num_ans_ = rightoperand.num_ans_;
  delete [] answers_;
  delete [] cor_ans_;
  answers_ = new string[num_ans_];
  cor_ans_ = new bool[num_ans_];
  for (int i = 0; i < num_ans_; ++i) {
    answers_[i] = rightoperand.answers_[i];
    cor_ans_[i] = rightoperand.cor_ans_[i];
  }
  return *this;
}

void MultipleChoiceQuestion::Print(bool v) const {
  // always prints
  Question::Print();
  cout << "Answer Choices:" << endl;
  if (v) {
    for (int i = 0; i < num_ans_; ++i) {
      if (cor_ans_[i])
        cout << answers_[i] << " - correct" << endl;
      else
        cout << answers_[i] << " - incorrect" << endl;
    }
  } else {
    for (int i = 0; i < num_ans_; ++i) {
      if (cor_ans_[i])
        cout << answers_[i] << endl;
      else
        cout << answers_[i] << endl;
    }
  }
}

}  // end namespace csce240_program5
