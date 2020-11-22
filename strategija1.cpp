
#include "strategija1.h"

bool compare(studentas first, studentas second) // palyginimas pagal galutini pazymi
{
    if (first.galutinis != second.galutinis) {
        return first.galutinis > second.galutinis;
    }
    else {
        return first.egz > second.egz;
    }
}

void failu_kurimas(string filename, int pazKiekis, int studKiekis) {
    auto start = std::chrono::high_resolution_clock::now();
    std::ofstream myFile(filename);
    for (int j = 0; j < studKiekis; j++) {
        myFile << "Vardas" << std::to_string(j + 1) << std::setw(15) << "Pavarde" << std::to_string(j + 1) << std::setw(15);
        for (int i = 0; i < pazKiekis; i++) {
            int paz = rand() % 10 + 1;
            myFile << paz << std::setw(10);
        }
        int egz = rand() % 10 + 1;
        myFile << egz << "\n";
    }
    myFile.close();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start; // Skirtumas (s)
    std::cout << "Failo su " << studKiekis << " studentu duomenu sukurimas uztruko: " << diff.count() << "s\n";
}

void greicio_analize_List(string read_vardas, int m) {
    list <studentas> grupe;
    cout << "Greicio analize naudojant 'List' :" << endl;
    std::ifstream myFile;
    myFile.open(read_vardas);
    int paz = 0;
    while (myFile) {
        if (!myFile.eof()) {
            studentas laik;
            myFile >> laik.vardas >> laik.pavarde;

            for (int i = 0; i < m; i++) {
                myFile >> paz;
                laik.pazymiai += paz;
            }
            myFile >> laik.egz;
            grupe.push_back(laik);
        }
        else {
            cout << "Negalima atidaryti failo!";
        }
    }
    myFile.close();
    // vidurkis
    for (auto& k : grupe) {
        double vid = 0;
        vid = k.pazymiai / m;
        k.galutinis = 0.6 * k.egz + 0.4 * vid;
    }
    auto start = std::chrono::high_resolution_clock::now();
    grupe.sort(compare);
    list <studentas> dvejetukininkai;
    list <studentas> moksliukai;

    for (auto& k : grupe) {
        if (k.galutinis > 5) {
            moksliukai.push_back(k);
        }
        else if (k.galutinis <= 5) {
            dvejetukininkai.push_back(k);
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start; // Skirtumas (s)
    cout << "Studentu skirstymas i dvi grupes uztruko: " << std::fixed << std::setprecision(6) << diff.count() << " s\n";
    grupe.clear();
    dvejetukininkai.clear();
    moksliukai.clear();
}

void greicio_analize_Vector(string read_vardas, int m, int studKiekis) {
    vector <studentas> grupe;
    grupe.reserve(studKiekis + 5);
    cout << "Greicio analize naudojant 'Vector' :" << endl;
    std::ifstream myFile;
    myFile.open(read_vardas);
    int paz = 0;
    while (myFile) {
        if (!myFile.eof()) {
            studentas laik;
            myFile >> laik.vardas >> laik.pavarde;
            for (int i = 0; i < m; i++) {
                myFile >> paz;
                laik.pazymiai += paz;
            }
            myFile >> laik.egz;
            grupe.push_back(laik);
        }
        else {
            cout << "Negalima atidaryti failo!";
        }
    }
    myFile.close();

    // vidurkis
    for (auto& k : grupe) {
        double vid = 0;
        vid = k.pazymiai / m;
        k.galutinis = 0.6 * k.egz + 0.4 * vid;
    }
    auto start = std::chrono::high_resolution_clock::now();
    std::sort(grupe.begin(), grupe.end(), compare);
    vector <studentas> dvejetukininkai;
    vector <studentas> moksliukai;
    dvejetukininkai.reserve(studKiekis * 0.65);
    moksliukai.reserve(studKiekis * 0.65);

    for (auto& k : grupe) {
        if (k.galutinis > 5) {
            moksliukai.push_back(k);
        }
        else if (k.galutinis <= 5) {
            dvejetukininkai.push_back(k);
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start; // Skirtumas (s)
    cout << "Studentu skirstymas i dvi grupes uztruko: " << std::fixed << std::setprecision(6) << diff.count() << " s\n";

    grupe.clear();
    dvejetukininkai.clear();
    moksliukai.clear();
}