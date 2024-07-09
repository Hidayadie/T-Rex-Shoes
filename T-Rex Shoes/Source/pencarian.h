#ifndef PENCARIAN_H
#define PENCARIAN_H

//#include "../Database/database.h"
#include "keranjang.h"


void kecilkanHuruf(char* str) {
    while (*str) {
        *str = tolower(*str);
        str++;
    }
}



int Cari_ID(string _ID) {
    for (int i =0; i < jumlahSepatu; i++) {
        if (_ID == sepatu[i].ID) {
            return i;
        }
    }
    return -1;
}

int Cari_User(string nama) {
    for (int i = 0; i < jumlahUser; i++) {
        if (nama == user[i].Nama) {
            return i;
        }
    }
    return -1;
}

void M_PENCARIAN() {
    string keyword, IDBeli;
    char beli;
    bersihkanLayar();
    cout << "+-------------------------------------+\n"
         << "|              PENCARIAN              |\n"
         << "+-------------------------------------+\n"
         << "Masukkan kata kunci pencarian: ";
    getline(cin, keyword);

    char keywordLower[100];
    strcpy(keywordLower, keyword.c_str());
    kecilkanHuruf(keywordLower);

    bool found = false;
    bersihkanLayar();

    cout << left
         << "+-----------------------------------------------------------------------+\n"
         << "| Menampilkan: \""<<setw(20) << keyword + "\"" <<right<< setw(38) << "|\n"
         << "|                                                                       |\n"
         << "+----+------------+--------------------+------------+-----------+-------+\n"
         << "| ID | Merek      | Nama               | Jenis      | Harga     | stok  |\n"
         << "+----+------------+--------------------+------------+-----------+-------+\n"
         << left;
    for (int i = 0; i < jumlahSepatu; i++) {
        char namaLower[100];
        strcpy(namaLower, sepatu[i].Nama.c_str());
        kecilkanHuruf(namaLower);

        char merekLower[100];
        strcpy(merekLower, sepatu[i].Merek.c_str());
        kecilkanHuruf(merekLower);

        if (strstr(namaLower, keywordLower) != NULL || strstr(merekLower, keywordLower) != NULL) {
            cout << "| "
                 << setw(3) << sepatu[i].ID     << "| "
                 << setw(11) << sepatu[i].Merek  << "| "
                 << setw(19)<< sepatu[i].Nama   << "| "
                 << setw(11)<< sepatu[i].Jenis  << "| "
                 << setw(10) << sepatu[i].Harga  << "| "
                 << setw(6) << sepatu[i].stok.jumlah << "|\n";
            found = true;
        }
    }

    if (!found) {
        char ulang;
        cout << left << setw(15) << "|" <<setw(57) << "Tidak ada hasil yang ditemukan" <<"|\n";
        cout << "+----+------------+--------------------+------------+-----------+-------+\n"
             << "|      Apakah anda ingin melakukan pencarian ulang (y/n)                |\n"
             << "+-----------------------------------------------------------------------+\n";
        cout << "-> "; cin >> ulang;
        cin.ignore();
        if (ulang == 'y' || ulang == 'Y') {
            M_PENCARIAN();
            return;
        } else if (ulang == 'n' || ulang == 'N') {
            return;
        }
    }

    cout << "+----+------------+--------------------+------------+-----------+-------+\n"
         << "|          Apakah anda ingin membeli dari satu diatas? (y/n)            |\n"
         << "+-----------------------------------------------------------------------+\n";
    cout << " -> "; cin >> beli;
    cin.ignore();
    if (beli == 'y' || beli == 'Y') {
        cout << "Masukkan \"ID\" Sepatu yang ingin anda beli...";
        cout << " -> "; getline(cin, IDBeli);
        if (Cari_ID(IDBeli) != -1) {
            _K_Sepatu(Cari_ID(IDBeli));
        }
    }
}



#endif // PENCARIAN_H
