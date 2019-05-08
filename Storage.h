#ifndef STORAGE_H
#define STORAGE_H

#include "defs.h"
#include "Student.h"

class Storage
{
  public:
    Storage();
    /*
      Function: overloaded += operator
      Purpose: adds a Student pointer to the back of the array data member of this object
      Parameters:
        in: student pointer to be added to back of array
    */
    Storage& operator+=(Student*);
    /*
      Function: print
      Purpose: prints the student array
    */
    void print();
    ~Storage();

  private:
    Student *students[MAX_NUM_STU];
    int    numStudents;
};

#endif
