#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

void initVect(vector<string>&);

int main() 
{
  vector<string> animalVect;
  stringstream ss;
  int id, age;
  string name, animalType;

  initVect(animalVect);

  for (int i=0; i<animalVect.size(); ++i) {
    ss.clear();
    ss.str(animalVect[i]);
    ss >> id >> animalType >> name >> age;
    cout << "Animal: "<< animalType << ", name " << setw(10) << name << ", age " << age << endl;
  }

}

void initVect(vector<string>& vect)
{
/*
  Adds every new record as a string formated as follows: id type name age
*/

  vect.push_back("7010 Dog Buster 3");
  vect.push_back("7011 Dog Princess 2");
  vect.push_back("7012 Cat Lady 8");
  vect.push_back("7013 Cat Hero 5");
  vect.push_back("7014 Cat Tiger 9");
  vect.push_back("7015 Dog Spike 9");

}
