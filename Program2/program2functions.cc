// Copyright 2023 ghewitt
// Homework Assignment 2 Function Implementation
#include"program2functions.h"

bool LeapYear(int year) {
  if ( year % 400 == 0 )
    return true;
  else if ( year % 4 == 0 && year % 100 != 0 )
    return true;
  return false;
}

int LastDayOfMonth(int month, int year) {
  if ( month < 1 || month > 12 )
    return 0;
  if ( month == 2 && year == 0 )
    return 0;
  if ( (month == 2 && year % 400 == 0) ||
  (month == 2 && (year % 4 == 0 && year % 100 != 0)) ) {
    return 29;
  } else if (month == 2) {
    return 28;
  } else {
    if (month <= 7 && month % 2 == 1) {
      return 31;
    } else if (month <= 7) {
      return 30;
    } else if (month > 7 && month % 2 == 0) {
      return 31;
    } else {
      return 30;
    }
  }
}

bool ValidDate(int month, int day, int year) {
  if ( month > 12 || month < 1 ) {
    return false;
  } else if ( year < 1 ) {
    return false;
  } else if ( (month == 2 && year % 400 == 0) ||
  (month == 2 && (year % 4 == 0 && year % 100 != 0)) ) {
    if ( day <= 29 && day >= 1 )
      return true;
    return false;
  } else if ( month == 2 )  {
    if (day <= 28 && day >= 1) {
      return true;
    } else {
      return false;
    }
  } else if ( month <= 7 && month % 2 == 1 ) {
    if ( day <= 31 && day >= 1 ) {
      return true;
    } else {
      return false;
    }
  } else if ( month <= 7 && month % 2 == 0 ) {
    if ( day <= 30 && day >= 1 ) {
      return true;
    } else {
      return false;
    }
  } else if ( month > 7 && month % 2 == 0 ) {
    if ( day <= 31 && day >= 1 ) {
      return true;
    } else {
      return false;
    }
  } else if ( day <= 30 && day >= 1 ) {
    return true;
  } else {
    return false;
  }
  return false;
}

void NextDate(int& month, int& day, int& year) {
  // tests the validity of the date input
  if (month <= 0 || month > 12)
    return;
  if (day <= 0)
    return;
  if (year <= 0)
    return;
  if ( (month <= 7 && month % 2 == 1) || (month > 7 && month % 2 == 0) ) {
    if (day > 31)
      return;
  } else {
    if (day > 30)
      return;
  }

  // if december 31st then roll year, day, and month
  if ( month == 12 && day == 31 ) {
    month = 1, day = 1, ++year;
    return;
  }
  // february special condition
  if ( (month == 2) && ((year % 400 == 0) ||
  (year % 4 == 0 && year % 100 != 0)) ) {
    if ( day == 29 ) {
      month = 3, day = 1;
      return;
    }
  } else if ( month == 2 ) {
    if ( day == 28 ) {
      month = 3, day = 1;
    }
  }
  // checks to see if date is at the end of the month & increments
  // accordingly
  if ( (month <= 7 && month % 2 == 1) ||
  (month > 7 && month % 2 == 0)) {
    if (day == 31) {
      day = 1;
      ++month;
    } else {
      ++day;
    }
  } else if (day == 30) {
    day = 1;
    ++month;
  } else {
    ++day;
  }
}

void PreviousDate(int& month, int& day, int& year) {
  // tests the validity of the date input
  if ( !(ValidDate(day, month, year)) ) {
    return;
  }

  // march special condition
  if ( month == 3 && LeapYear(year) ) {
    month = 2, day = 29;
    return;
  } else if ( month == 3 ) {
    month = 2, day = 28;
    return;
  }

  // if january 1st then roll year, day, and month
  if ( month == 1 && day == 1 ) {
    month = 12, day = 31, --year;
    return;
  }

  // if date is at beginning of the month decrement accordingly
  if ( (month <= 7 && month % 2 == 1) || (month > 7 && month % 2 == 0) ) {
    if (day == 1) {
      day = 30;
      --month;
    } else {
      --day;
    }
  } else {
    if ( day == 1 ) {
      day = 31;
      --month;
    } else {
      --day;
    }
  }
}
