#include "GPAMonitor.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>

GPAMonitor::GPAMonitor(float m) : Monitor(), minGPA(m) {

}

void GPAMonitor::update(Student* student) {
  stringstream log_s;
  if (student->computeGPA() < minGPA) {
    log_s << "- ID: " << student->getStudentID() << " GPA: " << student->computeGPA();
    logs.push_back(log_s.str());
  }
}

GPAMonitor::~GPAMonitor() {

}
