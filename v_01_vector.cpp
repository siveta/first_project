
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

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
    vector <studentas> grupe;
    studentas laikina;
    vector <int> pazymiai;
    cout << "Sveiki !\n ";
    cout << "Iveskite studentu skaiciu: ";
    cin >> a;
    grupe.reserve(a);
    for (int i = 0; i < a; i++) {
        int m = 0;
        cout << "Iveskite " << i + 1 << "-ojo studento varda: ";
        cin >> laikina.vardas;
        cout << "Iveskite " << i + 1 << "-ojo studento pavarde: ";
        cin >> laikina.pavarde;
        cout << "Iveskite " << i + 1 << "-ojo studento egzamino rezultata: ";
        cin >> laikina.egz;
        while (true) {
            cout << "Noredami baigti pazymiu ivedima parasykite '0'\n";
            cout << "Iveskite " << m + 1 << "-aji pazymi:\n";
            cin >> paz;        
            if (paz != 0) {
                pazymiai.reserve(m + 1);
                // patikrina ar ivestas pazymys yra  10-baleje sistemoje
                if (paz < 0 or paz > 10) {
                    cout << "Klaida! Iveskite pazymius dar karta:\n";
                    continue;                             
                }               
                else {
                    laikina.galutinis = laikina.galutinis + (float)paz;
                    pazymiai.push_back(paz);
                    m++;
                }
            }           
            else {
                break;
            }
        }
        // mediana
        std::nth_element(pazymiai.begin(), pazymiai.begin() + pazymiai.size() / 2, pazymiai.end());
        laikina.med = pazymiai[pazymiai.size() / 2];
    
    laikina.galutinis = laikina.galutinis / m;
    laikina.galutinis = laikina.galutinis * 0.4 + 0.6 * laikina.egz;
    grupe.push_back(laikina);
    
    }
    //spausdinimas
    cout << "Vardas" << std::setw(25) << "Pavarde" << std::setw(20) << "Galutinis(Vid.)\t" << "Galutinis(Med.)" << endl;
    cout << "------------------------------------------------------------------------\n";
    for (auto& tt : grupe) {
        cout << std::fixed << std::setprecision(2) << std::setw(10) << tt.vardas << std::setw(20) << tt.pavarde  << std::setw(20) << tt.galutinis << "\t\t" << tt.med << endl;
        
    }
    grupe.clear();
}
