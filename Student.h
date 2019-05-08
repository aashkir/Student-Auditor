#ifndef STUDENT_H
#define STUDENT_H

#include "defs.h"
#include "Course.h"
#include "List.h"
#include "CourseList.h"

class Student
{
  public:
    Student(int=0);
    ~Student();
    /*
      Function: Overloaded +=
      Purpose: adds a Course pointer to the back of the array data member of this object
      Parameters:
        in: course pointer to be added to back of array
    */
    Student& operator+=(Course*);
    /*
      Function: computeGPA
      Purpose: returns GPA as float
    */
    float computeGPA();
    /*
      Function: computeNumFW
      Purpose: returns number of failed or withdrawn courses
    */
    int computeNumFW();
    /*
      Function: print
      Purpose: prints the data members of the student object
    */
    void print();
    /* getters */
    int getStudentID();

  private:
    int    id;
    CourseList courses;
};

#endif
