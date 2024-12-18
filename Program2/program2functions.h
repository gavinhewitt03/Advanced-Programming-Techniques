// Copyright 2023 ghewitt
// Reusable functions for Project 2

// LeapYear should take an integer argument for the year. If the argument
// is a positive integer that is a leap year, the function should return
// true, otherwise it should return false.
// For example, LeapYear(2023) should return false. LeapYear(2024) should
// return true.


// LastDayOfMonth function should take an integer for the month, and an integer
// for the year as its three arguments.
// The year parameter should have a default argument of 0.
// The function should return the largest valid day for the given month (an
// integer).
// For example LastDayOfMonth(1) should return 31.
// LastDayOfMonth(4) should return 30.
// If the month is invalid, the function should return 0.
// For example, LastDayOfMonth(13) should return 0.
// If the month sent to the function is 2 (February), the function must be
// sent a positive integer argument for the year in order to return the last
// date of the month. If the year argument is not a positive integer the
// function should return 0.
// For example, LastDayOfMonth(2) should return 0.
// LastDayOfMonth(2, 2023) should return 28.
// LastDayOfMonth(2, 2024) should return 29.


// ValidDate function should take an integer for the month, an integer for
// the day, and an integer for the year as three arguments. The function should
// return true if the values make a valid date, and false otherwise.
// For example ValidDate(1, 5, 2023) should return true.
// ValidDate(7, 50, 2023) should return false.
// If the year is not a positive integer, then the function should return false


// NextDate function should take an integer variable for the month, an
// integer variable for the day, and an integer variable for the year as
// its three arguments.
// If the values of the arguments are not the values for a valid date, then
// the function should exit without making any changes to the arguments.
// If the values of the arguments are a valid date, then the function should
// update the three arguments to hold the next calendar date. For example, if
// the function is sent variables containing 1, 31, and 2023, the function
// update those variables so that they hold 2, 1, and 2023 when the function
// completes.


// PreviousDate function should take an integer variable for the month, an
// integer variable for the day, and an integer variable for the year as
// its three arguments.
// If the values of the arguments are not the values for a valid date, then
// the function should exit without making any changes to the arguments.
// If the values of the arguments are a valid date, then the function should
// update the three arguments to hold the previous calendar date. For example,
// if the function is sent variables containing 1, 1, and 2023, the function
// should update those variables so that they hold 12, 31, and 2022 when the
// function completes.

#ifndef PROJECT2_PROGRAM2FUNCTIONS_H_
#define PROJECT2_PROGRAM2FUNCTIONS_H_

// LeapYear function to determine if year entered is a Leap Year
bool LeapYear(int);

// Function to determine what the last day of the month entered is
int LastDayOfMonth(int month, int year = 0);

// Takes an an integer for the day, month, and year and returns true or false
// if the date entered is a valid day
bool ValidDate(int month, int day, int year);

// Accepts integer variables for the day, month, and year and changes the
// value of the variables input to hold the next day if date is valid
void NextDate(int& month, int& day, int& year);

// Determines if the month, day, and year entered are valid and changes the
// value of the variables input to hold the previous day if valid
void PreviousDate(int& month, int& day, int& year);

#endif  // PROJECT2_PROGRAM2FUNCTIONS_H_
