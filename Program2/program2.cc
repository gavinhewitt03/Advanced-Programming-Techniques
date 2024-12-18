// Copyright 2023 ghewitt
// Homework Assignment 2

#include<iostream>
#include"program2functions.h"
using std::cin;
using std::cout;
using std::endl;

int main() {
  // date variable declarization and initializations
  int month1, day1, year1, month2, day2, year2;
  char first1, second1, first2, second2;
  cin >> month1 >> first1 >> day1 >> second1 >> year1;
  cin >> month2 >> first2 >> day2 >> second2 >> year2;

  // sets vars of one month to separate vars for later use
  int month3, day3, year3;
  month3 = month1, day3 = day1, year3 = year1;

  // checks both dates are valid
  if ( !(ValidDate(month1, day1, year1) &&
  ValidDate(month2, day2, year2)) ) {
    cout << month1 << first1 << day1 << second1 <<
    year1 << " is not a valid date" << endl;
    cout << month2 << first2 << day2 << second2 <<
    year2 << " is not a valid date" << endl;
    return 0;
  } else if ( !(ValidDate(month1, day1, year1)) ) {
    cout << month1 << first1 << day1 << second1 <<
    year1 << " is not a valid date" << endl;
    return 0;
  }
  if ( !(ValidDate(month2, day2, year2)) ) {
    cout << month2 << first2 << day2 << second2 <<
    year2 << " is not a valid date" << endl;
    return 0;
  }

  // count var to determine how far apart the days are
  // & f var to keep track of what date comes first
  int count = 0, f = 0;

  // check which date comes first
  if (year1 > year2) {
    f = 1;
  } else if (year1 < year2) {
    f = 2;
  } else if (month1 > month2) {
    f = 1;
  } else if (month1 < month2) {
    f = 2;
  } else if (day1 > day2) {
    f = 1;
  } else if (day1 < day2) {
    f = 2;
  }

  if (f == 1) {
    month3 = month2, day3 = day2, year3 = year2;
    while (day3 != day1 || month3 !=
    month1 || year3 != year1) {
      NextDate(month3, day3, year3);
      ++count;
    }
    cout << month1 << first1 << day1 << second1 <<
    year1 << " is " << count << " days after " <<
    month2 << first2 << day2 << second2 << year2 <<
    endl;
  } else if (f == 2) {
    while (day3 != day2 || month3 !=
    month2 || year3 != year2) {
      NextDate(month3, day3, year3);
      ++count;
    }
    ++count;
    cout << month1 << first1 << day1 << second1 <<
    year1 << " is " << count << " days before " <<
    month2 << first2 << day2 << second2 << year2 <<
    endl;
  } else {
    cout << month1 << first1 << day1 << second1 <<
    year1 << " is " << count << " days before " <<
    month2 << first2 << day2 << second2 << year2 <<
    endl;
  }
  return 0;
}
