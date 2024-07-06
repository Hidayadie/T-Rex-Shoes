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
            cout <<"| "
                 << ((sepatu[i].stok.jumlah == 0) ? Merah : ((sepatu[i].stok.jumlah < 10) ? Kuning : RESET))
                 << setw(3) << sepatu[i].ID         << RESET << "| "
                 << ((sepatu[i].stok.jumlah == 0) ? Merah : ((sepatu[i].stok.jumlah < 10) ? Kuning : RESET))
                 << setw(11) << sepatu[i].Merek     << RESET <<"| "
                 << ((sepatu[i].stok.jumlah == 0) ? Merah : ((sepatu[i].stok.jumlah < 10) ? Kuning : RESET))
                 << setw(19)<< sepatu[i].Nama       << RESET <<"| "
                 << ((sepatu[i].stok.jumlah == 0) ? Merah : ((sepatu[i].stok.jumlah < 10) ? Kuning : RESET))
                 << setw(11)<< sepatu[i].Jenis      << RESET <<"| "
                 << ((sepatu[i].stok.jumlah == 0) ? Merah : ((sepatu[i].stok.jumlah < 10) ? Kuning : RESET))
                 << setw(10) << sepatu[i].Harga     << RESET <<"| "
                 << ((sepatu[i].stok.jumlah == 0) ? Merah : ((sepatu[i].stok.jumlah < 10) ? Kuning : RESET));
            if (sepatu[i].stok.jumlah == 0) {
            cout << setw(6)
                 << "HABIS"<< RESET <<"|\n";
            } else {
            cout << setw(6)
                 << sepatu[i].stok.jumlah<< RESET <<"|\n";
            }
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
        for (int i = 0; i < jumlahSepatu; i++) {
            if (IDBeli == sepatu[i].ID) {
                //TambahKeranjang(sepatu[i]);
                #ifdef KERANJANG_H
                TambahKeranjang(sepatu[i]);
                cout << "BRUH";
                getchar();
                #endif // KERANJANG_H
            }
        }
        cout << "Barang berhasil dimasukkan kedalam keranjang";
        getchar();
    }
}



#endif // PENCARIAN_H
