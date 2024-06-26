#ifndef PENCARIAN_H
#define PENCARIAN_H
#include "database.h"



void kecilkanHuruf(char* str) {
    while (*str) {
        *str = tolower(*str);
        str++;
    }
}

void pencarian() {
    string keyword, IDBeli;
    char beli;
    cout << bersih
         << "+-------------------------------------+\n"
         << "|              PENCARIAN              |\n"
         << "+-------------------------------------+\n"
         << "Masukkan kata kunci pencarian: ";
    getline(cin, keyword);

    char keywordLower[100];
    strcpy(keywordLower, keyword.c_str());
    kecilkanHuruf(keywordLower);

    bool found = false;
    system("cls");
    cout << "+----+-----------+--------------------+------------+-----------+\n"
         << "| ID | Merek     | Nama               | Jenis      | Harga     |\n"
         << "+----+-----------+--------------------+------------+-----------+\n"
         << left;

    for (int i = 0; i < jumlahSepatu; i++) {
        char namaLower[100];
        strcpy(namaLower, sepatu[i].Nama.c_str());
        kecilkanHuruf(namaLower);

        char merekLower[100];
        strcpy(merekLower, sepatu[i].Merek.c_str());
        kecilkanHuruf(merekLower);

        if (strstr(namaLower, keywordLower) != NULL || strstr(merekLower, keywordLower) != NULL) {
            cout << "|"
                 << setw(4) << sepatu[i].ID << "| "
                 << setw(10) << sepatu[i].Merek << "| "
                 << setw(19) << sepatu[i].Nama << "| "
                 << setw(11) << sepatu[i].Jenis << "| "
                 << setw(10) << sepatu[i].Harga << "|\n";
            found = true;
        }
    }

    if (!found) {
        cout << left << setw(15) << "|" <<setw(48) << "Tidak ada hasil yang ditemukan" <<"|\n";
    }

    cout << "+----+-----------+--------------------+------------+-----------+\n"
         << "|   Apakah anda ingin membeli dari satu diatas? (y/n)          |\n"
         << "+--------------------------------------------------------------+\n";
    cout << " -> "; cin >> beli;
    cin.ignore();
    if (beli == 'y' || beli == 'Y') {
        cout << "Masukkan \"ID\" Sepatu yang ingin anda beli...";
        cout << " -> "; getline(cin, IDBeli);
        for (int i = 0; i < jumlahSepatu; i++) {
            if (IDBeli == sepatu[i].ID) {
                TambahKeranjang(sepatu[i]);
            }
        }
        cout << "Barang berhasil dimasukkan kedalam keranjang";
        getchar();
    }
}

#endif // PENCARIAN_H
