// Copyright 2023 ghewitt
// Implementation of timeinterval.h

#include"timeinterval.h"
#include<iostream>
using std::cout;
using std::endl;
#include<string>
using std::string;

TimeInterval::TimeInterval(const TimeOfDay& start, const TimeOfDay& end) {
  if (start.GetHour() > end.GetHour()) {
    start_ = start;
    end_ = start;
  } else if (start.GetHour() == end.GetHour()) {
    if (start.GetMinute() > end.GetMinute()) {
      start_ = end;
      end_ = start;
    } else if (start.GetMinute() == start.GetMinute()) {
      if (start.GetSecond() > end.GetSecond()) {
        start_ = start;
        end_ = start;
      }
    }
  } else {
    start_ = start;
    end_ = end;
  }
}

TimeInterval::TimeInterval(const TimeOfDay& start, int length, string units) {
  start_ = start;
  if (units == "hours") {
    // checks that time interval doesn't go across days
    if (length > 0 && length < 24 - start_.GetHour())
      end_ = TimeOfDay(start_.GetHour() + length, start_.GetMinute(),
      start_.GetSecond());
    else
      end_ = start_;
  } else if (units == "minutes") {
    int hours = length / 60;
    int minutes = length % 60;
    if (length <= 0) {
      end_ = start_;
    } else if (start_.GetMinute() + minutes >= 60) {
      if (start_.GetHour() + hours + 1 > 23)
        end_ = start_;
      else
        end_ = TimeOfDay(start_.GetHour() + hours + 1,
        start_.GetMinute() + minutes - 60, start_.GetSecond());
    } else {
      if (start_.GetHour() + hours > 23)
        end_ = start_;
      else
        end_ = TimeOfDay(start_.GetHour() + hours, start_.GetMinute() + minutes,
        start_.GetSecond());
    }
  } else if (units == "seconds") {
    int minutes = length / 60;
    int hours = minutes / 60;
    int seconds = length % 60;
    if (length < 0)
      end_ = start_;
  }
}

void TimeInterval::SetStartTime(const TimeOfDay& start) {
  // series of checks for validity
  if (start.GetHour() > end_.GetHour())
    return;
  if (start.GetHour() == end_.GetHour()) {
    if (start.GetMinute() > end_.GetMinute())
      return;
    if (start.GetMinute() == end_.GetMinute()) {
      if (start.GetSecond() > end_.GetSecond())
        return;
    }
  }
  start_ = start;
}

void TimeInterval::SetEndTime(const TimeOfDay& end) {
  // series of checks for validity
  if (end.GetHour() < start_.GetHour())
    return;
  if (end.GetHour() == start_.GetHour()) {
    if (end.GetMinute() < start_.GetMinute())
      return;
    if (end.GetMinute() == start_.GetMinute()) {
      if (end.GetSecond() < start_.GetSecond())
        return;
    }
  }
  end_ = end;
}

void TimeInterval::SetEndTime(int length, string units) {
  if (length < 0)
    return;
  if (units == "hours") {
    if (length <= 23 - start_.GetHour()) {
      end_ = TimeOfDay(start_.GetHour() + length, start_.GetMinute(),
      start_.GetSecond());
    }
  } else if (units == "minutes") {
    // if length >= 60, need to account for hour change
    // if < 60, hours = 0 and minutes = length so fine
    int hours = length / 60;
    int minutes = length % 60;
    // check that addition wont go over 59
    if (start_.GetMinute() + minutes >= 60) {
      ++hours;
      minutes = start_.GetMinute() + minutes - 60;
      // checks that interval is valid
      if (start_.GetHour() + hours <= 23) {
        end_ = TimeOfDay(start_.GetHour() + hours,
        minutes, start_.GetSecond());
      }
    } else if (start_.GetHour() + hours <= 23) {
      end_ = TimeOfDay(start_.GetHour() + hours,
      start_.GetMinute() + minutes, start_.GetSecond());
    }
  } else if (units == "seconds") {
    // same as above but now min sec and hours
    int minutes = length / 60;
    int hours = minutes / 60;
    int seconds = length % 60;
    // check that addition wont go over 59
    if (start_.GetSecond() + seconds >= 60) {
      ++minutes;
      seconds = start_.GetSecond() + seconds - 60;
      if (start_.GetMinute() + minutes >= 60) {
        ++hours;
        minutes = start_.GetMinute() + minutes - 60;
        if (start_.GetHour() + hours <= 23)
          end_ = TimeOfDay(start_.GetHour() + hours, minutes, seconds);
      } else if (start_.GetHour() + hours <= 23) {
          end_ = TimeOfDay(start_.GetHour() + hours, start_.GetMinute() +
          minutes, seconds);
      }
    } else if (start_.GetHour() + hours <= 23) {
      end_ = TimeOfDay(start_.GetHour() + hours, start_.GetMinute() +
      minutes, start_.GetSecond() + seconds);
    }
  }
}

void TimeInterval::Print(bool mil, bool sec) {
  cout << "Start time: ";
  start_.Print(mil, sec);
  cout << "End time: ";
  end_.Print(mil, sec);
}
