#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <list>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::list;

struct studentas {
    string vardas;
    string pavarde;
    int pazymiai;
    int egz;
    float galutinis = 0;
};

bool compare(studentas first, studentas second); // palyginimas pagal pavarde

void failu_kurimas(std::string, int, int);