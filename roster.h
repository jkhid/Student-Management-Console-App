#pragma once
#include <iostream>
#include <string>
#include "student.h"
using namespace std;

class Roster {
public:
    void parse(string studentData);
    void addStudent(string studentId, string firstName, string lastName, string emailAddress, int age, int course1, int course2, int course3, DegreeProgram degreeProgram);
    int getLastIndex() { return lastIndex; }
    void printAllStudents();
    void removeStudent(string studentId);
    void printAverageDays(string studentId);
    void printInvalidEmails();
    void printByDegree(DegreeProgram degreeProgram);
    Student** getRosterArray() { return classRosterArray; }
    ~Roster();

private:
    int lastIndex = -1;
    const static int numStudents = 5;
    Student* classRosterArray[numStudents];
};



