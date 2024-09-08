#include <iostream>
using namespace std;

#include "student.cpp"

//*******************************************************************
// Program:	in-class exercise #2
// Author:	(you)
// Date:	09/06/22 and 09/08/22
// This program creates instances of class Student and demonstrates
// the use of various features of the class
//*******************************************************************
int main( )
{
  Student s1;
  s1.input();

  s1.output();

// The next line is an example of usage of a mutator function that could
// be added, which would allow you to modify just one data member instead
// of the whole class instance.

//  s1.new_lname("chamberlain");
//  s1.output();

  return 0;
}

