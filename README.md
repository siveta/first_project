# Objektinis programavimas C++

## v_05
Kažkodėl su didžiausiu duomenų failu neatlieka paskutinės funkcijos-greičio analizės su vektoriais (jei leidžiama per x86 versiją). Kai leidau per x64 versiją- programa veikė gerai, bet šiek tiek pasirodė nelogiškai maži skaičiai, dar bandysiu aiškintis kame problema.
**Programos dalys :**
* [v_05.cpp](https://github.com/siveta/first_project/blob/v_05/v_05.cpp)
* [speedTest.h](https://github.com/siveta/first_project/blob/v_05/speedTest.h)
* [speedTest.cpp](https://github.com/siveta/first_project/blob/v_05/speedTest.cpp)

## kompiuterio parametrai
* Intel Core i5-8250U
* 8 GB RAM 

## Rasta problema !
Pasirodo, per savo žioplumą buvau parašiusi, kad funkcija 'greicio_analize_vector' visur atlikinėtų darbą tik su vienu tuo pačiu failu, t.y. failu iš 1000 studentų.

## Apie :
Sugeneruojami failai, kuriuose kiekvienas studentas atsitiktinai gauna **4** pažymius ir egzamino pažymį, viso - 5.
Vardai ir pavardės generuojami paprastai, tiesiog Vardas(Pavardė) +  atitinkamas skaičius.
Rūšiavimas į dvi kategorijas įgyvendintas pasirodžiusiu efektyviausiu metodu (na bent jau atminties prasme) - kai sukuriamas vienas papildomas sąrašas (vektorius), iš bendro surūšiuoto sąrašo (vektoriaus) nuskaitinėjamos reikšmės ir pridedamos į naują sąrašą (vektorių) bei ištrinamos iš bendro sąrašo (vektoriaus), kol tenkina sąlygą.

## spartos analizės rezultatas
**x86**

![](https://github.com/siveta/first_project/blob/v_05/speedTest.png)


