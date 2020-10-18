
#include "myBib.h"

int main() {
    vector <studentas> grupe;
    studentas laikina;
    int choice = 0;
    cout << "Sveiki !\n ";
    cout << "Pasirinkite operacija (irasykite skaiciu):\n1. Irasyti studentu duomenis i duomenu baze.\n2. Nuskaityti duomenis is failo\n";
    cin >> choice;
    if (choice == 1) {
        int m = 0; // namu darbu kiekis
        int a = 0; // studentu skaicius
        int paz;
        vector <int> pazymiai;
        std::ofstream file("kursiokai.txt");
        cout << "Iveskite studentu skaiciu: ";
        cin >> a;
        if (a < 1) {
            while (true) {
                cout << "KLAIDA! Reikia ivesti bent 1 studenta!" << endl;
                cin >> a;
                if (a < 1) continue;
                else break;
            }
        }
        grupe.reserve(a);
        file << "Vardas\t" << "Pavarde\t";
        cout << "Kiek pazymiu noresite ivesti?\n";
        cin >> m;
        if (m < 1) {
            while (true) {
                cout << "KLAIDA! Reikia ivesti bent 1 pazymi!" << endl;
                cin >> m;
                if (m < 1) continue;
                else break;
            }
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
            cout << "Ar norite generuoti pazymius atsitiktinai ?\n1. Taip\n2.Ne\n(iveskite skaiciu)" << endl;
            int x;
            cin >> x;
            while (!cin >> (x != 1 && x != 2)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "\nIveskite skaiciu!" << std::endl;
            }

            if (x == 2) {
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
                }
            }
            else if (x == 1) {
                for (int j = 0; j < m; j++) {
                    paz = rand() % 10 + 1;
                    file << paz << "\t";
                    laikina.galutinis = laikina.galutinis + (float)paz;
                    pazymiai.push_back(paz);
                }
                laikina.egz = rand() % 10 + 1;
            }
            // mediana
            std::sort(pazymiai.begin(), pazymiai.end());
            laikina.med = m / 2 == 0 ?
                (pazymiai.at(m / 2 - 1) + pazymiai.at(m / 2)) / 2 : pazymiai.at((m / 2) + 0.5);
            laikina.med = 0.6 * laikina.egz + 0.4 * laikina.med;
            pazymiai.clear();

            // vidurkis
            laikina.galutinis = laikina.galutinis / m;
            //cout << "vidurkis " << laikina.galutinis;
            laikina.galutinis = laikina.galutinis * 0.4 + 0.6 * laikina.egz;
            //cout << "galutinis " << laikina.galutinis;
            file << laikina.egz << endl;
            grupe.push_back(laikina);
        }
        // rezultatai
        cout << std::setw(15) << "Pavarde" << std::setw(15) << "Vardas" << std::setw(20) << "Galutinis(Vid.)" << std::setw(20) << "Galutinis(Med.)" << endl;
        cout << "----------------------------------------------------------------------------------------------\n";
        for (auto& k : grupe) {
            cout << std::fixed << std::setprecision(2) << std::setw(15) << k.pavarde << std::setw(15) << k.vardas << std::setw(20) << k.galutinis << std::setw(20) << k.med << endl;
        }
    }
    else if (choice == 2) {

        std::ifstream myFile;
        string vardai;
        string pavardes;
        string pazymiai;
        string egzaminas;
        vector <string> pirmaEil;
        int nd = 0;
        grupe.reserve(1);
        pirmaEil.reserve(1);
        string file;
        cout << "Irasykite failo pavadinima :\n";
        cin >> file;
        myFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        try {
            myFile.open(file);
        }
        catch (std::ifstream::failure e) {
            std::cerr << "Negalima atidaryti failo arba failas neegzistuoja!\n";
        }
        if (myFile.is_open())
        {
            myFile >> vardai >> pavardes >> pazymiai;
            while (pazymiai != "Egz.")
            {
                pirmaEil.push_back(pazymiai);
                myFile >> pazymiai;
            }
            egzaminas = pazymiai;

            nd = pirmaEil.size(); // suzinosime kiek yra namu darbu pazymiu
            laikina.namuDarbai.reserve(nd);

            while (!myFile.eof()) { //skaito iki failo pabaigos
                studentas laik;
                myFile >> laik.vardas >> laik.pavarde;

                double paz;

                for (int i = 0; i < nd; i++) {
                    myFile >> paz;
                    laik.namuDarbai.push_back(paz);
                }
                myFile >> laik.egz;
                grupe.push_back(laik);
            }
            myFile.close();


            sort(grupe.begin(), grupe.end(), compare);

            // vidurkis
            for (auto& k : grupe) {
                double vid = 0;
                double suma = 0;
                for (auto& a : k.namuDarbai) {
                    suma = suma + a;
                }
                vid = suma / nd;
                k.galutinis = 0.6 * k.egz + 0.4 * vid;
            }

            // mediana
            double mediana;
            for (auto& k : grupe) {
                std::sort(k.namuDarbai.begin(), k.namuDarbai.end());
                mediana = nd % 2 == 0 ?
                    (k.namuDarbai.at(nd / 2 - 1) + k.namuDarbai.at(nd / 2)) / 2 : k.namuDarbai.at((nd / 2) + 0.5);
                k.med = 0.6 * k.egz + 0.4 * mediana;
            }
            // rezultatai
            cout << std::setw(15) << "Pavarde" << std::setw(15) << "Vardas" << std::setw(20) << "Galutinis(Vid.)" << std::setw(20) << "Galutinis(Med.)" << endl;
            cout << "----------------------------------------------------------------------------------------------\n";
            for (auto& k : grupe) {
                cout << std::fixed << std::setprecision(2) << std::setw(15) << k.pavarde << std::setw(15) << k.vardas << std::setw(20) << k.galutinis << std::setw(20) << k.med << endl;
            }
            grupe.clear();
        }
    }
}
