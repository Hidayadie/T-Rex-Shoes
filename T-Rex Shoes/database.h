#ifndef DATABASE_H
#define DATABASE_H
#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>



void Program()          ,
     database()         ,
     __KATALOG()          ,
     __Katalog_Cetak(int pilihan)   ,
     __KERANJANG()        ,
     __Preorder()         ,
     profil()             ,
     bersihkanLayar()     ;


void bersihkanLayar() {
    #ifdef __linux__
    system("clear");
    #elif _WIN32
    system("cls");
    #endif // __linux__
}

using namespace std;
#define bersih "\033[2J \033[1;1H"

const int MAX_ISI = 30;
int pil, jumlahSepatu = 0;
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

struct SepatuPreOrder {
        string ID          ,
               Merek       ,   // Merek dari sepatu
               kategori    ,   // Kategori sepatu
               Nama        ,   // Nama sepatunya
               Jenis       ;   // Jenis (Sneakers, sport, dsb)
        int    Harga       ,   // Harga sepatunya
               stok        ;   // Stack buat jumlah stok
};

Sepatu sepatu[MAX_ISI];
SepatuPreOrder Spesial[] = {
    {"A01", "Adibozz", "Dewasa Laki-laki", "Sepatu es", "Ski", 69000, 5},
    {"H02", "Kiwiwi", "Anak-anak", "roket shoes", "roket", 125000, 10},
    {"F21", "Yeyeye", "Anak-anak", "magnetic 2000", "Velcro", 750000, 3}

};

void database() {
    ifstream fileSepatu("database/database.txt");
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

    } else {
        cout << "not ok";
    }
}

#endif // DATABASE_H
