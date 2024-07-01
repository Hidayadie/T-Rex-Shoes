#ifndef ADMIN_H
#define ADMIN_H

#include "../Database/database.h"

void EditKatalog()  ,
     _K_Tambah()    ,
     _K_Edit()      ,
     _K_Hapus()     ,
     EditUser()     ,
     _U_Tambah()    ,
     _U_Edit()      ,
     _U_Hapus()     ;


void EditKatalog() {
    bersihkanLayar();
    cout << "+-------------------------------------+\n"
         << "|             EDIT KATALOG            |\n"
         << "+-------------------------------------+\n"
         << "|  Edit Nama, Jumlah dan stok sepatu  |\n"
         << "| Melalui menu ini, pilih salah satu  |\n"
         << "+-------------------------------------+\n"
         << "| 1. Tampilkan Katalog                |\n"
         << "| 2. Tambahkan Sepatu                 |\n"
         << "| 3. Edit Sepatu                      |\n"
         << "| 4. Hapus Sepatu                     |\n"
         << "|                                     |\n"
         << "+-------------------------------------+\n"
         << "pilih (0 kembali): ";
}


#endif // ADMIN_H
