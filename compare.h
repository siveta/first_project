#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;

struct studentas {
    string vardas;
    string pavarde;
    vector <double> namuDarbai;
    int egz;
    float med = 0;
    float galutinis = 0;
};

bool compare(studentas first, studentas second); // palyginimas pagal pavarde