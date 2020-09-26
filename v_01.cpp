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

int main() {
    int n = 0;
    cout << "Sveiki!\n";
    cout << "Irasykite studentu skaiciu :\n";
    cin >> n;
    studentas* grupe = new studentas[n];
    for (int i = 0; i < n; i++) {
        cout << "Iveskite eil.duomenis (vardas, pavarde, egz.paz.):\n";
        cin >> grupe[i].vardas >> grupe[i].pavarde >> grupe[i].egz;
        for (int j = 0; j < 5; j++) {
            cout << "Iveskite " << j + 1 << "-aji pazymi :\n";
            cin >> grupe[i].paz[j];
            if (grupe[i].paz[j] < 0 or grupe[i].paz[j] > 10 or isdigit(grupe[i].paz[j] = false)) {
                cout << "Klaida! Iveskite pazymius dar karta:\n";
                j = j - 1;
            }
            else {
                grupe[i].galutinis = grupe[i].galutinis + (float)grupe[i].paz[j];
            }

        }
        grupe[i].galutinis = grupe[i].galutinis / 5;
        grupe[i].galutinis = grupe[i].galutinis * 0.4 + 0.6 * grupe[i].egz;
    }
    cout << "Pavarde\t\t" << "Vardas\t\t" << "Galutinis(Vid.)" << "Galutinis(Med.)\n";
    cout << "------------------------------------------------------------------------\n";
    for (int i = 0; i < n; i++) {
        cout << grupe[i].vardas << "\t\t" << grupe[i].pavarde << "\t\t" << grupe[i].galutinis << endl;
    }
}