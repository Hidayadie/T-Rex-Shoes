#ifndef DATABASE
#define DATABASE


#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <string>

void MAIN_PROGRAM()     ,
     M_DATABASE()       ,
     M_PROFIL()         ,
     M_KATALOG()        ,
     M_PENCARIAN()      ,
     M_KERANJANG()      ,
     bersihkanLayar()   ,
     Cari_ID(std::string _ID)          ;




bool database_read()    ,
     database_update()  ,
     database_add()     ;

void bersihkanLayar() {
    #ifdef __linux__
    system("clear");
    #elif _WIN32
    system("cls");
    #endif // __linux__
}

using namespace std;





const int MAX_ISI       = 50;
      int pil               ,
          jumlahSepatu  = 0 ;

struct Stock {
        int jumlah          ; // jumlah sepatu itu sendiri
        string kondisi[100] ; // Implementasian stack berada pada
                              // string kondisi yang dimana setiap
                              // satuan sepatu memiliki kondisinya
                              // masing masing
};

struct Sepatu {
        string ID          ,
               Merek       ,   // Merek dari sepatu
               kategori    ,   // Kategori sepatu
               Nama        ,   // Nama sepatunya
               Jenis       ;   // Jenis (Sneakers, sport, dsb)
        int    Harga       ;   // Harga sepatunya
        Stock  stok        ;   // Stack buat jumlah stok
};


Sepatu sepatu[MAX_ISI];



void M_DATABASE() {
    //database_read();
}


bool database_read() {
    ifstream fileSepatu("Database/database.txt");
    if (fileSepatu.is_open()) {
        string _ID          ,
               _Merek       ,   // Merek dari sepatu
               _kategori    ,   // Kategori sepatu
               _Nama        ,   // Nama sepatunya
               _Jenis       ;   // Jenis (Sneakers, sport, dsb)
        int    _Harga       ,   // Harga sepatunya
               _stok        ;   // Stack buat jumlah stok


        string temp;
        while (getline(fileSepatu, _ID      ,   ',')) {
               getline(fileSepatu, _Merek   ,   ',');
               getline(fileSepatu, _kategori,   ',');
               getline(fileSepatu, _Nama    ,   ',');
               getline(fileSepatu, _Jenis   ,   ',');
               getline(fileSepatu, temp     ,   ','); _Harga = stoi(temp);
               getline(fileSepatu, temp            ); _stok  = stoi(temp);

               sepatu[jumlahSepatu].ID          =   _ID      ;
               sepatu[jumlahSepatu].Merek       =   _Merek   ;
               sepatu[jumlahSepatu].kategori    =   _kategori;
               sepatu[jumlahSepatu].Nama        =   _Nama    ;
               sepatu[jumlahSepatu].Jenis       =   _Jenis   ;
               sepatu[jumlahSepatu].Harga       =   _Harga   ;
               sepatu[jumlahSepatu].stok.jumlah =   _stok    ;
               jumlahSepatu++;
        }

        fileSepatu.close();
        return true;
    } else {
        return false;
    }
}
/*
bool database_add() {
    ofstream fileSepatu;

    fileSepatu.open("Database/database.txt", ios::app);
    if (fileSepatu.is_open()) {
        string _ID          ,
               _Merek       ,   // Merek dari sepatu
               _kategori    ,   // Kategori sepatu
               _Nama        ,   // Nama sepatunya
               _Jenis       ;   // Jenis (Sneakers, sport, dsb)
        int    _Harga       ,   // Harga sepatunya
               _stok        ;   // Stack buat jumlah stok

        cout << "Masukkan id: "; getline(cin, _ID);
        cout << "Masukkan Merek: "; getline(cin, _Merek);
        cout << "Masukkan Nama: "; getline(cin, _Nama);
        cout << "Masukkan Jenis: "; getline(cin, _Jenis);
        //cout << "Masukkan Harga: "; getline(cin, _Harga);
        //cout << "Masukkan Stok: "; getline(cin, _Stok);
        fileSepatu << _ID << ',' << _Merek <<',' << "Anak-anak"<< ','<<_Nama <<',' <<_Jenis <<',' <<123400<<',' <<25<<'\n';
    fileSepatu.close();
    }
}
*/
bool database_update() {
    ofstream fileSepatu;

    fileSepatu.open("Database/database.txt");

    if (fileSepatu.is_open()) {
        for (int i = 0; i < jumlahSepatu; i++) {
            fileSepatu << sepatu[i].ID      << ','
                       << sepatu[i].Merek   << ','
                       << sepatu[i].kategori<< ','
                       << sepatu[i].Nama    << ','
                       << sepatu[i].Jenis   << ','
                       << sepatu[i].Harga   << ','
                       << sepatu[i].stok.jumlah << "\n";
        }
    }
    fileSepatu.close();
    return true;
}






void M_PROFIL() {
    bersihkanLayar();
    cout << "+---------------------------------------------------------------+\n"
        << "|                         Tentang Kami                          |\n"
        << "+---------------------------------------------------------------+\n"
        << "| Trex Shoes CLI, adalah toko sepatu berbasis TUI yang kami     |\n"
        << "| Kembangkan sepenuh hati untuk anda yang ingin berbelanja      |\n"
        << "| Sepatu secara minimalis melalui Terminal.                     |\n"
        << "+---------------------------------------------------------------+\n"
        << "|                          ---=+=---                            |\n"
        << "| Keluhan dan saran silahkan menghubungi kontak kami dibawah    |\n"
        << "| Telp  +62 8123456789                                          |\n"
        << "| Email sepatu_t-rex@rawrrr.co.id                               |\n"
        << "| Jl. Nusa Keren, no.123, kec Amomo, kab Yahelu, Kayangan       |\n"
        << "+---------------------------------------------------------------+";
    getchar();
}

void Member() {
    do {
        bersihkanLayar();
        cout<< "+-------------------------------+\n"
            << "|         SELAMAT DATANG        |\n"
            << "+-------------------------------+\n"
            << "|Silahkan masukkan pilihan Anda |\n"
            << "+-------------------------------+\n"
            << "|1. Profil                      |\n"
            << "|2. Katalog Barang              |\n"
            << "|3. Pencarian                   |\n"
            << "|4. Keranjang                   |\n"
            << "|5. Keluar                      |\n"
            << "+-------------------------------+\n";
            cout << "Pilihan Anda: "; cin >> pil;
            cin.ignore();

            switch (pil) {
                case 1:
                    M_PROFIL();
                break;
                case 2:
                    M_KATALOG();
                break;
                case 3:
                    M_PENCARIAN();
                break;
                case 4:
                    M_KERANJANG();
                break;
                case 5:
                    return;
                break;
            }
    } while (true);
}

void Admin() {
    do {
        bersihkanLayar();
        cout<< "+-------------------------------+\n"
            << "|         SELAMAT DATANG        |\n"
            << "+-------------------------------+\n"
            << "|Silahkan masukkan pilihan Anda |\n"
            << "+-------------------------------+\n"
            << "|1. Edit Katalog                |\n"
            << "|2. Edit User                   |\n"
            << "|3. Katalog Barang              |\n"
            << "|4. Pencarian                   |\n"
            << "|5. Keranjang                   |\n"
            << "|6. Keluar                      |\n"
            << "+-------------------------------+\n";
    } while (true);
}

#endif // DATABASE
