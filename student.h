#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>
#include "degree.h"
using namespace std;

class Student {
public:
    Student();
    Student(string studentId, string firstName, string lastName, string emailAddress, int age, int daysToComplete[], DegreeProgram degreeProgram);
    void print();

    const static int daysArraySize = 3;

    // Student ID
    void setStudentId(string studentId);
    string getStudentId();

    // First Name
    void setFirstName(string firstName);
    string getFirstName();

    // Last Name 
    void setLastName(string lastName);
    string getLastName();

    // Email Address
    void setEmail(string emailAddress);
    string getEmail();

    // Age
    void setAge(int age);
    int getAge();

    // Days to complete classes
    void setDaysToComplete(int daysToComplete[]);
    int* getDaysToComplete();

    // Degree Program
    void setDegreeProgram(DegreeProgram degreeProgram);
    DegreeProgram getDegreeProgram();

private:
    string studentId;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int daysToComplete[daysArraySize];
    DegreeProgram degreeProgram;
};

#endif