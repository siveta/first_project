
#include "speedTest.h"

bool compare(studentas first, studentas second) // palyginimas pagal galutini pazymi
{
    if (first.galutinis != second.galutinis) {
        return first.galutinis > second.galutinis;
    }
}

void failu_kurimas(string filename, int pazKiekis, int studKiekis) {
    auto start = std::chrono::high_resolution_clock::now();
    std::ofstream myFile(filename);
    /*myFile << "Vardas" << std::setw(15) << "Pavarde" << std::setw(15);
    for (int i = 0; i < pazKiekis; i++) {
        myFile << "ND" << i + 1 << std::setw(10);
    }
    myFile << "Egzaminas\n";*/
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

void greicio_analize_List (std::string read_vardas, int m) {
    list <studentas> grupe;
    //string pirmaEil;
    cout << "Greicio analize naudojant 'List' :" << endl;
    auto start = std::chrono::high_resolution_clock::now(); auto st = start;
    std::ifstream myFile;
    myFile.open(read_vardas);
    //getline(myFile, pirmaEil);
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
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start; // Skirtumas (s)
    cout << "Failo nuskaitymas uztruko: " << diff.count() << " s\n";
   
    // vidurkis
    for (auto& k : grupe) {
        double vid = 0;
        vid = k.pazymiai / m;
        k.galutinis = 0.6 * k.egz + 0.4 * vid;
    }
    start = std::chrono::high_resolution_clock::now();
    grupe.sort(compare);
    list <studentas> dvejetukininkai;  
    studentas paskutinis = grupe.back();
    while (paskutinis.galutinis > 5) {
        dvejetukininkai.push_back(paskutinis);
        grupe.pop_back();
        paskutinis = grupe.back();
    }

    end = std::chrono::high_resolution_clock::now();
    diff = end - start; // Skirtumas (s)
    std::cout << "Studentu skirstymas i dvi grupes uztruko: " << std::fixed << std::setprecision(8) << diff.count() << " s\n";
    diff = std::chrono::high_resolution_clock::now() - st; // Skirtumas (s)
    cout << "Visas sugaistas laikas: " << diff.count() << " s\n\n";
    grupe.clear();
    dvejetukininkai.clear();
}


void greicio_analize_Vector(std::string read_vardas, int m, int studKiekis) {
    vector <studentas> grupe;
    grupe.reserve(studKiekis + 5);
    cout << "Greicio analize naudojant 'Vector' :" << endl;
    auto start = std::chrono::high_resolution_clock::now(); auto st = start;
    std::ifstream myFile;
    myFile.open(read_vardas);
    int paz = 0;
    //string pirmaEil;
    //getline(myFile, pirmaEil);
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
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start; // Skirtumas (s)
    cout << "Failo nuskaitymas uztruko: " << diff.count() << " s\n";

    // vidurkis
    for (auto& k : grupe) {
        double vid = 0;
        vid = k.pazymiai / m;
        k.galutinis = 0.6 * k.egz + 0.4 * vid;
    }
    start = std::chrono::high_resolution_clock::now();
    std::sort(grupe.begin(), grupe.end(), compare);
    vector <studentas> dvejetukininkai;
    dvejetukininkai.reserve(studKiekis * 0.65);

    studentas paskutinis = grupe.back();
    while (paskutinis.galutinis > 5) {
        dvejetukininkai.push_back(paskutinis);
        grupe.pop_back();
        paskutinis = grupe.back();
    }
    end = std::chrono::high_resolution_clock::now();
    diff = end - start; // Skirtumas (s)
    cout << "Studentu skirstymas i dvi grupes uztruko: " << std::fixed << std::setprecision(8) << diff.count() << " s\n";

    diff = std::chrono::high_resolution_clock::now() - st; // Skirtumas (s)
    cout << "Visas sugaistas laikas: " << diff.count() << " s\n\n";
    
    grupe.clear();
}