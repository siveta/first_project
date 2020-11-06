
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <sstream> 
#include <string>
#include <algorithm>
#include <vector> 
#include <chrono>

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

bool compare(studentas first, studentas second); // palyginimas pagal galutini pazymi
void failu_kurimas(std::string, int, int);
void operacijos(std::string, int, int, string);