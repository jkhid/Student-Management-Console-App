#include <iostream>
#include <string>
#include "student.h"
#include "degree.h"
using namespace std;

// Default constructor
Student::Student() {
    this->studentId = "";
    this->firstName = "";
    this->lastName = "";
    this->emailAddress = "";
    this->age = 0;
    for (int i = 0; i < daysArraySize; i++) { this->daysToComplete[i] = 0; }
    this->degreeProgram = DegreeProgram::UNDECLARED;
}

// Overloaded constructor
Student::Student(string studentId, string firstName, string lastName, string emailAddress, int age, int daysToComplete[], DegreeProgram degreeProgram) {
    this->studentId = studentId;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    for (int i = 0; i < daysArraySize; i++) { this->daysToComplete[i] = daysToComplete[i]; }
    this->degreeProgram = degreeProgram;
}

void Student::print() {
    cout << this->getStudentId() << "    ";
    cout << "First Name: " << firstName << "    ";
    cout << "Last Name: " << lastName << "    ";
    // cout << "Email Address: " << this->getEmail() << '\t';
    cout << "Age: " << this->getAge() << "    ";
    cout << "Days to complete classes: " << "{" << this->getDaysToComplete()[0] << ", " << getDaysToComplete()[1] << ", " << getDaysToComplete()[2] << "}" << "    ";
    cout << "Degree program: " << degreeProgramString[this->getDegreeProgram()] << '\n';
}

// Student ID
void Student::setStudentId(string studentId) {
    this->studentId = studentId;
}
string Student::getStudentId() {
    return this->studentId;
}

// First Name
void Student::setFirstName(string firstName) {
    this->firstName = firstName;
}
string Student::getFirstName() {
    return this->firstName;
}

// Last Name
void Student::setLastName(string lastName) {
    this->lastName = lastName;
}
string Student::getLastName() {
    return this->lastName;
}

// Email
void Student::setEmail(string emailAddress) {
    this->emailAddress = emailAddress;
}
string Student::getEmail() {
    return this->emailAddress;
}

// Age
void Student::setAge(int age) {
    this->age = age;
}
int Student::getAge() {
    return this->age;
}

// Days to complete class array
void Student::setDaysToComplete(int daysToComplete[]) {
    for (int i = 0; i < daysArraySize; i++) {
        this->daysToComplete[i] = daysToComplete[i];
    }
}
int* Student::getDaysToComplete() {
    return this->daysToComplete;
}

// Degree Program
void Student::setDegreeProgram(DegreeProgram degreeProgram) {
    this->degreeProgram = degreeProgram;
}
DegreeProgram Student::getDegreeProgram() {
    return this->degreeProgram;
}