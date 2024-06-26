#ifndef KATALOG_H
#define KATALOG_H

#include "database.h"
#include "Preorder.h"
#include "Keranjang.h"
#include "Sorting.h"


void __KATALOG() {
    system("cls");
    cout    << "+-------------------------------------+\n"
        << "|                KATALOG              |\n"
        << "+-------------------------------------+\n"
        << "| Selamat datang di katalog, terdapat |\n"
        << "| Banyak pilihan sepatu disini...     |\n"
        << "+-------------------------------------+\n"
        << "| 1. Tampilkan Keseluruhan            |\n"
        << "| 2. Sepatu Dewasa lk                 |\n"
        << "| 3. Sepatu Dewasa pr                 |\n"
        << "| 4. Sepatu Dewasa bebas              |\n"
        << "| 5. Sepatu Anak                      |\n"
        << "|                                     |\n"
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
                __Katalog_Cetak(4);
            break;
            case 5:
                __Katalog_Cetak(5);
            break;
            case 6:
                //__Preorder();
            break;
        }
}

void __Katalog_Print(int pilihan) {
    string pencarian;
    switch (pilihan) {
        case 1:
            pencarian = "Semua";
        break;
        case 2:
            pencarian = "Dewasa Laki-laki";
        break;
        case 3:
            pencarian = "Dewasa Perempuan";
        break;
        case 4:
            pencarian = "Dewasa";
        break;
        case 5:
            pencarian = "Anak-anak";
        break;
    }

    // cetak tabel

   system("cls");
    cout << "+---------------------------------------------------------------------+\n"
         << "|" <<setw(17)<< "Menampilkan " <<left<<setw(20) << pencarian <<right<< setw(34) << "|\n"
         << "+----+-----------+--------------------+------------+-----------+------+\n"
         << "| ID | Merek     | Nama               | Jenis      | Harga     | stok |\n"
         << "+----+-----------+--------------------+------------+-----------+------+\n"
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
                 << setw(10) << sepatu[i].Harga  << "| "
                 << setw(5) << sepatu[i].stok.jumlah << "|\n";

            }
        } else if (sepatu[i].kategori == pencarian) {
            cout << "| "
                 << setw(3) << sepatu[i].ID     << "| "
                 << setw(10) << sepatu[i].Merek  << "| "
                 << setw(19)<< sepatu[i].Nama   << "| "
                 << setw(11)<< sepatu[i].Jenis  << "| "
                 << setw(10) << sepatu[i].Harga  << "| "
                 << setw(5) << sepatu[i].stok.jumlah << "|\n";

        } else if (pencarian == "Semua") {
            cout << "| "
                 << setw(3) << sepatu[i].ID     << "| "
                 << setw(10) << sepatu[i].Merek  << "| "
                 << setw(19)<< sepatu[i].Nama   << "| "
                 << setw(11)<< sepatu[i].Jenis  << "| "
                 << setw(10) << sepatu[i].Harga  << "| "
                 << setw(5) << sepatu[i].stok.jumlah << "|\n";
        }
    }
    cout << "+----+-----------+--------------------+------------+-----------+------+\n";
}

void __Katalog_Cetak(int pilihan) {
    string IDBeli;
    __Katalog_Print(pilihan);
    char pilih;
    cout << "Pilih menu:\n"
         << "1. Beli\n"
         << "2. Urutkan\n"
         << "3. Kembali\n";

    cout << " -> "; cin >> pilih;
    cin.ignore();

    if (pilih == '1') {
        cout << "Masukkan \"ID\" Sepatu yang ingin anda beli...";
        cout << " -> "; getline(cin, IDBeli);
        for (int i = 0; i < jumlahSepatu; i++) {
            if (IDBeli == sepatu[i].ID) {
                TambahKeranjang(sepatu[i]);
            }
        }
        cout << "Barang berhasil dimasukkan kedalam keranjang";
        getchar();
    } else if (pilih == '2') {
        system("cls");
        __Katalog_Print(pilihan);
        menuSort();
        system("cls");
        __Katalog_Cetak(pilihan);
    }
    //getchar();
}



#endif // KATALOG_H
