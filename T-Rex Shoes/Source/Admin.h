#ifndef ADMIN_H
#define ADMIN_H

#include "../Database/database.h"
#include "../Database/datauser.h"

void EditKatalog()  ,
     _K_APrint(int pilihan, int halaman, int urutan)    ,
     _K_Tambah()    ,
     _K_Edit()      ,
     _K_Hapus()     ,
     EditUser()     ,
     _U_APrint()    ,
     _U_Tambah()    ,
     _U_Edit()      ,
     _U_Hapus()     ;


void Admin() {
    do {
        bersihkanLayar();
        cout << "+-------------------------------+\n"
             << "|         "<<BiruMuda<<"SELAMAT DATANG"<<RESET<<"        |\n"
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
                    EditUser();
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
             << "|             "<<BiruMuda<<"EDIT KATALOG"<<RESET<<"            |\n"
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
                    _K_APrint(1,1,1);
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
                    bersihkanLayar();
                    _K_Hapus();
                break;
                case 5:
                    return;
                break;

             }
    }
}

void _K_APrint(int pilihan, int halaman, int urutan) {
    int hal = halaman;
    int uru = urutan;
    bersihkanLayar();
    _K_Print(pilihan, hal, uru);

    cout << "|  [q] prev   [e] next   [s] sort   [E] edit   [h] hapus   [r] kembali  |\n"
         << "+-----------------------------------------------------------------------+\n"
         << "-> "; cin >> pilC;
    cin.ignore();
    switch (pilC) {
        case 'q':
        case 'Q':
            if (hal > 1) hal--;
            _K_Print(pilihan, hal, uru);
            _K_Menu(pilihan, hal, uru);
        break;
        case 'e':
            if (hal < 4) hal++;
            _K_Print(pilihan, hal, uru);
            _K_APrint(pilihan, hal, uru);
        break;
        case 'E':
            _K_Edit();
        break;

        case 'h':
        case 'H':
            _K_Hapus();
        break;
        case 's':
        case 'S':
            bersihkanLayar();
            _K_Print(pilihan, hal, uru);
            uru = menuSort();
            bersihkanLayar();
            _K_APrint(pilihan, hal, uru);
            return;
        break;
        case 'r':
            return;
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
    string temp;
    cout << "PERINGATAN!!!\n"
         << "Penghapusan sepatu bersifat permanen\n"
         << "dan tidak bisa dilakukan pemulihan\n"
         << "apakah anda yakin? (Y/n): "; cin >>pilC;
    cin.ignore();
    if (pilC == 'Y' || pilC == 'y') {
        cout << "Pilih ID: "; getline(cin, temp);
        if (Cari_ID(temp) != -1) {
            bersihkanLayar();
            cout << "Sepatu: " << sepatu[Cari_ID(temp)].Nama << ", dari " << sepatu[Cari_ID(temp)].Merek << "\n"
                 << "Akan dihapus, apakah data diatas sudah benar?\n"
                 << "(Y/n): "; cin >>pilC;
            cin.ignore();
            if (pilC == 'Y' || pilC == 'y') {
                penghapusanSepatu(Cari_ID(temp));
                cout << "Data berhasil dihapus...";
                getchar();
            }
        } else {
            cout << "Data tidak ditemukan...";
            getchar();
        }
    }
}



/*************************************************/


void EditUser() {
    while (true) {
        bersihkanLayar();
        cout << "+-------------------------------------+\n"
             << "|              "<<BiruMuda<<"EDIT USER"<<RESET<<"              |\n"
             << "+-------------------------------------+\n"
             << "| Edit Nama, Reset Password, ataupun  |\n"
             << "| ubah hak akses melalui menu ini     |\n"
             << "+-------------------------------------+\n"
             << "| 1. Tampilkan User                   |\n"
             << "| 2. Tambahkan User                   |\n"
             << "| 3. Edit Hak akses                   |\n"
             << "| 4. Hapus User                       |\n"
             << "| 5. Kembali                          |\n"
             << "|                                     |\n"
             << "+-------------------------------------+\n"
             << "pilih: "; cin >> pil;
             cin.ignore();
             switch (pil) {
                case 1:
                    _U_APrint();
                break;

                case 2:
                    bersihkanLayar();
                    _U_Tambah();
                break;

                case 3:
                    bersihkanLayar();
                    _U_Edit();
                break;

                case 4:
                    bersihkanLayar();
                    _U_Hapus();
                break;
                case 5:
                    return;
                break;

             }
    }
}


void _U_APrint() {
    bersihkanLayar();
    cout << "+----+--------------------------+-------------------+-------------+\n"
         << "| No | Nama                     | Password          | Akses       |\n"
         << "+----+--------------------------+-------------------+-------------+\n";
    for (int i = 0; i < jumlahUser; i++) {
        cout << "| " << left
             << setw(3) << i + 1 << "| "
             << (user[i].Status == "Admin" ? Hijau : RESET)
             << setw(25) << user[i].Nama        << RESET <<"| "
             << (user[i].Status == "Admin" ? Hijau : RESET)
             << setw(18) << user[i].Password    << RESET <<"| "
             << (user[i].Status == "Admin" ? Hijau : RESET)
             << setw(12) << user[i].Status      << RESET <<"|\n";
    }
    cout << "+----+--------------------------+-------------------+-------------+\n";
    cout << "1. Tambah\n"
         << "2. Edit Hak Akses\n"
         << "3. Hapus User\n"
         << "4. Kembali\n"
         << "-> "; cin >> pil;
    cin.ignore();
    switch (pil) {
        case 1:
            _U_Tambah();
        break;
        case 2:
            _U_Edit();
        break;
        case 3:
            _U_Hapus();
        break;
        case 4:
            return;
        break;
    }

}

void _U_Tambah() {
    string temp;
    cout << "Penambahan user...\n"
         << "Nama: "; getline(cin, temp);
    user[jumlahUser].Nama = temp;
    cout << "Password: "; getline(cin, temp);
    user[jumlahUser].Password = temp;
    cout << "Hak akses...\n"
         << "1. Admin\n"
         << "2. Member\n"
         << "-> "; cin >> pil;
    cin.ignore();
    user[jumlahUser].Status = ((pil == 1) ? "Admin" : "Member");
    cout << "Nama: \"" << user[jumlahUser].Nama << "\"\n"
         << "Pass: \"" << user[jumlahUser].Password <<"\"\n"
         << "Status: " << user[jumlahUser].Status << "\n"
         << "Apakah data diatas sudah benar?\n"
         << "(Y/n): "; cin >> pilC;
    cin.ignore();
    if (pilC == 'Y' || pilC == 'y') {
        jumlahUser++;
        cout << "User berhasil ditambah...";
        getchar();
    }
}

void _U_Edit() {
    string temp;
    cout << "Masukkan username: ";
    getline(cin, temp);
    cout << user[Cari_User(temp)].Nama << ", saat ini adalah " << user[Cari_User(temp)].Status << "\n"
         << "Ubah menjadi...\n"
         << "1. Admin\n"
         << "2. Member\n"
         << "-> "; cin >> pil;
    user[Cari_User(temp)].Status = ((pil == 1) ? "Admin" : "Member");
    cout << "Berhasil mengubah hak akses...";
    getchar();
}

void _U_Hapus() {
    string temp;
    cout << "PERINGATAN!!!\n"
         << "Penghapusan User bersifat permanen\n"
         << "dan tidak bisa dilakukan pemulihan\n"
         << "apakah anda yakin? (Y/n): "; cin >>pilC;
    cin.ignore();
    if (pilC == 'Y' || pilC == 'y') {
        cout << "Username: "; getline(cin, temp);
        if (temp != userSekarang.Nama) {
            if (Cari_User(temp) == -1)
                return;

            cout << user[Cari_User(temp)].Status << " " << user[Cari_User(temp)].Nama << "\n"
                 << "Akan dihapus, apakah Anda yakin?\n"
                 << "(Y/n): "; cin >> pilC;
            cin.ignore();
            if (pilC == 'Y' || pilC == 'y') {
                penghapusanUser(Cari_User(temp));
                datauser_update();
            }
        }
    }
}
#endif // ADMIN_H
