// Copyright 2023 ghewitt (first 111 lines by bhipp)
#include<iostream>
using std::cout;
using std::endl;
#include<fstream>
using std::ifstream;
#include<string>
using std::string;
#include"question.h"
#include"truefalsequestion.h"
#include"shortanswerquestion.h"
#include"multiplechoicequestion.h"
using namespace csce240_program5;  // cpplint will complain, it's ok

int main(int argc, char * * argv) {
  if ( argc != 3 ) {
    cout << "This program should be run with two input text files."
         << "e.g. ./checkstudentanswers answerkey.txt studentanswers.txt"
         << endl;
    return 0;
  }
  // the first argument (after the name of the executable) should be a text
  // file holding questions and their correct answers. We open that file with
  // an object named key
  ifstream key(argv[1]);

  int number_of_questions, i = 0, num_answers;
  string question_type, question_text, true_false;
  string * answers = nullptr;
  bool * mc_answer_correct = nullptr;
  Question * * the_questions;

  key >> number_of_questions;
  key.get();  // The line above uses formatted input reading only an integer
              // leaving the \n character in the input buffer. The get() call
              // removes that end of line character from the buffer.

  if ( number_of_questions <= 0 ) {
    cout << "First value in the answer key file should be the number of "
         << "questions in the file (a positive integer)." << endl;
    return 0;
  }

  // the_questions will hold a block of base class pointers to hold the
  // addresses of dynamically allocated derived class objects
  the_questions = new Question * [number_of_questions];

  getline(key, question_type);
  while ( key.good() && i < number_of_questions ) {
    getline(key, question_text);
    // each question begins with a type - e.g. true/false, short answer,
    // mutiple choice. We're looking at the first character only to be
    // forgiving of misspellings, abbreviations, etc
    switch ( question_type[0] ) {
      case 't':
      case 'T':
        answers = new string[1];
        getline(key, answers[0]);
        the_questions[i] = new TrueFalseQuestion(question_text,
                                                 answers[0][0] == 't' ||
                                                 answers[0][0] == 'T');
        break;
      case 's':
      case 'S':
        answers = new string[1];
        getline(key, answers[0]);
        the_questions[i] = new ShortAnswerQuestion(question_text, answers[0]);
        break;
      case 'm':
      case 'M':
        key >> num_answers;
        key.get();
        if ( num_answers <= 0 ) {
          cout << "Invalid multiple choice question format" << endl;
          return 0;
        }
        answers = new string[num_answers];
        mc_answer_correct = new bool[num_answers];
        for ( int j = 0; j < num_answers; ++j ) {
          getline(key, answers[j]);
          getline(key, true_false);
          mc_answer_correct[j] = (true_false[0] == 't' || true_false[0] == 'T');
        }
        the_questions[i] = new MultipleChoiceQuestion(question_text,
                                                      num_answers,
                                                      answers,
                                                      mc_answer_correct);
        break;
      default:
        cout << "Invalid question type in key" << endl;
        return 0;
    }

    // free the memory previously reserved for answers and mc_answer_correct
    if ( answers != nullptr ) {
      delete [] answers;
      answers = nullptr;
    }
    if ( mc_answer_correct != nullptr ) {
      delete [] mc_answer_correct;
      mc_answer_correct = nullptr;
    }
    ++i;
    getline(key, question_type);
  }

  if ( i != number_of_questions ) {
    cout << "Invalid key file" << endl;
    return 0;
  }
  key.close();

// ADD YOUR CODE HERE
  // Check the students answers:
  // open the text file containing the student's answers (argv[2])

  // Read each answer.
  // Print each question, displaying the correct answer, and print
  // the student's answer for each question. Send the student's
  // answer to the CheckAnswer for the corresponding question and
  // output whether or not the student answer the question correctly.

  // output the number of questions the student answered correctly

  ifstream input_file(argv[2]);
  // points to a memory block of strings whose length is equal to the number
  // of questions that need to be checked
  string * lines = new string[number_of_questions];
  // count the number of correct answers
  int count = 0;
  // index for loop
  int j = 0;
  // stores answers line by line
  while (input_file.good()) {
    getline(input_file, lines[j++]);
  }
  // loop to print questions, correct answers, and student answers while
  // counting the number of questions the student got correct
  for (int i = 0; i < number_of_questions; ++i) {
    // print the question and its answers
    the_questions[i]->Print(true);
    // if the student's response is correct, then increment count & print
    if (the_questions[i]->CheckAnswer(lines[i])) {
      ++count;
      cout << "Student's answer: " << lines[i] << " - Correct" << endl;
    } else {
      cout << "Student's answer: " << lines[i] << " - Incorrect" << endl;
    }
    cout << endl;
  }
  cout << "The student answered " << count << " of the " << number_of_questions
  << " questions correctly" << endl;
  return 0;
}
