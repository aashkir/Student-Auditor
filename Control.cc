#include <string>
using namespace std;
#include <iostream>
#include <sstream>
#include "Control.h"

Control::Control() {
  GPAMonitor* gpaMonitor = new GPAMonitor(3.0);
  FWMonitor* fwMonitor = new FWMonitor(2);
  monitors.push_back(gpaMonitor);
  monitors.push_back(fwMonitor);

  // Adding students from cloud
  vector<string> stuVector;
  stringstream ss;

  stuServer.retrieve(stuVector);

  int     stuId, courseCode, grade, term;
  string  instructor;

  for (int i = 0; i < stuVector.size(); i++) {
    ss.clear();
    ss.str(stuVector[i]);
    // create the student
    ss >> stuId;
    Student* student = new Student(stuId);
    // add courses to the student
    // each course takes 4 parameters
    while (true) { // take the first param here, since we have to test it
      ss >> courseCode;
      //cout << courseCode;
      if (courseCode == 0) // done adding courses for this student
        break;

      ss >> term >> grade >> instructor;
      Course* course = new Course(courseCode, grade, term, instructor);
      //student->addCourse(course);
      *student+=course;
    }
    //students.addStudent(student);
    students+=student;
  }
}

void Control::launch() {
  int     stuId, courseCode, grade, term;
  string  instructor;
  int     menuSelection;

  while (1) {
    // find out what user selected in main menu
    view.mainMenu(menuSelection);
    // creating student
    if (menuSelection == 0)
      break;
    else if (menuSelection == 1) {
      view.readStudentId(stuId);
      Student* student = new Student(stuId);
      while (1) {
        view.readCourseInfo(courseCode, grade, term, instructor);
        if (courseCode == 0)
          break;
        Course* course = new Course(courseCode, grade, term, instructor);
        //student->addCourse(course);
        *student+=course;
      }
      //students.addStudent(student);
      students+=student;
      notify(student); // notify observers
    }
  }

  students.print();
}

void Control::notify(Student* newStu) {
  for (int i=0; i<monitors.size(); ++i)
    monitors[i]->update(newStu);
}

Control::~Control() {
  for (int i=0; i<monitors.size(); ++i) {
    monitors[i]->printLogs();
    delete monitors[i];
  }
}
