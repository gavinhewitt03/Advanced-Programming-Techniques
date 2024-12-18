// Copyright 2023 ghewitt

#include<iostream>
#include<iomanip>
#include<cmath>
using std::cout;
using std::cin;
using std::endl;

int main() {
  // declaring integers for input from user
  int int1;
  int int2;
  int int3;

  // declaring char variables for opertators input by user
  char arith;
  char relation;

  // declaring character that determines continuation
  char cont;

  // checks that the arithmetic and relational operators are valid and assigns
  // value to two boolean variables to determine what output should be printed
  bool arith_valid;
  bool relation_valid;

  // initializes two variables that will be used in the % computation at the end
  double numRight = 0;
  double total = 0;

  // do while loop for after first run to determine continuation
  do {
    // instantiating variables in the specified order that input is expected
    // from user
    cin >> int1 >> arith >> int2 >> relation >> int3;

    if ( arith == '+' || arith == '-' ||
      arith == '*' || arith == '/' || arith == '%' )
        arith_valid = true;
    else
      arith_valid = false;
    if ( relation == '<' || relation == '>' )
      relation_valid = true;
    else
      relation_valid = false;
    bool expression_valid;
    if ( !arith_valid && !relation_valid ) {
      cout << "Unrecognized arithmetic operator " << arith << endl;
      cout << "Unrecognized relational operator " << relation << endl;
    } else if ( !arith_valid ) {
      cout << "Unrecognized arithmetic operator " << arith << endl;
    } else if ( !relation_valid ) {
      cout << "Unrecognized relational operator " << relation << endl;
    } else {
    switch (relation) {
      case '<' :
        switch (arith) {
          case '+' :
            if ( (int1 + int2) < int3 )
              expression_valid = true;
            else
              expression_valid = false;
            break;
          case '-' :
            if ( (int1 - int2) < int3 )
              expression_valid = true;
            else
              expression_valid = false;
            break;
          case '*' :
            if ( (int1 * int2) < int3 )
              expression_valid = true;
            else
              expression_valid = false;
            break;
          case '/' :
            if ( (int1 / int2) < int3 )
              expression_valid = true;
            else
              expression_valid = false;
            break;
          case '%' :
            if ( (int1 % int2) < int3 )
              expression_valid = true;
            else
              expression_valid = false;
            break;
        }
        break;
      case '>' :
      switch (arith) {
          case '+' :
            if ( (int1 + int2) > int3 )
              expression_valid = true;
            else
              expression_valid = false;
            break;
          case '-' :
            if ( (int1 - int2) > int3 )
              expression_valid = true;
            else
              expression_valid = false;
            break;
          case '*' :
            if ( (int1 * int2) > int3 )
              expression_valid = true;
            else
              expression_valid = false;
            break;
          case '/' :
            if ( (int1 / int2) > int3 )
              expression_valid = true;
            else
              expression_valid = false;
            break;
          case '%' :
            if ( (int1 % int2) > int3 )
              expression_valid = true;
            else
              expression_valid = false;
            break;
        }
      }
      if ( expression_valid ) {
        cout << int1 << " " << arith << " " << int2 << " " << relation
        << " " << int3 << " - Correct" << endl;
        ++numRight, ++total;
      } else {
        cout << int1 << " " << arith << " " << int2 << " " << relation
        << " " << int3 << " - Incorrect" << endl;
        ++total;
      }
    }
    // initializes cont based on user input
    cin >> cont;
  } while (cont == 'c');
  // initializes variable to be the percent returned and rounds it
  double round;
  if ( total == 0 ) {
    round = 0.00;
  } else {
    round = numRight / total;
    round *= 10000;
    round += 0.5;
    round = floor(round);
    round /= 100;
  }
  cout << numRight << " of " << total << " = " << std::fixed
  << std::setprecision(2) << round << "%" << endl;
  return 0;
}
