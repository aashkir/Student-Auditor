#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Student.h"

Student::Student(int i)
{
  id = i;
  //numCourses = 0;
}

Student& Student::operator+=(Course* course)
{
  //courses.add(course);
  courses+=course;
  return *this;
}

int Student::getStudentID()
{
 return id;
}

float Student::computeGPA() {
  return courses.computeGPA();
}

int Student::computeNumFW() {
  return courses.computeNumFW();
}

void Student::print()
{
  cout << endl << "Student #: " << id <<  " GPA: " << computeGPA() <<  endl;
  courses.print();
}

Student::~Student()
{

}
