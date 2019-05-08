#ifndef FWMONITOR_H
#define FWMONITOR_H

#include "Monitor.h"
#include <vector>

using namespace std;


class FWMonitor : public Monitor
{
  public:
    FWMonitor(float m);
    /*
      Function: update
      Purpose: flags a student if they have more than the maximum FW
      in: new student
    */
    virtual void update(Student*);
    virtual ~FWMonitor();
  private:
    float maxFW; // maximum threshold for FW
};

#endif
