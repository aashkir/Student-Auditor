#ifndef VIEW_H
#define VIEW_H

#include "Storage.h"

class View {

  public:
    View();
    /*
      Function: mainMenu
      Purpose: prompts user for selection
      Parameters:
        out: menuSelection, gives back user selection
    */
    void mainMenu(int& menuSelection);
    /*
      Function: readStudentId
      Purpose: prompts user for student ID
      Parameters:
        out: id, gives back student id
    */
    void readStudentId(int& id);
    /*
      Function: readCourseInfo
      Purpose: prompts user for course info
      Parameters:
        out: courseCode, grade, term, instructor
        all used in creating the course object
    */
    void readCourseInfo(int& courseCode, int& grade, int& term, string& instructor);
    /*
      Function: print
      Purpose: prints the students and their data members
      Parameters:
        in: students to be printed
    */
    void print(Storage& students);

  private:

};
#endif
