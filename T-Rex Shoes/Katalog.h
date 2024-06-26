#ifndef KATALOG_H
#define KATALOG_H

#include "database.h"
#include "Preorder.h"
#include "Keranjang.h"

void __KATALOG() {
    cout << bersih
        << "+-------------------------------------+\n"
        << "|                KATALOG              |\n"
        << "+-------------------------------------+\n"
        << "| Selamat datang di katalog, terdapat |\n"
        << "| Banyak pilihan sepatu disini...     |\n"
        << "+-------------------------------------+\n"
        << "| 1. Sepatu Dewasa lk                 |\n"
        << "| 2. Sepatu Dewasa pr                 |\n"
        << "| 3. Sepatu Dewasa bebas              |\n"
        << "| 4. Sepatu Anak                      |\n"
        << "| 5. Spesial Preorder                 |\n"
        << "|                                     |\n"
        << "+-------------------------------------+\n"
        << "pilih (0 kembali): ";
        cin >> pil;
        cin.ignore();
        switch (pil) {
            case 0:
                return;
            break;
            case 1:
                __Katalog_Cetak(1);
            break;
            case 2:
                __Katalog_Cetak(2);
            break;
            case 3:
                __Katalog_Cetak(3);
            break;
            case 4:

            break;
            case 5:
                __Preorder();
            break;
        }
}

void __Katalog_Cetak(int pilihan) {

    char beli;

    string pencarian, target, IDBeli;
    switch (pilihan) {
        case 1:
            pencarian = "Dewasa Laki-laki";
        break;
        case 2:
            pencarian = "Dewasa Perempuan";
        break;
        case 3:
            pencarian = "Dewasa";
        break;
    }

    // cetak tabel

    cout << bersih
         << "+--------------------------------------------------------------+\n"
         << "|" <<setw(17)<< "Menampilkan " <<left<<setw(20) << pencarian <<right<< setw(27) << "|\n"
         << "+----+-----------+--------------------+------------+-----------+\n"
         << "| ID | Merek     | Nama               | Jenis      | Harga     |\n"
         << "+----+-----------+--------------------+------------+-----------+\n"
         << left;
    // cari sepatu yang sama
    for (int i = 0; i < jumlahSepatu; i++) {
        if (pencarian == "Dewasa") {
            if (sepatu[i].kategori == "Dewasa Perempuan" || sepatu[i].kategori == "Dewasa Laki-laki" ){
            cout << "| "
                 << setw(3) << sepatu[i].ID     << "| "
                 << setw(10) << sepatu[i].Merek  << "| "
                 << setw(19)<< sepatu[i].Nama   << "| "
                 << setw(11)<< sepatu[i].Jenis  << "| "
                 << setw(10) << sepatu[i].Harga  << "|\n";
            }
        } else if (sepatu[i].kategori == pencarian) {
            cout << "|"
                 << setw(4) << sepatu[i].ID     << "| "
                 << setw(10) << sepatu[i].Merek  << "| "
                 << setw(19)<< sepatu[i].Nama   << "| "
                 << setw(11)<< sepatu[i].Jenis  << "| "
                 << setw(10) << sepatu[i].Harga  << "|\n";

        }
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
    //getchar();
}



#endif // KATALOG_H
