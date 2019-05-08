#include "FWMonitor.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>

FWMonitor::FWMonitor(float m) : Monitor(), maxFW(m) {
}

void FWMonitor::update(Student* student) {
  stringstream log_s;
  if (student->computeNumFW() > maxFW) {
    log_s << "- ID: " << student->getStudentID() << " FW: " << student->computeNumFW();
    logs.push_back(log_s.str());
  }
}

FWMonitor::~FWMonitor() {

}
