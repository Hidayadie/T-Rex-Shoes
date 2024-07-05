#ifndef KATALOG_H
#define KATALOG_H

#include "../Database/database.h"
#include "sorting.h"
#include "keranjang.h"
using namespace std;

// konstruktor
void _K_Print(int pilihan) ,
     _K_Menu(int pilihan)  ;

//int pil;

void M_KATALOG() {
    bersihkanLayar();
    cout<< "+-------------------------------------+\n"
        << "|                "<< Kuning<<"KATALOG"<< RESET<<"              |\n"
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
                _K_Menu(1);
            break;
            case 2:
                _K_Menu(2);
            break;
            case 3:
                _K_Menu(3);
            break;
            case 4:
                _K_Menu(4);
            break;
            case 5:
                _K_Menu(5);
            break;
            default:
                cout << Merah << "Pilihan tidak tersedia!" << RESET;
                getchar();
            break;
        }
}



void _K_Print(int pilihan) {
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

   bersihkanLayar();
    cout << "+----------------------------------------------------------------------+\n"
         << "|" <<setw(17)<< "Menampilkan " <<left<<setw(20) << pencarian <<right<< setw(35) << "|\n"
         << "+----+-----------+--------------------+------------+-----------+-------+\n"
         << "| ID | Merek     | Nama               | Jenis      | Harga     | stok  |\n"
         << "+----+-----------+--------------------+------------+-----------+-------+\n"
         <<left;
    // cari sepatu yang sama
    for (int i = 0; i < jumlahSepatu; i++) {
        if (pencarian == "Dewasa") {
            if (sepatu[i].kategori == "Dewasa Perempuan" || sepatu[i].kategori == "Dewasa Laki-laki" ){
            cout <<"| "
                 << ((sepatu[i].stok.jumlah == 0) ? Merah : ((sepatu[i].stok.jumlah < 10) ? Kuning : RESET))
                 << setw(3) << sepatu[i].ID         << RESET << "| "
                 << ((sepatu[i].stok.jumlah == 0) ? Merah : ((sepatu[i].stok.jumlah < 10) ? Kuning : RESET))
                 << setw(10) << sepatu[i].Merek     << RESET <<"| "
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

            }
        } else if (sepatu[i].kategori == pencarian) {
            cout <<"| "
                 << ((sepatu[i].stok.jumlah == 0) ? Merah : ((sepatu[i].stok.jumlah < 10) ? Kuning : RESET))
                 << setw(3) << sepatu[i].ID         << RESET << "| "
                 << ((sepatu[i].stok.jumlah == 0) ? Merah : ((sepatu[i].stok.jumlah < 10) ? Kuning : RESET))
                 << setw(10) << sepatu[i].Merek     << RESET <<"| "
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

        } else if (pencarian == "Semua Sepatu") {
            cout <<"| "
                 << ((sepatu[i].stok.jumlah == 0) ? Merah : ((sepatu[i].stok.jumlah < 10) ? Kuning : RESET))
                 << setw(3) << sepatu[i].ID         << RESET << "| "
                 << ((sepatu[i].stok.jumlah == 0) ? Merah : ((sepatu[i].stok.jumlah < 10) ? Kuning : RESET))
                 << setw(10) << sepatu[i].Merek     << RESET <<"| "
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
        }
    }
    cout << "+----+-----------+--------------------+------------+-----------+-------+\n";
}



void _K_Menu(int pilihan) {
    string IDBeli;
    _K_Print(pilihan);
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
        bersihkanLayar();
        _K_Print(pilihan);
        menuSort();
        bersihkanLayar();
        _K_Menu(pilihan);
    }
    //getchar();
}


#endif // KATALOG_H
