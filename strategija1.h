
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <sstream> 
#include <vector> 
#include <algorithm>
#include <chrono>
#include <string>
#include <list>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::list;
using std::sort;

struct studentas {
    string vardas;
    string pavarde;
    int pazymiai = 0;
    int egz;
    float galutinis = 0;
};

void failu_kurimas(string, int, int);
bool compare(studentas first, studentas second); // palyginimas pagal galutini pazymi
void greicio_analize_List(std::string, int);
void greicio_analize_Vector(std::string, int, int);
