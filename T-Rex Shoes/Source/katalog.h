#ifndef KATALOG_H
#define KATALOG_H

#include "../Database/database.h"
#include "sorting.h"
#include "keranjang.h"
using namespace std;

// konstruktor
void _K_Print(int pilihan, int halaman, int urutan) ,
     _K_Menu(int pilihan, int halaman, int urutan)  ,
     _K_Sepatu(int indeks)         ;

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
                _K_Menu(5, 1, 0);
            break;
            default:
                cout << Merah << "Pilihan tidak tersedia!" << RESET;
                getchar();
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
    cout << left
         << "+-----------------------------------------------------------------------+\n"
         << "| Menampilkan: " <<left<<setw(20) << pencarian <<right<< setw(39) << "|\n"
         << "| Dengan pengurutan: "<<left<<setw(6) << urutan[pengurutan]<<" ["<< setw(2) << halaman * 10 - 9<<"-"<<halaman * 10<<"]"<<right<<setw(39) << "|\n"
         << "+----+------------+--------------------+------------+-----------+-------+\n"
         << "| ID | Merek      | Nama               | Jenis      | Harga     | stok  |\n"
         << "+----+------------+--------------------+------------+-----------+-------+\n"
         << left;
    // cari sepatu yang sama
    for (int i = halaman * 10 - 10; i < halaman * 10; i++) {
        if (pencarian == "Dewasa") {
            if (sepatu[i].kategori == "Dewasa Perempuan" || sepatu[i].kategori == "Dewasa Laki-laki" ){
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

            }
        } else if (sepatu[i].kategori == pencarian) {
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

        } else if (pencarian == "Semua") {
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
        }
    }

    cout << "+----+------------+--------------------+------------+-----------+-------+\n";

}



