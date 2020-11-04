#include "speedTest.h"
#include "myBib.h"

void greicio_analize_List (std::string read_vardas, int m) {
    list <studentas> grupe;
    cout << "Greicio analize naudojant 'List' :" << endl;
    auto start = std::chrono::high_resolution_clock::now(); auto st = start;
    std::ifstream myFile(read_vardas);
    int paz = 0;
    while (myFile) {
        if (!myFile.eof()) {
            studentas laik;
            myFile >> laik.vardas >> laik.pavarde;
            for (int i = 0; i < m; i++) {
                myFile >> laik.pazymiai;
                paz = paz + laik.pazymiai;
            }

            myFile >> laik.egz;
            grupe.push_back(laik);
        }     
        else break;
    }
    myFile.close();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start; // Skirtumas (s)
    cout << "Failo nuskaitymas uztruko: " << diff.count() << " s\n";
   
    // vidurkis
    for (auto& k : grupe) {
        double vid = 0;     
        vid = paz / m;
        k.galutinis = 0.6 * k.egz + 0.4 * vid;
    }
    //double sk = 0.0;
    start = std::chrono::high_resolution_clock::now();
    grupe.sort(compare);
    list <studentas> moksliukai2;
    list <studentas> dvejetukininkai2;
    
    for (auto& k : grupe) {
        if (k.galutinis > 5) {
            moksliukai2.push_back(k);
        }
        else if (k.galutinis <= 5) {
            dvejetukininkai2.push_back(k);
        }
    }

    end = std::chrono::high_resolution_clock::now();
    diff = end - start; // Skirtumas (s)
    std::cout << "Studentu skirstymas i dvi grupes uztruko: " << std::fixed << std::setprecision(8) << diff.count() << " s\n";
    diff = std::chrono::high_resolution_clock::now() - st; // Skirtumas (s)
    cout << "Visas sugaistas laikas: " << diff.count() << " s\n\n";
}


void greicio_analize_Vector(std::string read_vardas, int m) {
    vector <studentas> grupe;
    cout << "Greicio analize naudojant 'Vector' :" << endl;
    auto start = std::chrono::high_resolution_clock::now(); auto st = start;
    std::ifstream myFile(read_vardas);
    int paz = 0;
    while (myFile) {
        if (!myFile.eof()) {
            studentas laik;
            myFile >> laik.vardas >> laik.pavarde;
            for (int i = 0; i < m; i++) {
                myFile >> laik.pazymiai;
                paz = paz + laik.pazymiai;
            }

            myFile >> laik.egz;
            grupe.push_back(laik);
        }
        else break;
    }
    myFile.close();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start; // Skirtumas (s)
    cout << "Failo nuskaitymas uztruko: " << diff.count() << " s\n";

    // vidurkis
    for (auto& k : grupe) {
        double vid = 0;
        vid = paz / m;
        k.galutinis = 0.6 * k.egz + 0.4 * vid;
    }
    //double sk = 0.0;
    start = std::chrono::high_resolution_clock::now();
    std::sort(grupe.begin(), grupe.end(), compare);
    vector <studentas> moksliukai;
    vector <studentas> dvejetukininkai;

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
    cout << "Studentu skirstymas i dvi grupes uztruko: " << std::fixed << std::setprecision(8) << diff.count() << " s\n";

    diff = std::chrono::high_resolution_clock::now() - st; // Skirtumas (s)
    cout << "Visas sugaistas laikas: " << diff.count() << " s\n\n";
}
