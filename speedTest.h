
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

struct studentas{
    string vardas;
    string pavarde;
    int pazymiai=0;
    int egz;
    float galutinis=0;
};

bool compare(studentas first, studentas second); // palyginimas pagal galutini pazymi
void failu_kurimas(std::string, int, int);
void greicio_analize_List(std::string, int);
void greicio_analize_Vector(std::string, int, int);

