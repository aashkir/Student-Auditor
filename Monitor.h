#ifndef MONITOR_H
#define MONITOR_H

#include <string>
#include <vector>
#include "Student.h"

using namespace std;

class Monitor
{
  public:
    Monitor();
    virtual void update(Student*) = 0;
    /*
      Function: printLogs
      Purpose: prints the logs of the monitor
    */
    void printLogs();
    virtual ~Monitor();
  protected:
    vector<string> logs;
};

#endif
