
#include "strategija1.h"
#include "strategija2.h"

int main() {
    int m;
    cout << "Sveiki !\n ";
    cout << "Kiek pazymiu noresite sugeneruoti savo failuose?\n";
    cin >> m;

    /*failu_kurimas("studentai1.txt", m, 1000);
    failu_kurimas("studentai2.txt", m, 10000);
    failu_kurimas("studentai3.txt", m, 100000);
    failu_kurimas("studentai4.txt", m, 1000000);*/

    cout << "----------------------------------------------------------------------" << endl;
    cout << "Failo 'studentai1.txt' nuskaitymas :\t(failas is 1000 eiluciu)" << endl;
    greicio_analize_List("studentai1.txt", m);
    greicio_analize_Vector("studentai1.txt", m, 1000);
    greicio_analize2_List("studentai1.txt", m);
    greicio_analize2_Vector("studentai1.txt", m, 1000);
    cout << "----------------------------------------------------------------------" << endl;

    cout << "Failo 'studentai2.txt' nuskaitymas :\t(failas is 10000 eiluciu)" << endl;
    greicio_analize_List("studentai2.txt", m);
    greicio_analize_Vector("studentai2.txt", m, 10000);
    greicio_analize2_List("studentai2.txt", m);
    greicio_analize2_Vector("studentai2.txt", m, 10000);
    cout << "----------------------------------------------------------------------" << endl;

    cout << "Failo 'studentai3.txt' nuskaitymas :\t(failas is 100000 eiluciu)" << endl;
    greicio_analize_List("studentai3.txt", m);
    greicio_analize_Vector("studentai3.txt", m, 100000);
    greicio_analize2_List("studentai3.txt", m);
    greicio_analize2_Vector("studentai3.txt", m, 100000);
    cout << "----------------------------------------------------------------------" << endl;

    cout << "Failo 'studentai4.txt' nuskaitymas :\t(failas is 1000000 eiluciu)" << endl;
    greicio_analize_List("studentai4.txt", m);
    greicio_analize_Vector("studentai4.txt", m, 1000000);
    greicio_analize2_List("studentai4.txt", m);
    greicio_analize2_Vector("studentai4.txt", m, 1000000);
    cout << "----------------------------------------------------------------------" << endl;

}