#pragma once
#ifndef DEGREE_H
#define DEGREE_H
#include <string>
using namespace std;

enum DegreeProgram { SECURITY, NETWORK, SOFTWARE, UNDECLARED };

const static string degreeProgramString[] = { "SECURITY", "NETWORK", "SOFTWARE", "UNDECLARED" };

inline DegreeProgram degreeProgramToString(const string& degreeString) {
    if (degreeString == "SECURITY") { return SECURITY; }
    if (degreeString == "NETWORK") { return NETWORK; }
    if (degreeString == "SOFTWARE") { return SOFTWARE; }
    if (degreeString == "UNDECLARED") { return UNDECLARED; }
}

#endif
