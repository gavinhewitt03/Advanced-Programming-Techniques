// Copyright 2023 ghewitt
// Implementation of timeofday.h
#include"timeofday.h"
#include<iostream>
using std::cout;
using std::endl;
#include<iomanip>
using std::setw;
using std::setfill;

TimeOfDay::TimeOfDay(int h, int m, int s) {
  // checks args are valid and assigns to 0 if not
  if ( h >= 0 && h < 24 )
    hour_ = h;
  else
    hour_ = 0;
  if (m >= 0 && m < 60 )
    minute_ = m;
  else
    minute_ = 0;
  if (s >= 0 && s < 60 )
    second_ = s;
  else
    second_ = 0;
}

void TimeOfDay::SetHour(int h) {
  if ( h >= 0 && h < 24 )
    hour_ = h;
}

void TimeOfDay::SetMinute(int m) {
  if (m >= 0 && m < 60 )
    minute_ = m;
}

void TimeOfDay::SetSecond(int s) {
  if (s >= 0 && s < 60 )
    second_ = s;
}

void TimeOfDay::Print(bool mil, bool sec) {
  if (mil && sec) {
    cout << setw(2) << setfill('0') << hour_ << ":"
    << setw(2) << setfill('0') << minute_ << ":"
    << setw(2) << setfill('0') << second_ << endl;
  } else if (mil) {
    cout << setw(2) << setfill('0') << hour_ << ":"
    << setw(2) << setfill('0') << minute_ << endl;
  } else if (sec) {
    if (hour_ / 12 == 1) {
      cout << setw(2) << setfill('0') << (hour_ % 12) << ":"
      << setw(2) << setfill('0') << minute_ << ":"
      << setw(2) << setfill('0') << second_ << " p.m." << endl;
    } else {
      cout << setw(2) << setfill('0') << (hour_ % 12) << ":"
      << setw(2) << setfill('0') << minute_ << ":"
      << setw(2) << setfill('0') << second_ << " a.m." << endl;
    }
  } else {
    if (hour_ / 12 == 1) {
      cout << setw(2) << setfill('0') << (hour_ % 12) << ":"
      << setw(2) << setfill('0') << minute_ << " p.m." << endl;
    } else {
      cout << setw(2) << setfill('0') << (hour_ % 12) << ":"
      << setw(2) << setfill('0') << minute_ << " a.m." << endl;
    }
  }
}
