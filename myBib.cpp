
#include "myBib.h"

bool compare(studentas first, studentas second) // palyginimas pagal pavarde
{
    if (first.pavarde != second.pavarde) {
        return first.vardas < second.pavarde;
    }
    else {
        return (first.vardas < second.vardas);
    }
}
