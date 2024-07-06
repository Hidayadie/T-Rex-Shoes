#ifndef KATALOG_H
#define KATALOG_H

#include "../Database/database.h"
#include "sorting.h"
#include "keranjang.h"
using namespace std;

// konstruktor
void _K_Print(int pilihan, int halaman, int urutan) ,
     _K_Menu(int pilihan, int halaman, int urutan)  ;

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
                _K_Menu(1, 1, 0);
            break;
            case 2:
                _K_Menu(2, 1, 0);
            break;
            case 3:
                _K_Menu(3, 1, 0);
            break;
            case 4:
                _K_Menu(4, 1, 0);
            break;
            case 5:
<<<<<<< HEAD
                _K_Menu(5, 1, 0);
=======
                _K_Menu(5);
            break;
            default:
                cout << Merah << "Pilihan tidak tersedia!" << RESET;
                getchar();
>>>>>>> 0faa2f48a58999c0371b22db7e0b754ff9225ee3
            break;
        }
}



void _K_Print(int pilihan, int halaman, int pengurutan) {
    string pencarian,
           urutan[] = {"ID","Merek","Nama","Harga"};
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
<<<<<<< HEAD
    cout << left
         << "+---------------------------------------------------------------------+\n"
         << "| Menampilkan: " <<left<<setw(20) << pencarian <<right<< setw(37) << "|\n"
         << "| Dengan pengurutan: "<<left<<setw(6) << urutan[pengurutan]<<" ["<<halaman * 10 - 9<<"-"<<halaman * 10<<"]"<<right<<setw(38) << "|\n"
         << "+----+-----------+--------------------+------------+-----------+------+\n"
         << "| ID | Merek     | Nama               | Jenis      | Harga     | stok |\n"
         << "+----+-----------+--------------------+------------+-----------+------+\n"
         << left;
=======
    cout << "+----------------------------------------------------------------------+\n"
         << "|" <<setw(17)<< "Menampilkan " <<left<<setw(20) << pencarian <<right<< setw(35) << "|\n"
         << "+----+-----------+--------------------+------------+-----------+-------+\n"
         << "| ID | Merek     | Nama               | Jenis      | Harga     | stok  |\n"
         << "+----+-----------+--------------------+------------+-----------+-------+\n"
         <<left;
>>>>>>> 0faa2f48a58999c0371b22db7e0b754ff9225ee3
    // cari sepatu yang sama
    for (int i = halaman * 10 - 10; i < halaman * 10; i++) {
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
<<<<<<< HEAD
    cout << "+----+-----------+--------------------+------------+-----------+------+\n";

=======
    cout << "+----+-----------+--------------------+------------+-----------+-------+\n";
>>>>>>> 0faa2f48a58999c0371b22db7e0b754ff9225ee3
}



void _K_Menu(int pilihan, int halaman, int urutan) {
    int hal = halaman;
    int uru = urutan;
    string IDBeli;
    _K_Print(pilihan, hal, uru);
    cout << "|    [q] prev     [e] next     [s] sort    [b] beli     [r] kembali   |\n"
         << "+---------------------------------------------------------------------+\n";
    char pilih;
    cout << " -> "; cin >> pilih;
    cin.ignore();

    switch (pilih) {
        case 'b':
        case 'B':
            cout << "Masukkan \"ID\" Sepatu yang ingin anda beli...";
            cout << " -> "; getline(cin, IDBeli);
            for (int i = 0; i < jumlahSepatu; i++) {
                if (IDBeli == sepatu[i].ID) {
                    TambahKeranjang(sepatu[i]);
                }
            }
            cout << "Barang berhasil dimasukkan kedalam keranjang";
            getchar();
        break;

        case 's':
        case 'S':
            bersihkanLayar();
            _K_Print(pilihan, hal, uru);
            uru = menuSort();
            bersihkanLayar();
            _K_Menu(pilihan, hal, uru);
        break;

        case 'e':
        case 'E':
            if (hal < 4) hal++;
            _K_Print(pilihan, hal, uru);
            _K_Menu(pilihan, hal, uru);
        break;
        case 'q':
        case 'Q':
            if (hal > 1) hal--;
            _K_Print(pilihan, hal, uru);
            _K_Menu(pilihan, hal, uru);
        break;
        case 'r':
        case 'R':
            return;
        break;
    }

    //getchar();
}


#endif // KATALOG_H
