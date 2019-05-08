#ifndef GPAMONITOR_H
#define GPAMONITOR_H

#include "Monitor.h"
#include <vector>

using namespace std;

class GPAMonitor : public Monitor
{
  public:
    GPAMonitor(float m);
    /*
      Function: update
      Purpose: flags a student if their gpa is below the minimum
      in: new student
    */
    virtual void update(Student*);
    virtual ~GPAMonitor();
  private:
    float minGPA; // minimum threshold for GPA
};

#endif
