#include "database.h"
#include "Katalog.h"
#include "Pencarian.h"
#include "Keranjang.h"
#include "Sorting.h"

#define bersih "\033[2J \033[1;1H"


using namespace std;


int main() {
    database();
    cout << jumlahSepatu << " Terimput...";
    Program();
}

void Program() {

    getchar();
    do {
    system("cls");
    reset();
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
        << "+-------------------------------+\n"
        << "Pilihan Anda: "; cin >> pil;
        cin.ignore();

        switch (pil) {
            case 1:
                profil();
            break;
            case 2:
                __KATALOG();
            break;
            case 3:
                pencarian();
            break;
            case 4:
                __KERANJANG();
            break;
            case 5:
                return;
            break;
        }


    } while (true);
}


void profil() {
    system("cls");
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
