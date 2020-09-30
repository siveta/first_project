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
    //int paz[1];
    float galutinis = 0;
};

int main() {
    int n = 0;
    //int m;
    int a;
    cout << "Sveiki!\n";
    cout << "Irasykite studentu skaiciu :\n";
    cin >> n; // studentu skaicius 
    studentas* grupe = new studentas[n]; // studentu masyvas is n nariu
    for (int i = 0; i < n; i++) {
        int m = 0;
        cout << "Iveskite eil.duomenis (vardas, pavarde, egz.paz.):\n";
        cin >> grupe[i].vardas >> grupe[i].pavarde >> grupe[i].egz; // ivedame varda pavarde ir egzamino rezultata 
        /*while (true) {
            cout << "Noredami baigti pazymiu ivedima parasykite '0'\n";
            cout << "Noredami testi pazymiu ivedima parasykite '1'\n";
            cin >> a;
            if (a = 1) {
                cout << "Iveskite " << m + 1 << "-aji pazymi:\n"; 
                int *paz = new int[m+1];
                cin >> paz[m];
                int* pazymiai = new int[m + 2];
                for (int j = 0; j < m + 1; j++) {                  
                    pazymiai[j] = paz[j];               
                    grupe[i].galutinis = grupe[i].galutinis + pazymiai[j];
                    delete[] paz;
                }
                m++;
            }
            else if (a=0) { 
                break; 
            }
            else {
                cout << "KLAIDA!" << endl;
                continue;
            }
        }*/
        while (true) {
            int* paz = new int[m+1];
            cout << "Noredami uzbaigti pazymiu ivedima, parasykite skaiciu '0'\n";
            cout << "Iveskite " << m + 1 << "-aji pazymi:" << endl;
            cin >> paz[m];
            if (paz[m] != 0) {
                //int* pazymiai = new int[m + 1];
                /*for (int j = 0; j < m; j++) {
                    //pazymiai[j] = paz[j];
                    cout << "Pazimys :\n";
                    cout << paz[j] << endl;*/
                grupe[i].galutinis = grupe[i].galutinis + paz[m];
                
                m++;
                delete[] paz;               

            }
            else {
                cout << "galutinis :" << endl;
                cout << grupe[i].galutinis << endl;
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