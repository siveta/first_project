
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
    int paz[15];
    float med;
    float galutinis = 0;
};

int main() {
    int m = 0;
    int a = 0;
    vector <studentas> grupe;
    studentas laikina;
    vector <int> pazymiai;
    cout << "Sveiki !\n ";
    cout << "Iveskite studentu skaiciu: ";
    cin >> a;
    grupe.reserve(a);
    cout << "Kiek pazymiu noresite ivesti (maksimalus galimas ivedimas - 15 pazymiu)?\n";

    // patikrina ar norima ivesti ne maziau 0 ir ne daugiau  kaip 15 pazymiu
    while (true) {
        cin >> m;
        if (m < 1 or 15 < m) {  
            cout << "KLAIDA! negalimas veiksmas\n";
        }
        else {break;}
    }
    for (int i = 0; i < a; i++) {
        cout << "Iveskite " << i + 1 << "-ojo studento varda: ";
        cin >> laikina.vardas;
        cout << "Iveskite " << i + 1 << "-ojo studento pavarde: ";
        cin >> laikina.pavarde;
        cout << "Iveskite " << i + 1 << "-ojo studento egzamino rezultata: ";
        cin >> laikina.egz;
        for (int j = 0; j < m; j++) {
            cout << "Iveskite " << j + 1 << "-aji pazymi :\n";
            cin >> laikina.paz[j];
            if (laikina.paz[j] < 0 or laikina.paz[j] > 10) {
                cout << "Klaida! Iveskite pazymius dar karta:\n";
                j = j - 1;
            }
            else {
                laikina.galutinis = laikina.galutinis + (float)laikina.paz[j];
                pazymiai.push_back(laikina.paz[j]);
            }
           
            std::nth_element(pazymiai.begin(), pazymiai.begin() + pazymiai.size() / 2, pazymiai.end());
            laikina.med = pazymiai[pazymiai.size() / 2];
        }
        laikina.galutinis = laikina.galutinis / m;
        laikina.galutinis = laikina.galutinis * 0.4 + 0.6 * laikina.egz;

        grupe.push_back(laikina);
    }
    cout << "Pavarde\t\t" << "Vardas\t\t" << "Galutinis(Vid.)\t" << "Galutinis(Med.)" <<endl;
    cout << "------------------------------------------------------------------------\n";
    for (auto& tt : grupe)
        cout << tt.vardas << "\t\t" << tt.pavarde << "\t\t" << std::fixed << std::setprecision(2) << tt.galutinis << "\t\t" << tt.med << endl;
    grupe.clear();
}
