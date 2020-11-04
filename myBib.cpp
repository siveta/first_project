
#include "myBib.h"
#include "speedTest.h"

bool compare(studentas first, studentas second) // palyginimas pagal pavarde
{
    if (first.pavarde != second.pavarde) {
        return first.vardas < second.pavarde;
    }
    else {
        return (first.vardas < second.vardas);
    }
}

void failu_kurimas(string filename, int pazKiekis, int studKiekis) {
    auto start = std::chrono::high_resolution_clock::now();
    std::ofstream myFile(filename);
    myFile << "Vardas" << std::setw(15) << "Pavarde" << std::setw(15);
    for (int i = 0; i < pazKiekis; i++) {
        myFile << "ND" << i + 1 << std::setw(10);
    }
    myFile << "Egzaminas\n";
    for (int j = 0; j < studKiekis; j++) {
        myFile << "Vardas" << j + 1 << std::setw(15) << "Pavarde" << j + 1 << std::setw(15);
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