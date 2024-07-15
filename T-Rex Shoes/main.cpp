#include "Database/database.h"
#include "Database/datauser.h"
#include "Source/katalog.h"
#include "Source/pencarian.h"
#include "Source/sorting.h"
#include "Source/Admin.h"

// Program T-Res shoes, adalah program manajemen
// sistem informasi penjualan sepatu Console User
// Interface, Program menyimpan database secara lokal
// menggunakan file txt sebagai database, program
// mampu membaca dan menulis dengan penggunaan lib
// fstream

// Program ini memakai file file header untuk menjalankan
// beberapa fungsi lainnya seperti pembacaan/tulis data
// katalog.h untuk menampilkan beberapa menu katalog
// pencarian untuk pencarian, sorting dsb...


// fungsi utama
int main() {

    // jika gagal membaca database -> program berhenti
    if (!datauser_read())
        return 1;
    // jika gagal membaca datauser -> program berhenti
    if (!database_read())
        return 1;

    // jika gagal masuk/login -> program berhenti
    if (!Login())
        return 1;


    // Menjalankan program T-Rex Shoes
    MAIN_PROGRAM();
}

// Fungsi menjalankan program utama, program ini
// hanya mengecek siapakah user kali ini, apakah
// admin, member, atau pedagang/penjual
void MAIN_PROGRAM() {
    // fungsi membersihkan layar digunakan untuk
    // membersihkan layar
    bersihkanLayar();

    // reset digunakan untuk mengurutkan ulang database sepatu
    // pengurutan dilakukan sesuai nomor id sepatu (awal baca)
    reset();

    // mengecek apa status user sekarang
    if (userSekarang.Status == "Admin")
        Admin();
    if (userSekarang.Status == "Member")
        Member();
}


