
#include "strategija2.h"

bool compare(studentas2 first, studentas2 second) // palyginimas pagal galutini pazymi
{
    if (first.galutinis != second.galutinis) {
        return first.galutinis > second.galutinis;
    }
    else {
        return first.egz > second.egz;
    }
}

void greicio_analize2_List(string read_vardas, int m) {
    list <studentas2> grupe;
    cout << "Greicio analize naudojant 'List' :" << endl;
    std::ifstream myFile;
    myFile.open(read_vardas);
    int paz = 0;
    while (myFile) {
        if (!myFile.eof()) {
            studentas2 laik;
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
    list <studentas2> dvejetukininkai;
    studentas2 paskutinis = grupe.back();
    while (paskutinis.galutinis > 5) {
        dvejetukininkai.push_back(paskutinis);
        grupe.pop_back();
        paskutinis = grupe.back();
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start; // Skirtumas (s)
    std::cout << "Studentu skirstymas i dvi grupes uztruko: " << std::fixed << std::setprecision(6) << diff.count() << " s\n";
    grupe.clear();
    dvejetukininkai.clear();
}


void greicio_analize2_Vector(string read_vardas, int m, int studKiekis) {
    vector <studentas2> grupe;
    grupe.reserve(studKiekis + 5);
    cout << "Greicio analize naudojant 'Vector' :" << endl;
    std::ifstream myFile;
    myFile.open(read_vardas);
    int paz = 0;
    while (myFile) {
        if (!myFile.eof()) {
            studentas2 laik;
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
    vector <studentas2> dvejetukininkai;
    dvejetukininkai.reserve(studKiekis * 0.65);

    studentas2 paskutinis = grupe.back();
    while (paskutinis.galutinis > 5) {
        dvejetukininkai.push_back(paskutinis);
        grupe.pop_back();
        paskutinis = grupe.back();
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start; // Skirtumas (s)
    cout << "Studentu skirstymas i dvi grupes uztruko: " << std::fixed << std::setprecision(6) << diff.count() << " s\n";

    grupe.clear();
}