#include "myBib1.h"

int main() {
    int m;
    cout << "Sveiki !\n ";
    cout << "Kiek pazymiu noresite sugeneruoti savo failuose?\n";
    cin >> m;

    cout << "----------------------------------------------------------------------" << endl;
    // pirmasis failas, 1000 duomenu
    failu_kurimas("studentai1.txt", m, 1000);
    operacijos("studentai1.txt", m, 1000, "1");

    cout << "----------------------------------------------------------------------" << endl;
    // antrasis failas, 10000 duomenu
    failu_kurimas("studentai2.txt", m, 10000);
    operacijos("studentai2.txt", m, 10000, "2");

    cout << "----------------------------------------------------------------------" << endl;
    // treciasis failas, 100000 duomenu
    failu_kurimas("studentai3.txt", m, 100000);
    operacijos("studentai3.txt", m, 100000, "3");

    cout << "----------------------------------------------------------------------" << endl;
    // ketvirtasis failas, 1000000 duomenu
    failu_kurimas("studentai4.txt", m, 1000000);
    operacijos("studentai4.txt", m, 1000000, "4");

    cout << "----------------------------------------------------------------------" << endl;
    // pektasis failas, 10000000 duomenu
    failu_kurimas("studentai5.txt", m, 10000000);
    operacijos("studentai5.txt", m, 10000000, "5");
}