void _K_Menu(int pilihan, int halaman, int urutan) {
    int hal = halaman;
    int uru = urutan;
    string IDBeli;
    _K_Print(pilihan, hal, uru);
    cout << "|     [q] prev     [e] next     [s] sort    [b] beli     [r] kembali    |\n"
         << "+-----------------------------------------------------------------------+\n";
    char pilih;
    cout << " -> "; cin >> pilih;
    cin.ignore();

    switch (pilih) {
        case 'b':
        case 'B':
            cout << "Masukkan \"ID\" Sepatu yang ingin anda beli...";
            cout << " -> "; getline(cin, IDBeli);
            _K_Sepatu(Cari_ID(IDBeli));
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
            if (hal < jumlahSepatu / 10 + 1) hal++;
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

}


void _K_Sepatu(int indeks) {
    bersihkanLayar();
    cout << left;
    if (sepatu[indeks].Jenis == "Sneakers" ||
        sepatu[indeks].Jenis == "Walking"  ||
        sepatu[indeks].Jenis == "Sandals"  ||
        sepatu[indeks].Jenis == "Casual")  {
        cout << "| "<<setw(19) <<casual[0] <<  BiruMuda << sepatu[indeks].Nama << "\n" << RESET
             << "| "<<setw(19) <<casual[1] <<  "by: " << sepatu[indeks].Merek << "\n"
             << "| "<<setw(19) <<casual[2] <<  "\n"
             << "| "<<setw(19) <<casual[3] <<  RunningDesc[0] << "\n"
             << "| "<<setw(19) <<casual[4] <<  RunningDesc[1] << "\n"
             << "| "<<setw(19) <<casual[5] <<  RunningDesc[2] << "\n";
    }
    else if (sepatu[indeks].Jenis == "Skate") {
        cout << "| "<<setw(19) <<" "      <<  BiruMuda << sepatu[indeks].Nama << "\n" << RESET
             << "| "<<setw(19) <<skate[0] <<  "by: " << sepatu[indeks].Merek << "\n"
             << "| "<<setw(19) <<skate[1] <<  "\n"
             << "| "<<setw(19) <<skate[2] <<  skateDesc[0] << "\n"
             << "| "<<setw(19) <<skate[3] <<  skateDesc[1] << "\n"
             << "| "<<setw(19) <<skate[4] <<  skateDesc[2] << "\n";
             }
    else if (sepatu[indeks].Jenis == "Boots") {
        cout << "| "<<setw(19) <<boots[0]      <<  BiruMuda << sepatu[indeks].Nama << "\n" << RESET
             << "| "<<setw(19) <<boots[1] <<  "by: " << sepatu[indeks].Merek << "\n"
             << "| "<<setw(19) <<boots[2] <<  "\n"
             << "| "<<setw(19) <<boots[3] <<  "" << "\n"
             << "| "<<setw(19) <<boots[4] <<  bootdesc[0] << "\n"
             << "| "<<setw(19) <<boots[5] <<  bootdesc[1] << "\n"
             << "| "<<setw(19) <<boots[6] <<  bootdesc[2] <<"\n"
             << "| "<<setw(19) <<boots[7] <<  bootdesc[3] <<"\n"
             << "| "<<setw(19) <<boots[8] <<  bootdesc[4] <<"\n";
    }
    else if (sepatu[indeks].Jenis == "Sport"    ||
             sepatu[indeks].Jenis =="Running"   ||
             sepatu[indeks].Jenis =="Training"  ||
             sepatu[indeks].Jenis =="Basketball"||
             sepatu[indeks].Jenis =="Hiking"    ||
             sepatu[indeks].Jenis =="Hiking")   {
        cout << "| "<<setw(19) <<" "      <<  BiruMuda << sepatu[indeks].Nama << "\n" << RESET
             << "| "<<setw(19) <<sports[0] <<  "by: " << sepatu[indeks].Merek << "\n"
             << "| "<<setw(19) <<sports[1] <<  "\n"
             << "| "<<setw(19) <<sports[2] <<  sportsdesc[0] << "\n"
             << "| "<<setw(19) <<sports[3] <<  sportsdesc[1] << "\n"
             << "| "<<setw(19) <<sports[4] <<  sportsdesc[2] << "\n";
             }
    cout << "| \n"
         << "| "<<((sepatu[indeks].stok.jumlah > 5) ? Hijau : (sepatu[indeks].stok.jumlah == 0) ? Merah : Kuning)
         <<    "Stok tersedia: " << sepatu[indeks].stok.jumlah << "\n" << RESET
         << "| Size: ";
         if (sepatu[indeks].kategori == "Dewasa Laki-laki" || sepatu[indeks].kategori =="Dewasa Perempuan") {
            cout << ((sepatu[indeks].stok.jumlah > 7) ? Hijau : Merah) << "38 " << RESET
                 << ((sepatu[indeks].stok.jumlah > 3) ? Hijau : Merah) << "39 " << RESET
                 << ((sepatu[indeks].stok.jumlah > 1) ? Hijau : Merah) << "40 " << RESET
                 << ((sepatu[indeks].stok.jumlah > 0) ? Hijau : Merah) << "41 " << RESET
                 << ((sepatu[indeks].stok.jumlah > 4) ? Hijau : Merah) << "42 " << RESET;
         }
         else if (sepatu[indeks].kategori == "Anak-anak") {
            cout << ((sepatu[indeks].stok.jumlah > 7) ? Hijau : Merah) << "33 " << RESET
                 << ((sepatu[indeks].stok.jumlah > 3) ? Hijau : Merah) << "34 " << RESET
                 << ((sepatu[indeks].stok.jumlah > 1) ? Hijau : Merah) << "35 " << RESET
                 << ((sepatu[indeks].stok.jumlah > 0) ? Hijau : Merah) << "36 " << RESET
                 << ((sepatu[indeks].stok.jumlah > 4) ? Hijau : Merah) << "37 " << RESET;
         }
    cout << "\n"
         << "| \n"
         << "| Harga: Rp " << sepatu[indeks].Harga << "\n";
    if (sepatu[indeks].stok.jumlah > 0) {
        cout << "| Apakah anda ingin membelinya?\n"
             << "| (Y/n): "; cin >> pilC;
        cin.ignore();
        if (pilC == 'Y' || pilC == 'y') TambahKeranjang(sepatu[indeks]);

    } else {
        cout << "| " << Merah << "Stok habis...\n" << RESET
             << "| " << Merah << "Silahkan cek lagi nanti" << RESET;
             getchar();
    }




}

#endif // KATALOG_H
