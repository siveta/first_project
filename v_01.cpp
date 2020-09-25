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
    int paz[10];
    float galutinis = 0;
};

int main()
{
    int n = 0;
    studentas Eil;
    cout << "Sveiki, iveskite eil.duomenis (vardas, pavarde, egz.paz.):\n";
    cin >> Eil.vardas >> Eil.pavarde >> Eil.egz;
    cout << "Iveskite skaiciu kiek namu darbu noresite ivesti :";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Iveskite " << i + 1 << "-aji pazymi :\n";
        cin >> Eil.paz[i];
        if (Eil.paz[i] <= 0 or Eil.paz[i] > 10) {
            cout << "Klaida! Iveskite pazymius dar karta:\n";
            i = i - 1;
        }
        else {
            Eil.galutinis = Eil.galutinis + (float)Eil.paz[i];
        }

    }
    Eil.galutinis = Eil.galutinis / n;
    Eil.galutinis = Eil.galutinis * 0.4 + 0.6 * Eil.egz;

    cout << "Pavarde\t\t" << "Vardas\t\t" << "Galutinis(Vid.)\n";
    cout << "------------------------------------------------------------------------\n";
    cout << Eil.vardas << "\t\t" << Eil.pavarde << "\t\t" << Eil.galutinis;