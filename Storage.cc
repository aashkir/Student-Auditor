#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Storage.h"

Storage::Storage() : numStudents(0) {}

Storage& Storage::operator+=(Student* stu)
{
  if (numStudents < MAX_NUM_STU)
    students[numStudents++] = stu; // add student pointer to back of student pointer array
  else
    cout << "Error: Students are full." << endl;

  return *this;
}

void Storage::print()
{
  cout << endl << "Students: " << endl;

  for (int i = 0; i < numStudents; i++)
    students[i]->print();
}

Storage::~Storage()
{
  for (int i = 0; i < numStudents; i++) {
    delete students[i];
  }
}
