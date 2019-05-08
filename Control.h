#ifndef CONTROL_H
#define CONTROL_H

#include "View.h"
#include "Student.h"
#include "Course.h"
#include "Storage.h"
#include "Monitor.h"
#include "FWMonitor.h"
#include "GPAMonitor.h"
#include "StuServer.h"
#include <vector>

class Control {
  public:
    Control();
    /*
      Function: launch
      Purpose: does the control flow for the program
    */
    void launch();
    ~Control();

  private:
    View view; // view object for user interaction
    Storage students; // storage object for our students
    vector<Monitor*> monitors; // stores observers
    StuServer stuServer;
    /*
      Function: notify
      Purpose: tells observers that a student as been added
      in: new student
    */
    void notify(Student* newStu);
};

#endif
