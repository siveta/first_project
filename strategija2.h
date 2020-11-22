
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

struct studentas2 {
    string vardas;
    string pavarde;
    int pazymiai = 0;
    int egz;
    float galutinis = 0;
};

bool compare(studentas2 first, studentas2 second); // palyginimas pagal galutini pazymi
void greicio_analize2_List(std::string, int);
void greicio_analize2_Vector(std::string, int, int);