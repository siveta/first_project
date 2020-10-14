#include "greicio_analize.h"

void el_po_el(std::string read_vardas, std::string write_vardas) {
    std::vector<std::string> splited;
    std::string eil;
    //----------------------------------------------------------------------
    auto start = std::chrono::high_resolution_clock::now(); auto st = start;
    std::ifstream open_f(read_vardas);
    while (open_f) {
        if (!open_f.eof()) {
            open_f >> eil;
            splited.push_back(eil);
        }
        else break;
    }
    open_f.close();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start; // Skirtumas (s)
    std::cout << "Failo nuskaitymas i zodziu vektoriu uztruko: " << diff.count() << " s\n";
    //------------------------------------------------------------------------ 
    double sk = 0.0;
    start = std::chrono::high_resolution_clock::now();
    std::ofstream out_f(write_vardas);
    for (std::string a : splited) {
        if (int(sk) % 23 != 22.0) out_f << std::setw(20) << std::fixed << a;
        else out_f << std::setw(20) << std::fixed << a << std::endl;
        sk++;
    }
    out_f.close();
    end = std::chrono::high_resolution_clock::now();
    diff = end - start; // Skirtumas (s)
    std::cout << "Failo irasymas is zodziu vektoriaus uztruko: " << diff.count() << " s\n";
    splited.resize(0);

    diff = std::chrono::high_resolution_clock::now() - st; // Skirtumas (s)
    std::cout << "Visas sugaistas laikas: " << diff.count() << " s\n\n";
}