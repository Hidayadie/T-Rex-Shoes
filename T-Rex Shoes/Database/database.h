#ifndef DATABASE
#define DATABASE

// ifdef define diatas adalah preprocessor hanya
// dibaca oleh kompiler untuk mengecek bagaimana
// jalannya kode yang akan dibuat kedepannya,
// tetapi prepocessor diatas hanya mengecek apakah
// header ini sudah dibuat atau belum, jika belum
// maka kompiler akan membuat kode yang ada diantara
// if - end (ifndef - endif) yaitu pada line awal
// dan akhir pada setiap file header

// Hal ini dilakukan supaya ga terjadi redefinisi atau
// tumpang tindih file (kedouble"), dikarenakan beberapa
// header juga memerlukan header lain, jika tidak menggunakan
// ifndef maka jika ada header yang di panggil (#include)
// oleh 2 file lain maka akan terjadi redefinisi dan kode tdk
// bisa berjalan

#include <iostream> // untuk standar output/input stream
#include <fstream>  // untuk standar file stream
#include <string>   // untuk standar string
#include <iomanip>  // untuk setw()
#include <cstring>  // untuk strcpy

using namespace std;

// konstruktor
void MAIN_PROGRAM()         , // konstruktor main program
     M_DATABASE()           , // fungsi akses database (Admin)
     M_PROFIL()             , // fungsi menampilkan identitas T-Rex Shoes
     M_KATALOG()            , // fungsi menampilkan menu katalog
     M_PENCARIAN()          , // fungsi pencarian
     M_KERANJANG()          , // fungsi keranjang
     bersihkanLayar()       , // fungsi pembersihan layar
     Cari_ID(string _ID)    ; // fungsi cari sepatu berdasarkan ID

bool database_read()        , // fungsi pengecekan apakah berhasil membaca file
     database_update()      , // fungsi mengupdate database dan menulis ulang
     database_add()         ; // fungsi menambahkan database


//fungsi pembersihan layar
void bersihkanLayar() {
    // fungsi ini akan berlaku berbeda untuk setiap lingkungan
    // OS yang digunakannya, kompiler mengecek apakah os kali ini
    // menggunakan Linux atau Windows, biasanya kompiler secara
    // otomatis membuat macro define sendiri tergantung lingkungannya
    // seperti timestamp yang berisi kapan kode dijalankan atau waktu
    // nama os yang digunakan seperti __linux__ , _WIN32 atau _WIN64
    // begitu juga untuk MAC/apple juga punya sendiri


    #ifdef __linux__
    system("clear"); // jika berada pada lingkungan linux
                     // maka system clear akan dikompil
    #elif _WIN32
    system("cls");   // sedangkan jika windows, maka cls
                     // lah yang akan dikompile dan digunakan
    #endif // __linux__
}

/***************************************************/




const int MAX_ISI       = 50;   // digunakan untuk maksimal database

      int pil               ,   // global variabel pilihan
          jumlahSepatu  = 0 ;   // jumlah sepatu yang ada pada program

struct Stock {
    int jumlah          ; // jumlah sepatu itu sendiri
    string kondisi[100] ; // Implementasian stack berada pada
                          // string kondisi yang dimana setiap
                          // satuan sepatu memiliki kondisinya
                          // masing masing
};

struct Sepatu {
    string ID           ,   // ID sepatu
           Merek        ,   // Merek dari sepatu
           kategori     ,   // Kategori sepatu (Dewasa, Anak-anak)
           Nama         ,   // Nama sepatunya
           Jenis        ;   // Jenis (Sneakers, sport, dsb)
    int    Harga        ;   // Harga sepatunya
           Stock stok   ;   // Stack untuk jumlah stok
};

//  Pembuatan variabel sepatu dengan maksimal sesuai max
Sepatu sepatu[MAX_ISI];



void M_DATABASE() {
    //database_read();
}



// Fungsi ini digunakan untuk meload atau membaca database
// sepatu yang ada pada file database.txt
bool database_read() {
    // membuat variabel(class) inputStream dengan membuka file database.txt
    ifstream fileSepatu("Database/database.txt");

    // mengecek, jika file dapat dibuka
    if (fileSepatu.is_open()) {
        // maka akan dibuat variabel yang sama dengan apa yang ada
        // di struct sepatu, ini nantinya akan digunakan oleh fungsi
        // getline untuk membaca data data apa saja untuk setiap barisnya

        string _ID          ,
               _Merek       ,   // Merek dari sepatu
               _kategori    ,   // Kategori sepatu
               _Nama        ,   // Nama sepatunya
               _Jenis       ;   // Jenis (Sneakers, sport, dsb)
        int    _Harga       ,   // Harga sepatunya
               _stok        ;   // Stack buat jumlah stok

        // variabel temp untuk mengubah string angka ke int
        string temp;

        // fungsi membaca setiap baris pada file, menggunakan logika
        // while yaitu jika masih ada baris maka akan tetap berjalan
        // getline mengambil sumber file, menyimpan variabel, batas
        while (getline(fileSepatu, _ID      ,   ',')) {
               getline(fileSepatu, _Merek   ,   ',');
               getline(fileSepatu, _kategori,   ',');
               getline(fileSepatu, _Nama    ,   ',');
               getline(fileSepatu, _Jenis   ,   ',');
               getline(fileSepatu, temp     ,   ','); _Harga = stoi(temp); //mengubah string to int
               getline(fileSepatu, temp            ); _stok  = stoi(temp); //mengubah string to int


               // memasukkan data yang sudah didapat dari getline ke struct
               // sepatu sesuai dengan iterator jumlah sepatu yang ada, karena
               // pada awal tadi jumlah_sepatu masih 0 maka akan memasukkan
               // pada index pertama yaitu 0, jika kode sudah sampai bawah
               // maka iterator jumlah sepatu akan dinaikkan satu sehingga
               // untuk looping while kedepannya akan berlanjut index ke kedua,
               // tiga, empat, dst sampai jumlah baris habis
               sepatu[jumlahSepatu].ID          =   _ID      ;
               sepatu[jumlahSepatu].Merek       =   _Merek   ;
               sepatu[jumlahSepatu].kategori    =   _kategori;
               sepatu[jumlahSepatu].Nama        =   _Nama    ;
               sepatu[jumlahSepatu].Jenis       =   _Jenis   ;
               sepatu[jumlahSepatu].Harga       =   _Harga   ;
               sepatu[jumlahSepatu].stok.jumlah =   _stok    ;
               // naikkan iterator
               jumlahSepatu++;
        }
        // tutup file sepatu
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





// fungsi ini digunakan untuk menampilkan halaman profil
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
        cout << "+-------------------------------+\n"
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
        cout << "Pilihan Anda: "; cin >> pil;
            cin.ignore();

            switch (pil) {
                case 1:

                break;
                case 2:

                break;

                case 3:
                    M_KATALOG();
                break;

                case 4:
                    M_PENCARIAN();
                break;

                case 5:
                    M_KERANJANG();
                break;

                case 6:
                    return;
                break;
            }
    } while (true);
}

#endif // DATABASE
