#include "Course.h"
#include <iostream>
#include <iomanip>

Course::Course(int c, int g, int t, string i) : code(c), grade(g), term(t), instructor(i)
{

}

void Course::print()
{
  string str;

  cout << "-- COMP " << code << ":  ";
  cout << right << setw(6) << term << "  ";
  cout << right << setw(2) << grade   << "  ";
  getGradeStr(str);
  cout << left << setw(3) << str << "  ";
  cout << instructor << "  " << endl;
}

void Course::getGradeStr(string& gradeStr)
{
  string gradeStrings[] = {
    "WDN", "F", "D-", "D", "D+", "C-", "C", "C+",
    "B-", "B", "B+", "A-", "A", "A+" };

  if ( grade >= -1 && grade <= 12 )
    gradeStr = gradeStrings[grade+1];
  else
    gradeStr = "Unknown";
}

bool Course::lessThan(Course* c)
{
  if (code == c->code)
    return term < c->term;
  return code < c->code;
}

int Course::getGrade() {
  return grade;
}
