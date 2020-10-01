#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;

struct studentas {
    string vardas;
    string pavarde;
    int egz;
    float galutinis = 0;
};

int main() {
    int n = 0;
    int a;
    cout << "Sveiki!\n";
    cout << "Irasykite studentu skaiciu :\n";
    cin >> n; // studentu skaicius 
    studentas* grupe = new studentas[n]; // studentu masyvas is n nariu
    for (int i = 0; i < n; i++) {
        int m = 0;
        cout << "Iveskite eil.duomenis (vardas, pavarde, egz.paz.):\n";
        cin >> grupe[i].vardas >> grupe[i].pavarde >> grupe[i].egz; // ivedame varda pavarde ir egzamino rezultata 
        
        while (true) {
            int* paz = new int[m+1];
            cout << "Noredami uzbaigti pazymiu ivedima, parasykite skaiciu '0'\n";
            cout << "Iveskite " << m + 1 << "-aji pazymi:" << endl;
            cin >> paz[m];
            if (paz[m] != 0) {
                grupe[i].galutinis = grupe[i].galutinis + paz[m];               
                m++;
                delete[] paz;               
            }
            else {
                break;
            }
        }
        grupe[i].galutinis = grupe[i].galutinis / m;
        grupe[i].galutinis = grupe[i].galutinis * 0.4 + 0.6 * grupe[i].egz;    
    }

    cout << "Pavarde\t\t" << "Vardas\t\t" << "Galutinis(Vid.)\n";
    cout << "------------------------------------------------------------------------\n";
    for (int i = 0; i < n; i++) {
        cout << grupe[i].vardas << "\t\t" << grupe[i].pavarde << "\t\t" << grupe[i].galutinis << endl;
    }
}