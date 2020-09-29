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
    int paz[1];
    float galutinis = 0;
};

int main() {
    int n = 0;
    
    cout << "Sveiki!\n";
    cout << "Irasykite studentu skaiciu :\n";
    cin >> n; // studentu skaicius 
    studentas* grupe = new studentas[n]; // studentu masyvas is n nariu
    for (int i = 0; i < n; i++) {
        int m = 0;
        cout << "Iveskite eil.duomenis (vardas, pavarde, egz.paz.):\n";
        cin >> grupe[i].vardas >> grupe[i].pavarde >> grupe[i].egz; // ivedame varda pavarde ir egzamino rezultata
        
        while (true) {
            cout << "Noredami baigti pazymiu ivedima parasykite '0'\n";
            cout << "Iveskite " << m + 1 << "-aji pazymi:\n"; 
            cin >> grupe[i].paz[m];
            if (grupe[i].paz[m] != 0) {
                int* pazymiai = new int[m + 1];
                for (int j = 0; j < m ; j++) {                  
                    pazymiai[j] = grupe[i].paz[m];
                    grupe[i].galutinis = grupe[i].galutinis + pazymiai[j];
                }
                m = m + 1;
            }
            else { 
                break; 
            }
    }
        cout << "pazymiu suma- " << grupe[i].galutinis << endl;
        grupe[i].galutinis = grupe[i].galutinis / m;
        cout << "Ivesta pazymiu - " << m << endl;
        cout << "pazymiu vidurkis - " << grupe[i].galutinis << endl;
        cout << "egzaminas - " << grupe[i].egz << endl;
        grupe[i].galutinis = grupe[i].galutinis * 0.4 + 0.6 * grupe[i].egz;
    }
    cout << "Pavarde\t\t" << "Vardas\t\t" << "Galutinis(Vid.)\n";
    cout << "------------------------------------------------------------------------\n";
    for (int i = 0; i < n; i++) {
        cout << grupe[i].vardas << "\t\t" << grupe[i].pavarde << "\t\t" << grupe[i].galutinis << endl;
    }
}