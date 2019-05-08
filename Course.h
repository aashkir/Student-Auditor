#ifndef COURSE_H
#define COURSE_H

using namespace std;
#include <string>

class Course
{
  public:
    Course(int=0, int=0, int=0, string="undefined");
    /*
      Function: print
      Purpose: prints the data members of the course object
    */
    void print();
    /*
      Funcion: lessThan
      Purpose: returns true if course is less than other course passed.
      Parameters:
        in: course to be compared
    */
    bool lessThan(Course*);
    // getters
    int getGrade();
    /*
      Function: getGradeStr
      Purpose: returns a string based on course object's grade
      Parameters:
        out: gradeStr
    */
    void getGradeStr(string&);


  private:
    int code;	// course code, for example 2404 for COMP2404
    int grade;	// numeric grade from 0 (F) to 12 (A+), with -1 for WDN
    int term; // term, is the year appended with 10 = winter, 20 = summer, 30 = fall
    string instructor; // instructor name
};

#endif
