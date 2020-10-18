
#include "compare.h"
#include "greicio_analize.h"

int main() {
    int paz;
    int egz;
    int m;
    cout << "Sveiki !\n ";
    cout << "Kiek pazymiu noresite sugeneruoti savo failuose?\n";
    cin >> m;
    
    // pirmas failas su 1000 studentu duomenimis
    std::ofstream file1("studentai1.txt");
    file1 << "Vardas" << std::setw(15) << "Pavarde" << std::setw(15);
    for (int i = 0; i < m; i++) {
        file1 << "ND" << i + 1 << std::setw(10);
    }
    file1 << "Egzaminas\n";
    for (int j = 0; j < 1000; j++) {
        file1 << "Vardas" << j + 1 << std::setw(15) << "Pavarde" << j + 1 << std::setw(15);
        for (int i = 0; i < m; i++) {
            paz = rand() % 10 + 1;
            file1 << paz << std::setw(10);
        }
        egz = rand() % 10 + 1;
        file1 << egz << "\n";
    }
    // antras failas su 10000 studentu duomenimis
    std::ofstream file2("studentai2.txt");
    file2 << "Vardas\t\t" << "Pavarde\t";
    for (int i = 0; i < m; i++) {
        file2 << "ND" << i + 1 << "\t";
    }
    file2 << "Egzaminas\n";
    for (int j = 0; j < 10000; j++) {
        file2 << "Vardas" << j + 1 << "\t\t" << "Pavarde" << j + 1 << "\t";
        for (int i = 0; i < m; i++) {
            paz = rand() % 10 + 1;
            file2 << paz << "\t";
        }
        egz = rand() % 10 + 1;
        file2 << egz << "\n";
    }

    // trecias failas su 100000 studentu duomenimis
    std::ofstream file3("studentai3.txt");
    file3 << "Vardas\t" << "Pavarde\t";
    for (int i = 0; i < m; i++) {
        file3 << "ND" << i + 1 << "\t";
    }
    file3 << "Egzaminas\n";
    for (int j = 0; j < 100000; j++) {
        file3 << "Vardas" << j + 1 << "\t" << "Pavarde" << j + 1 << "\t";
        for (int i = 0; i < m; i++) {
            paz = rand() % 10 + 1;
            file3 << paz << "\t";
        }
        egz = rand() % 10 + 1;
        file3 << egz << "\n";
    }

    // ketvirtas failas su 1000000 studentu duomenimis
    std::ofstream file4("studentai4.txt");
    file4 << "Vardas\t" << "Pavarde\t";
    for (int i = 0; i < m; i++) {
        file4 << "ND" << i + 1 << "\t";
    }
    file4 << "Egzaminas\n";
    for (int j = 0; j < 1000000; j++) {
        file4 << "Vardas" << j + 1 << "\t" << "Pavarde" << j + 1 << "\t";
        for (int i = 0; i < m; i++) {
            paz = rand() % 10 + 1;
            file4 << paz << "\t";
        }
        egz = rand() % 10 + 1;
        file4 << egz << "\n";
    }
    
    // penktas failas su 1000000 studentu duomenimis
    std::ofstream file5("studentai5.txt");
    file5 << "Vardas\t" << "Pavarde\t";
    for (int i = 0; i < m; i++) {
        file5 << "ND" << i + 1 << "\t";
    }
    file5 << "Egzaminas\n";
    for (int j = 0; j < 1000000; j++) {
        file5 << "Vardas" << j + 1 << "\t" << "Pavarde" << j + 1 << "\t";
        for (int i = 0; i < m; i++) {
            paz = rand() % 10 + 1;
            file5 << paz << "\t";
        }
        egz = rand() % 10 + 1;
        file5 << egz << "\n";
    }
    int a;
    cout << "Kuri faila norite surusiuoti ?\n";
    cout << ("1.studentai1.txt\n2.studentai2.txt\n3.studentai3.txt\n4.studentai4.txt\n5.studentai5.txt\nIrasykite numeri:")<<endl;
    cin >> a;
    vector <studentas> grupe;
    string vardas, pavarde, pirmaEil;
    std::ifstream myFile;

    if (a == 1) myFile.open("studentai1.txt");
    if (a == 2) myFile.open("studentai2.txt");
    if (a == 3) myFile.open("studentai3.txt");
    if (a == 4) myFile.open("studentai4.txt");
    if (a == 5) myFile.open("studentai5.txt");

    if (myFile.is_open())
    {
        getline(myFile, pirmaEil);
       
        while (!myFile.eof()) { //skaito iki failo pabaigos
            studentas laik;
            laik.namuDarbai.reserve(m);
            
            myFile >> laik.vardas >> laik.pavarde;
            for (int i = 0; i < m; i++) {
                myFile >> paz;
                laik.namuDarbai.push_back(paz);
            }           

            myFile >> laik.egz;
            grupe.push_back(laik);
        }
        myFile.close();
    }
    else {
        cout << "Negalima atidaryti failo!";
    }

    std::sort(grupe.begin(), grupe.end(), compare);

    // vidurkis
    for (auto& k : grupe) {
        double vid = 0;
        double suma = 0;
        for (auto& a : k.namuDarbai) {
            suma = suma + a;
        }
        vid = suma / m;
        k.galutinis = 0.6 * k.egz + 0.4 * vid;
    }

    // mediana
    double mediana;
    for (auto& k : grupe) {
        std::sort(k.namuDarbai.begin(), k.namuDarbai.end());
        mediana = m % 2 == 0 ?
            (k.namuDarbai.at(m / 2 - 1) + k.namuDarbai.at(m / 2)) / 2 : k.namuDarbai.at((m / 2) + 0.5);
        k.med = 0.6 * k.egz + 0.4 * mediana;
    }
    
    std::ofstream newFile ("moksliukai.txt");
    std::ofstream newFile2("dvejetukininkai.txt");
    // rezultatai
    newFile << std::setw(15) << "Pavarde" << std::setw(15) << "Vardas" << std::setw(20) << "Galutinis(Vid.)" << std::setw(20) << "Galutinis(Med.)" << endl;
    newFile << "----------------------------------------------------------------------------------------------\n";
    newFile2 << std::setw(15) << "Pavarde" << std::setw(15) << "Vardas" << std::setw(20) << "Galutinis(Vid.)" << std::setw(20) << "Galutinis(Med.)" << endl;
    newFile2 << "----------------------------------------------------------------------------------------------\n";
    for (auto& k : grupe) {
        if (k.galutinis > 5) {
            newFile << std::fixed << std::setprecision(2) << std::setw(15) << k.pavarde << std::setw(15) << k.vardas << std::setw(20) << k.galutinis << std::setw(20) << k.med << endl;
        }
        else if (k.galutinis <= 5) {
            newFile2 << std::fixed << std::setprecision(2) << std::setw(15) << k.pavarde << std::setw(15) << k.vardas << std::setw(20) << k.galutinis << std::setw(20) << k.med << endl;
        }

    }
    cout << "Failo 'sudentai1.txt' nuskaitymas :\n(failas is 1000 eiluciu)" << endl;
    std::cout << "Iprastas variantas, eilutes:\n";
    el_po_el("studentai1.txt", "studentai_copy.txt");

    cout << "Failo 'sudentai2.txt' nuskaitymas :\n(failas is 10000 eiluciu)" << endl;
    std::cout << "Iprastas variantas, eilutes:\n";
    el_po_el("studentai2.txt", "studentai2_copy.txt");

    cout << "Failo 'sudentai3.txt' nuskaitymas :\n(failas is 100000 eiluciu)" << endl;
    std::cout << "Iprastas variantas, eilutes:\n";
    el_po_el("studentai3.txt", "studentai3_copy.txt");

    cout << "Failo 'sudentai4.txt' nuskaitymas :\n(failas is 1000000 eiluciu)" << endl;
    std::cout << "Iprastas variantas, eilutes:\n";
    el_po_el("studentai4.txt", "studentai4_copy.txt");

    cout << "Failo 'sudentai5.txt' nuskaitymas :\n(failas is 10000000 eiluciu)" << endl;
    std::cout << "Iprastas variantas, eilutes:\n";
    el_po_el("studentai5.txt", "studentai5_copy.txt");

    grupe.clear();
}
     
        

            
            
            
