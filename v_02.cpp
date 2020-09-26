#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdio.h> 
#include <conio.h>
#include <iomanip>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;

struct studentas {
    string vardas;
    string pavarde;
    int egz;
    int paz[20];
    float med;
    float galutinis = 0;
};

int main() {
    int m = 0;
    int a = 0;
    int choice;
    vector <studentas> grupe;
    studentas laikina;
    vector <int> pazymiai;
    cout << "Sveiki !\n ";
    cout << "Pasirinkite operacija :\n1. Irasyti studentu duomenis i duomenu baze.\n2. Nuskaityti duomenis is failo\n";
    cin >> choice;
    if (choice == 1) {
        std::ofstream file("kursiokai.txt");
        cout << "Iveskite studentu skaiciu: ";
        cin >> a;
        grupe.reserve(a);
        file << "Vardas\t" << "Pavarde\t";
        cout << "Kiek pazymiu noresite ivesti (maksimalus galimas ivedimas - 15 pazymiu)?\n";
        // patikrina ar norima ivesti ne maziau 0 ir ne daugiau  kaip 15 pazymiu
        while (true) {
            cin >> m;
            if (m < 1 or 20 < m) {
                cout << "KLAIDA! negalimas veiksmas\n";
            }
            else { break; }
        }
        pazymiai.reserve(m);
        for (int i = 0; i < m; i++) {
            file << "ND" << i + 1 << "\t";
        }
        file << "Egzaminas\n";
        for (int i = 0; i < a; i++) {
            cout << "Iveskite " << i + 1 << "-ojo studento varda: ";
            cin >> laikina.vardas;
            file << laikina.vardas << "\t";
            cout << "Iveskite " << i + 1 << "-ojo studento pavarde: ";
            cin >> laikina.pavarde;
            file << laikina.pavarde << "\t";
            cout << "Iveskite " << i + 1 << "-ojo studento egzamino rezultata: ";
            cin >> laikina.egz;
            
            for (int j = 0; j < m; j++) {
                cout << "Iveskite " << j + 1 << "-aji pazymi :\n";
                cin >> laikina.paz[j];
                // patikrina ar ivestas pazymys yra  10-baleje sistemoje
                if (laikina.paz[j] < 0 or laikina.paz[j] > 10) {
                    cout << "Klaida! Iveskite pazymius dar karta:\n";
                    j = j - 1;
                }
                else {
                    file << laikina.paz[j] << "\t";
                    laikina.galutinis = laikina.galutinis + (float)laikina.paz[j];
                    pazymiai.push_back(laikina.paz[j]);
                }
                // mediana
                std::nth_element(pazymiai.begin(), pazymiai.begin() + pazymiai.size() / 2, pazymiai.end());
                laikina.med = pazymiai[pazymiai.size() / 2];
            }

            laikina.galutinis = laikina.galutinis / m;
            laikina.galutinis = laikina.galutinis * 0.4 + 0.6 * laikina.egz;
            file << laikina.egz << endl;
            grupe.push_back(laikina);
        }
    }
    else if (choice == 2) {
        string name;
        cout << "Iveskite failo, kuri norite nuskaityti, pavadinima:\n";
        cin >> name;
        std::ifstream file2(name);

    
    } 

    cout << "Vardas\t\t" << "Pavarde\t\t" << "Galutinis(Vid.)" << "Galutinis(Med.)" << endl;
    cout << "------------------------------------------------------------------------\n";
    for (auto& tt : grupe)
        cout << tt.vardas << "\t\t" << tt.pavarde << "\t\t" << std::fixed << std::setprecision(2) << tt.galutinis << "\t\t" << tt.med << endl;
    grupe.clear();
}
