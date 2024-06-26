#ifndef PENCARIAN_H
#define PENCARIAN_H
#include "database.h"

using namespace std;
/*
std::string toLowerCase(const std::string& str) {
    std::string lowerStr = str;
    std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

// Fungsi untuk mencari sepatu berdasarkan kategori tidak case-sensitive
void Pencarian(const Sepatu sepatuList[], int jumlahSepatu, const std::string& kategoriPencarian) {
    std::string lowerKategoriPencarian = toLowerCase(kategoriPencarian);

    std::cout << "+--------------------------------------------------------+\n"
              << "|    Menampilkan Sepatu berdasarkan kategori             |\n"
              << "+----+---------+--------------------+----------+---------+\n"
              << "| ID | Merek   | Nama               | Jenis    | Harga   |\n"
              << "+----+---------+--------------------+----------+---------+\n";

    for (int i = 0; i < jumlahSepatu; ++i) {
        if (toLowerCase(sepatuList[i].kategori).find(lowerKategoriPencarian) != std::string::npos) {
            std::cout << "|" << std::setw(4) << sepatuList[i].ID
                      << "|" << std::setw(9) << sepatuList[i].Merek
                      << "|" << std::setw(20) << sepatuList[i].Nama
                      << "|" << std::setw(10) << sepatuList[i].Jenis
                      << "|" << std::setw(9) << sepatuList[i].Harga << "|\n";
        }
    }

    std::cout << "+----+---------+--------------------+----------+---------+\n";
    getchar();
}



*/
#endif // PENCARIAN_H
