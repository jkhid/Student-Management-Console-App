#include <iostream>
#include "student.h"
#include "degree.h"
#include "roster.h"
using namespace std;

int main() {
    const int numStudents = 5;
    const string studentData[] = {
    "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    };

    cout << "Scripting and Programming - Applications - C867" << " | " << "C++" << " | " << "011078274" << " | " << "Jamal Khidir" << endl;
    cout << endl;
    Roster classRoster;

    for (int i = 0; i < numStudents; i++) {
        classRoster.parse(studentData[i]);
    }

    cout << "********* printAll() function *********" << endl;
    classRoster.printAllStudents();
    cout << endl;

    cout << "********* printInvalidEmails() function *********" << endl;
    classRoster.printInvalidEmails();
    cout << endl;

    cout << "********* printAverageDays() function *********" << endl;
    for (int i = 0; i < numStudents; i++) {
        classRoster.printAverageDays(classRoster.getRosterArray()[i]->getStudentId());
    }
    cout << endl;

    cout << "********* printByDegree() function *********" << endl;
    classRoster.printByDegree(SOFTWARE);
    cout << endl;

    cout << "********* removeStudent() functionality *********" << endl;
    classRoster.removeStudent("A3");
    classRoster.printAllStudents();
    classRoster.removeStudent("A3");
    cout << endl;
}
