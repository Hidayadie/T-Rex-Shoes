#ifndef ADMIN_H
#define ADMIN_H

#include "../Database/database.h"
#include "../Database/datauser.h"

void EditKatalog()  ,
     _K_APrint()    ,
     _K_Tambah()    ,
     _K_Edit()      ,
     _K_Hapus()     ,
     EditUser()     ,
     _U_Tambah()    ,
     _U_Edit()      ,
     _U_Hapus()     ;


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
                    EditKatalog();
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

void EditKatalog() {
    while (true) {
        bersihkanLayar();
        cout << "+-------------------------------------+\n"
             << "|             EDIT KATALOG            |\n"
             << "+-------------------------------------+\n"
             << "| Edit Nama, Jumlah dan stok sepatu   |\n"
             << "| Melalui menu ini, pilih salah satu  |\n"
             << "+-------------------------------------+\n"
             << "| 1. Tampilkan Katalog                |\n"
             << "| 2. Tambahkan Sepatu                 |\n"
             << "| 3. Edit Sepatu                      |\n"
             << "| 4. Hapus Sepatu                     |\n"
             << "| 5. Kembali                          |\n"
             << "|                                     |\n"
             << "+-------------------------------------+\n"
             << "pilih: "; cin >> pil;
             cin.ignore();
             switch (pil) {
                case 1:
                    _K_APrint();
                break;

                case 2:
                    _K_Tambah();
                break;

                case 3:
                    bersihkanLayar();
                    cout << "Gunakan menu 1 jika anda lupa ID sepatu\n";
                    _K_Edit();
                break;

                case 4:

                break;
                case 5:
                    return;
                break;

             }
    }
}

void _K_APrint() {

    bersihkanLayar();
    _K_Print(1);
    cout << "1. Edit\n"
         << "2. Hapus\n"
         << "3. Urutkan\n"
         << "4. Kembali\n"
         << "-> "; cin >> pil;
    cin.ignore();
    switch (pil) {
        case 1:
            _K_Edit();
        break;

        case 2:
        break;
        case 3:
            bersihkanLayar();
            _K_Print(1);
            menuSort();
            bersihkanLayar();
            _K_APrint();
            return;
        break;
        case 4:

        break;
    }
}


void _K_Tambah() {
    string temp;
    int tempint;
    bersihkanLayar();
    cout << "Penambahan sepatu baru...\n"
         << "Masukkan ID    : "; getline(cin, temp);
         sepatu[jumlahSepatu].ID = temp;
    cout << "Masukkan Nama  : "; getline(cin, temp);
         sepatu[jumlahSepatu].Nama = temp;
    cout << "Masukkan Merek : "; getline(cin, temp);
         sepatu[jumlahSepatu].Merek = temp;
    cout << "Masukkan Jenis  : "; getline(cin, temp);
         sepatu[jumlahSepatu].Jenis = temp;
    cout << "Kategori: \n"
         << "1. Dewasa Laki-laki\n"
         << "2. Dewasa Perempuan\n"
         << "3. Anak-anak\n"
         << "-> "; cin >> tempint;
    cin.ignore();
    switch (tempint) {
        case 1:
            sepatu[jumlahSepatu].kategori = "Dewasa Laki-laki";
        break;

        case 2:
            sepatu[jumlahSepatu].kategori = "Dewasa Perempuan";
        break;

        case 3:
            sepatu[jumlahSepatu].kategori = "Anak-anak";
        break;
    }

    cout << "Masukkan Harga  : "; cin >> tempint;
    cin.ignore();
         sepatu[jumlahSepatu].Harga = tempint;
    cout << "Masukkan Stok   : "; cin >> tempint;
    cin.ignore();
         sepatu[jumlahSepatu].stok.jumlah = tempint;
    jumlahSepatu++;
    database_update();
    cout << "Sepatu berhasil ditambahkan...";
    getchar();
}



void _K_Edit() {
    string temp;
    int tempint;
    cout << "Masukkan id yang ingin diedit: ";
    getline(cin, temp);
    int ditemukan = Cari_ID(temp);
    if (ditemukan == -1) return;

    cout << "Apakah sepatu \"" << sepatu[ditemukan].Nama  << "\"\n"
         << "Dengan merek \"" << sepatu[ditemukan].Merek  << "\"\n"
         << "(Y/n): "; cin >> pilC;
    cin.ignore();

    if (pilC == 'Y' || pilC == 'y') {
        while (true) {

            bersihkanLayar();
            cout << "1. ID      : " << sepatu[ditemukan].ID << "\n"
                 << "2. Nama    : "<<sepatu[ditemukan].Nama << "\n"
                 << "3. Merek   : "<<sepatu[ditemukan].Merek << "\n"
                 << "4. Jenis   : "<<sepatu[ditemukan].Jenis << "\n"
                 << "5. Kategori: "<<sepatu[ditemukan].kategori << "\n"
                 << "6. Harga   : "<<sepatu[ditemukan].Harga << "\n"
                 << "7. Stok    : "<<sepatu[ditemukan].stok.jumlah << "\n";
            cout << "Apa yang ingin diedit?\n"
                 << "-> "; cin >> pil;
            cin.ignore();
            switch (pil) {
                case 1:
                    cout << "Masukkan ID baru: "; getline(cin, temp);
                    sepatu[ditemukan].ID = temp;
                break;
                case 2:
                    cout << "Masukkan Nama baru: "; getline(cin, temp);
                    sepatu[ditemukan].Nama = temp;
                break;
                case 3:
                    cout << "Masukkan Merek baru: "; getline(cin, temp);
                    sepatu[ditemukan].Merek = temp;
                break;
                case 4:
                    cout << "Masukkan Jenis baru: "; getline(cin, temp);
                    sepatu[ditemukan].Jenis = temp;
                break;
                case 5:
                    cout << "Masukkan Jenis Kategori baru...\n"
                         << "1. Dewasa Laki-laki\n"
                         << "2. Dewasa Perempuan\n"
                         << "3. Anak-anak\n"
                         << "-> "; cin >> tempint;
                    cin.ignore();
                    switch (tempint) {
                        case 1:
                            sepatu[ditemukan].kategori = "Dewasa Laki-laki";
                        break;

                        case 2:
                            sepatu[ditemukan].kategori = "Dewasa Perempuan";
                        break;

                        case 3:
                            sepatu[ditemukan].kategori = "Anak-anak";
                        break;
                    }

                break;
                case 6:
                    cout << "Masukkan Harga baru: "; cin >> tempint;
                    sepatu[ditemukan].Harga = tempint;
                    cin.ignore();
                break;
                case 7:
                    cout << "Masukkan Stok baru: "; cin >> tempint;
                    cin.ignore();
                    sepatu[ditemukan].stok.jumlah = tempint;
                break;

            }
        cout << "Apakah Anda masih ingin mengedit?\n"
             << "(Y/n): "; cin >> pilC;
        cin.ignore();
        if (pilC == 'n' || pilC == 'N') break;
        }

        database_update();
    }
}

void _K_Hapus() {
    cout << "PERINGATAN!!!\n"
         << "Penghapusan sepatu bersifat permanen\n"
         << "dan tidak bisa dilakukan pemulihan\n"
         << "apakah anda yakin? (Y/n): "; cin >>pilC;
    cin.ignore();
    if (pilC == 'Y' || pilC == 'y') {
        cout << "Pilih ID: ";
    }
}


#endif // ADMIN_H