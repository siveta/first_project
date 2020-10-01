#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
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
    float med;
    float galutinis = 0;
};

int main() {

    int m = 0;
    int a = 0;
    int paz;
    int choice = 0;
    vector <studentas> grupe;
    studentas laikina;
    vector <int> pazymiai;
    cout << "Sveiki !\n ";
    cout << "Pasirinkite operacija (irasykite skaiciu):\n1. Irasyti studentu duomenis i duomenu baze.\n2. Nuskaityti duomenis is failo\n";
    cin >> choice;
    if (choice == 1) {
        std::ofstream file("kursiokai.txt");
        cout << "Iveskite studentu skaiciu: ";
        cin >> a;
        grupe.reserve(a);
        file << "Vardas\t" << "Pavarde\t";
        cout << "Kiek pazymiu noresite ivesti?\n";
        cin >> m;
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
                cin >> paz;
                // patikrina ar ivestas pazymys yra 10-baleje sistemoje
                if (paz < 0 or paz > 10) {
                    cout << "Klaida! Iveskite pazymius dar karta:\n";
                    j = j - 1;
                }
                else {
                    file << paz << "\t";
                    laikina.galutinis = laikina.galutinis + (float)paz;
                    pazymiai.push_back(paz);
                }
                // mediana
                std::nth_element(pazymiai.begin(), pazymiai.begin() + pazymiai.size() / 2, pazymiai.end());
                laikina.med = pazymiai[pazymiai.size() / 2];
                pazymiai.clear();
            }
            laikina.galutinis = laikina.galutinis / m;
            laikina.galutinis = laikina.galutinis * 0.4 + 0.6 * laikina.egz;
            file << laikina.egz << endl;
            grupe.push_back(laikina);
        }
    }
    else if (choice == 2) {
        int lines = 0;
        string name;
        int nd;
        int word = 0;
        int size = 0;
        string words;
        string line;
        std::ifstream myfile;
        cout << "Iveskite failo, kuri norite nuskaityti, pavadinima:\n";
        cin >> name;
        myfile.open(name);
        if (myfile.is_open()) {
            cout << "failas atidarytas!" << endl;
            string l;
            getline(myfile, l); // pirma eilute
            cout << l << endl;
            string temp = l;
            
            while (myfile >> line) {
                getline(myfile, line);
                lines++; // studentu skaicius bus lygus eiluciu skaiciui - 1
            }
        }
        else {
            cout << "Negalima atidaryti failo!" <<endl;
        }

        cout << "zodziai : " << word << endl;
        cout << "eilutes : " << lines << endl;
        nd = (word / lines) - 3;
        cout << "nd : " << nd << endl;
        myfile.close();
    }

    cout << "Vardas\t\t" << "Pavarde\t\t" << "Galutinis(Vid.)" << "Galutinis(Med.)" << endl;
    cout << "------------------------------------------------------------------------\n";
    for (auto& tt : grupe)
        cout << tt.vardas << "\t\t" << tt.pavarde << "\t\t" << std::fixed << std::setprecision(2) << tt.galutinis << "\t\t" << tt.med << endl;
    grupe.clear();
}