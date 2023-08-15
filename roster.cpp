#include "roster.h"

void Roster::parse(string studentData) {
    int rightSide = studentData.find(',');
    string studentId = studentData.substr(0, rightSide);

    int leftSide = rightSide + 1;
    rightSide = studentData.find(",", leftSide);
    string firstName = studentData.substr(leftSide, rightSide - leftSide);

    leftSide = rightSide + 1;
    rightSide = studentData.find(",", leftSide);
    string lastName = studentData.substr(leftSide, rightSide - leftSide);

    leftSide = rightSide + 1;
    rightSide = studentData.find(",", leftSide);
    string emailAddress = studentData.substr(leftSide, rightSide - leftSide);

    leftSide = rightSide + 1;
    rightSide = studentData.find(",", leftSide);
    int age = stoi(studentData.substr(leftSide, rightSide - leftSide));

    leftSide = rightSide + 1;
    rightSide = studentData.find(",", leftSide);
    int course1 = stoi(studentData.substr(leftSide, rightSide - leftSide));

    leftSide = rightSide + 1;
    rightSide = studentData.find(",", leftSide);
    int course2 = stoi(studentData.substr(leftSide, rightSide - leftSide));

    leftSide = rightSide + 1;
    rightSide = studentData.find(",", leftSide);
    int course3 = stoi(studentData.substr(leftSide, rightSide - leftSide));

    leftSide = rightSide + 1;
    rightSide = studentData.find(",", leftSide);
    string parsedProgram = studentData.substr(leftSide, rightSide - leftSide);
    DegreeProgram degreeProgram = UNDECLARED;
    if (parsedProgram == "SECURITY") { degreeProgram = SECURITY; }
    if (parsedProgram == "NETWORK") { degreeProgram = NETWORK; }
    if (parsedProgram == "SOFTWARE") { degreeProgram = SOFTWARE; }

    addStudent(studentId, firstName, lastName, emailAddress, age, course1, course2, course3, degreeProgram);
}


void Roster::addStudent(string studentId, string firstName, string lastName, string emailAddress, int age, int course1, int course2, int course3, DegreeProgram degreeProgram) {
    int courses[3] = { course1, course2, course3 };

    classRosterArray[++lastIndex] = new Student(studentId, firstName, lastName, emailAddress, age, courses, degreeProgram);
}

void Roster::printAllStudents() {
    for (int i = 0; i <= Roster::getLastIndex(); i++) {
        classRosterArray[i]->print();
    }
}

void Roster::removeStudent(string studentId) {
    bool found = false;

    for (int i = 0; i < Roster::lastIndex; i++) {
        if (classRosterArray[i]->getStudentId() == studentId) {
            found = true;
            if (i < numStudents - 1) {
                Student* temp = classRosterArray[i];
                classRosterArray[i] = classRosterArray[numStudents - 1];
                classRosterArray[numStudents - 1] = temp;
            }
            Roster::lastIndex--;
        }
    }

    if (found) {
        cout << studentId << " was successfully removed" << endl;
    }
    else {
        cout << "Error: " << studentId << " was not found" << endl;
    }
}

void Roster::printAverageDays(string studentId) {

    for (int i = 0; i < Roster::lastIndex; i++) {
        if (classRosterArray[i]->getStudentId() == studentId) {
            int totalDays = 0;
            totalDays += classRosterArray[i]->getDaysToComplete()[0];
            totalDays += classRosterArray[i]->getDaysToComplete()[1];
            totalDays += classRosterArray[i]->getDaysToComplete()[2];
            cout << classRosterArray[i]->getStudentId() << ": " << totalDays / 3 << endl;
        }

    }
}

void Roster::printInvalidEmails() {
    for (int i = 0; i <= Roster::lastIndex; i++) {
        bool foundInvalidEmail = false;
        string studentEmail = classRosterArray[i]->getEmail();

        if (studentEmail.find(' ') != string::npos) {
            foundInvalidEmail = true;
        }
        if (studentEmail.find('@') == string::npos || studentEmail.find('.') == string::npos) {
            foundInvalidEmail = true;
        }

        if (foundInvalidEmail) {
            cout << studentEmail << endl;
        }
    }
}

void Roster::printByDegree(DegreeProgram degreeProgram) {
    for (int i = 0; i <= Roster::lastIndex; i++) {
        if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
            classRosterArray[i]->print();
        }
        cout << endl;
    }
}

Roster::~Roster() {
    for (int i = 0; i < numStudents; i++) {
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
    cout << "Repo destroyed" << endl;
}