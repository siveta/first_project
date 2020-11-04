
#include "speedTest.h"
#include "myBib.h"

int main() {
    int m;
    cout << "Sveiki !\n ";
    cout << "Kiek pazymiu noresite sugeneruoti savo failuose?\n";
    cin >> m;

    failu_kurimas("studentai1.txt", m, 1000);
    failu_kurimas("studentai2.txt", m, 10000);
    failu_kurimas("studentai3.txt", m, 100000);
    failu_kurimas("studentai4.txt", m, 1000000);
    failu_kurimas("studentai5.txt", m, 10000000);
    
    cout << "----------------------------------------------------------------------" << endl;
    cout << "Failo 'studentai1.txt' nuskaitymas :\n(failas is 1000 eiluciu)" << endl;
    greicio_analize_List("studentai1.txt", m);
    greicio_analize_Vector("studentai1.txt", m);
    cout << "----------------------------------------------------------------------" << endl;

    cout << "Failo 'studentai2.txt' nuskaitymas :\n(failas is 10000 eiluciu)" << endl;
    greicio_analize_List("studentai2.txt", m);
    greicio_analize_Vector("studentai2.txt", m);
    cout << "----------------------------------------------------------------------" << endl;

    cout << "Failo 'studentai3.txt' nuskaitymas :\n(failas is 100000 eiluciu)" << endl;
    greicio_analize_List("studentai3.txt", m);
    greicio_analize_Vector("studentai3.txt", m);
    cout << "----------------------------------------------------------------------" << endl;

    cout << "Failo 'studentai4.txt' nuskaitymas :\n(failas is 1000000 eiluciu)" << endl;
    greicio_analize_List("studentai4.txt", m);
    greicio_analize_Vector("studentai4.txt", m);
    cout << "----------------------------------------------------------------------" << endl;

    cout << "Failo 'studentai5.txt' nuskaitymas :\n(failas is 10000000 eiluciu)" << endl;
    greicio_analize_List("studentai5.txt", m);
    greicio_analize_Vector("studentai5.txt", m);
    cout << "----------------------------------------------------------------------" << endl;
    
}







