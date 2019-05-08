#include "CourseList.h"
#include <string>

CourseList::CourseList() : List<Course*>() {

}

float CourseList::computeGPA() {
  float gpa = 0;
  string grade = "";
  int courseNum = 0;
  Node* currNode = head;
  while (currNode != NULL) {
    currNode->data->getGradeStr(grade);
    if (grade != "WDN") {
      gpa += currNode->data->getGrade();
      courseNum++;
    }
    currNode = currNode->next;
  }

  if (courseNum > 0)
    return gpa/courseNum;
  // empty list, all withdrawn
  return 0.0;
}

int CourseList::computeNumFW() {
  int numFW = 0;
  string grade = "";
  Node* currNode = head;

  while (currNode != NULL) {
    currNode->data->getGradeStr(grade);
    if (grade == "WDN" || grade == "F")
      numFW++;
    currNode = currNode->next;
  }
  return numFW;
}

CourseList::~CourseList() {

}
