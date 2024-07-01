#include "Database/database.h"
#include "Database/datauser.h"
#include "Source/katalog.h"
#include "Source/pencarian.h"
#include "Source/sorting.h"

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

// penggunaan namespace std: cerr
using std::cerr;


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

    // Dibawah ini adalah fungsi debug, dipakai untuk mengetahui
    // berapa jumlah sepatu yang berhasil masuk ke program dan
    // juga siapa user sekarang sekaligus hak akses statusnya
    cerr << "DEBUG: "
         << jumlahSepatu << " Terimput...\n"
         << "Masuk sebagai "<<userSekarang.Nama <<" dengan status " <<userSekarang.Status;

    // Menjalankan program T-Rex Shoes
    MAIN_PROGRAM();
}

// Fungsi menjalankan program utama, program ini
// hanya mengecek siapakah user kali ini, apakah
// admin, member, atau pedagang/penjual
void MAIN_PROGRAM() {
    // fungsi getchar mirip seperti system("pause") yaitu
    // mengambil input dari keyboard untuk melanjutkan
    // program ke kode selanjutnya,
    // ini dipakai untuk menunggu user apakah sudah membaca
    // tulisan sebelumnya... Dikarenakan selanjutnya akan
    // dilakukan pembersihan layar dengan kode bersihkanLayar
    getchar();
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


