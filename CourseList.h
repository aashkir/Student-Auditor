#ifndef COURSELIST_H
#define COURSELIST_H

#include "List.h"
#include "Course.h"

using namespace std;

class CourseList : public List<Course*>
{
  public:
    CourseList();
    virtual ~CourseList();
    //virtual bool operator<(Book* book);
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

};


#endif
