#include "Monitor.h"
#include <iostream>
#include <string>
using namespace std;


Monitor::Monitor() {

}

void Monitor::printLogs() {
  cout << "LOGS: " << endl;
  for (int i=0; i<logs.size(); ++i) {
    cout << logs[i] << endl;
  }
}

Monitor::~Monitor() { }
