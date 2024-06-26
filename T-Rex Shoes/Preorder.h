#ifndef PREORDER_H
#define PREORDER_H

#include "database.h"

void __Preorder() {
    char beli;
    cout << bersih
         << "+--------------------------------------------------------------+\n"
         << "|" <<setw(17)<< "Menampilkan " <<left<<setw(20) << "Sepatu preorder" <<right<< setw(27) << "|\n"
         << "+----+-----------+--------------------+------------+-----------+\n"
         << "| ID | Merek     | Nama               | Jenis      | Harga     |\n"
         << "+----+-----------+--------------------+------------+-----------+\n"
         << left;
    for (int i = 0; i < 3; i++) {
        cout << "| "
             << setw(3) << Spesial[i].ID     << "| "
             << setw(10) << Spesial[i].Merek  << "| "
             << setw(19)<< Spesial[i].Nama   << "| "
             << setw(11)<< Spesial[i].Jenis  << "| "
             << setw(10) << Spesial[i].Harga  << "|\n";
    }
    cout << "+----+-----------+--------------------+------------+-----------+\n"
         << "| Apakah anda ingin melakukan preorder dari satu diatas? (y/n) |\n"
         << "+--------------------------------------------------------------+\n";
    cout << " -> "; cin >> beli;
    cin.ignore();

}
#endif // PREORDER_H
