#include "myBib1.h"

bool compare(studentas first, studentas second) // palyginimas pagal galutini pazymi
{
    if (first.galutinis != second.galutinis) {
        return first.galutinis > second.galutinis;
    }
}

void failu_kurimas(string filename, int pazKiekis, int studKiekis) {
    int paz, egz;
    auto start = std::chrono::high_resolution_clock::now();
    std::ofstream myFile(filename);
    myFile.setf(std::ios_base::right);
    myFile.width(20);
    myFile << std::setw(15) << "Vardas" << std::setw(15) << "Pavarde" << std::setw(20);
    for (int i = 0; i < pazKiekis; i++) {
        myFile << "ND" << i + 1 << std::setw(10);
    }
    myFile << "Egzaminas\n";
    for (int j = 0; j < studKiekis; j++) {
        myFile << std::setw(15) << "Vardas" << std::to_string(j + 1) << std::setw(15) << "Pavarde" << std::to_string(j + 1) << std::setw(20);
        for (int i = 0; i < pazKiekis; i++) {
            paz = rand() % 10 + 1;
            myFile << paz << std::setw(10);
        }
        egz = rand() % 10 + 1;
        myFile << std::setw(10) << egz << "\n";
    }
    myFile.close();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start; // Skirtumas (s)
    std::cout << "Failo su " << studKiekis << " studentu duomenu sukurimas uztruko: " << diff.count() << "s\n";
}

void operacijos(string fileName, int pazKiekis, int studKiekis, string p) {
    auto start = std::chrono::high_resolution_clock::now();
    vector <studentas> grupe;
    grupe.reserve(studKiekis + 5);
    int paz = 0;
    string vardas, pavarde, pirmaEil;
    std::ifstream myFile;
    myFile.open(fileName);
    getline(myFile, pirmaEil);
    while (myFile) {
        if (!myFile.eof()) {
            studentas laik;
            laik.namuDarbai.reserve(pazKiekis + 3);
            myFile >> laik.vardas >> laik.pavarde;
            for (int i = 0; i < pazKiekis; i++) {
                myFile >> paz;
                laik.namuDarbai.push_back(paz);
            }
            myFile >> laik.egz;
            grupe.push_back(laik);
        }
        else {
            cout << "Negalima atidaryti failo!";
        }
    }
        myFile.close();
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end - start; // Skirtumas (s)
        cout << "Failo nuskaitymas uztruko: " << diff.count() << " s\n";

        // vidurkis
        for (auto& k : grupe) {
            double vid = 0;
            double suma = 0;
            for (auto& a : k.namuDarbai) {
                suma = suma + a;
            }
            vid = suma / pazKiekis;
            k.galutinis = 0.6 * k.egz + 0.4 * vid;
        }
        // mediana
        double mediana;
        for (auto& k : grupe) {
            std::sort(k.namuDarbai.begin(), k.namuDarbai.end());
            mediana = pazKiekis % 2 == 0 ?
                (k.namuDarbai.at(pazKiekis / 2 - 1) + k.namuDarbai.at(pazKiekis / 2)) / 2 : k.namuDarbai.at((pazKiekis / 2) + 0.5);
            k.med = 0.6 * k.egz + 0.4 * mediana;
        } 
        
        start = std::chrono::high_resolution_clock::now();
        std::sort(grupe.begin(), grupe.end(), compare);
        vector <studentas> moksliukai;
        moksliukai.reserve(studKiekis * 0.65);
        vector <studentas> dvejetukininkai;
        moksliukai.reserve(studKiekis * 0.65);

        for (auto& k : grupe) {
            if (k.galutinis > 5) {
                moksliukai.push_back(k);
            }
            else if (k.galutinis <= 5) {
                dvejetukininkai.push_back(k);
            }
        }
        end = std::chrono::high_resolution_clock::now();
        diff = end - start; // Skirtumas (s)
        cout << "Studentu skirstymas i dvi grupes uztruko: " << diff.count() << " s\n";

        // surusiuotu studentu isvedimas i du naujus failus.
        start = std::chrono::high_resolution_clock::now();
        string fname1 = "moksliukai" + p + ".txt";
        string fname2 = "dvejetukininkai" + p + ".txt";
        std::ofstream newFile1(fname1);
        std::ofstream newFile2(fname2);
        newFile1 << std::setw(15) << "Pavarde" << std::setw(15) << "Vardas" << std::setw(20) << "Galutinis(Vid.)" << std::setw(20) << "Galutinis(Med.)" << endl;
        newFile1 << "----------------------------------------------------------------------------------------------\n";
        newFile2 << std::setw(15) << "Pavarde" << std::setw(15) << "Vardas" << std::setw(20) << "Galutinis(Vid.)" << std::setw(20) << "Galutinis(Med.)" << endl;
        newFile2 << "----------------------------------------------------------------------------------------------\n";
        for (auto& k : moksliukai) {
            newFile1 << std::fixed << std::setprecision(2) << std::setw(15) << k.pavarde << std::setw(15) << k.vardas << std::setw(20) << k.galutinis << std::setw(20) << k.med << endl;
        }
        for (auto& k : dvejetukininkai) {
            newFile2 << std::fixed << std::setprecision(2) << std::setw(15) << k.pavarde << std::setw(15) << k.vardas << std::setw(20) << k.galutinis << std::setw(20) << k.med << endl;
        }    
        end = std::chrono::high_resolution_clock::now();
        diff = end - start; // Skirtumas (s)
        cout << studKiekis << " studentu duomenu surasymas i 2 failus uztruko :  " << diff.count() << " s\n";
        grupe.clear();
}
