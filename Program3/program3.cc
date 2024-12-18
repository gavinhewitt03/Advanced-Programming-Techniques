// Copyright 2023 ghewitt
// Program 3 Assignment
#include<iostream>
using std::cin;
using std::cout;
using std::endl;

#include<fstream>
using std::ifstream;

int main(int num_cstrings, char * cstrings[]) {
  // int pointer to hold integer values corresponding to each letter
  int * char_count;
  char_count = new int[26];
  
  // checks to make sure memory was reserved
  if ( char_count == nullptr ){
    return 0;
  }

  for (int i = 0; i < 26; ++i) {
    char_count[i] = 0;
  }

  // input file object
  ifstream input_file(cstrings[1]);
  char next;
  input_file >> next;
  while ( input_file.good() ){
    // loop to check what alphabetic character next is
    for ( int i = 65; i <= 90; ++i ) {
      // if A-Za-z
      if ( next == i || next == (i + 32) ) {
       // increment character count for that letter
       ++char_count[i - 65];
      }
    }
    input_file >> next;
  }

  // 2D array to link character to count
  int char_n_count[26][2];
  for ( int i = 0; i < 26; ++i ) {
    char_n_count[i][0] = i + 97;
    char_n_count[i][1] = char_count[i];
  }

  // bubble sort 2D array to be printed in descending order
  for (int i = 0; i < 26; ++i) {
    for (int j = 0; j < 26 - i; ++j) {
      if(char_n_count[j][1] < char_n_count[j + 1][1]) {
        int temp0 = char_n_count[j][0];
        int temp1 = char_n_count[j][1];
        char_n_count[j][0] = char_n_count[j + 1][0];
        char_n_count[j][1] = char_n_count[j + 1][1];
        char_n_count[j + 1][0] = temp0;
        char_n_count[j + 1][1] = temp1;
      }
    }
  }

  int max = char_n_count[0][1];
  int maxCount = 0;
  int min = char_n_count[25][1];
  int minCount = 0;

  for (int i = 0; i < 26; ++i) {
    if (char_n_count[i][1] == max)
      ++maxCount;
    if (char_n_count[i][1] == min)
      ++minCount;
  }

  if (maxCount > 1) {
    if (max != 1)
      cout << "Highest frequency characters (appeared " << max << " times in the file): ";
    else
      cout << "Highest frequency characters (appeared " << max << " time in the file): ";
    for (int i = 0; i < maxCount; ++i) {
      char c = char_n_count[i][0];
      if ( maxCount == 2) {
        if (i != maxCount - 1)
        cout << c;
      else
        cout << " and " << c << endl;
      } else {
        if (i != maxCount - 1)
          cout << c << ", ";
        else
          cout << " and " << c << endl;
      }
    }
  } else {
    char c = char_n_count[0][0];
    cout << "Highest frequency character (appeared " << max << " times in the file): "
    << c << endl;
  }

  if (minCount > 1) {
    if (min != 1)
      cout << "Lowest frequency characters (appeared " << min << " times in the file): ";
    else
      cout << "Lowest frequency characters (appeared " << min << " time in the file): ";
    for (int i = 26 - minCount; i < 26; ++i) {
      char c = char_n_count[i][0];
      if ( minCount == 2) {
        if (i != 25)
        cout << c;
      else
        cout << " and " << c << endl;
      } else {
        if (i != 25)
          cout << c << ", ";
        else
          cout << "and " << c << endl;
      }
    }
  } else {
    char c = char_n_count[25][0];
    cout << "Lowest frequency character (appeared " << min << " times in the file): "
    << c << endl;
  }

  cout << endl;

  // print the list of descending character counts
  for (int i = 0; i < 26; ++i) {
    char c = char_n_count[i][0];
    cout << c << ": " << char_n_count[i][1] << endl;
  }

  cout << endl;
  
  // 2D array for the graph
  char graph[char_n_count[0][1] + 1][26];

  // populating axes
  for (int i = 0; i < char_n_count[0][1] + 1; ++i) {
    for (int j = 0; j < 26; ++j) {
      if (i == char_n_count[0][1]) {
        char c = 97 + j;
        graph[i][j] = c;
      } else {
        graph[i][j] = ' ';
      }
    }
  }

  // populate graph with '*' corresponding to char counts
  for (int i = 0; i < char_n_count[0][1]; ++i) {
    for (int j = 0; j < 26; ++j) {
      if (char_n_count[0][1] - i <= char_count[j]) {
        graph[i][j] = '*';
      }
    }
  }

  // print graph
  for (int i = 0; i < char_n_count[0][1] + 1; ++i) {
    if (char_n_count[0][1] > 9) {
      if (char_n_count[0][1] - i > 9)
        cout << char_n_count[0][1] - i << " ";
      else if (char_n_count[0][1] - i > 0)
        cout << " " << char_n_count[0][1] - i << " ";
      else
        cout << "   ";
    } else {
      if (char_n_count[0][1] - i > 0)
        cout << char_n_count[0][1] - i << " ";
      else
        cout << "  ";
    }
    for (int j = 0; j < 26; ++j) 
      if (j != 25)
        cout << graph[i][j] << " ";
      else
        cout << graph[i][j] << endl;
  }

  // deallocate memory
  delete [] char_count;
  char_count = nullptr;
  return 0;
}