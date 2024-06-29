#include "Database/database.h"
#include "Source/katalog.h"
#include "Source/pencarian.h"
#include "Source/sorting.h"

using namespace std;

int main() {
    string nama, pass;
    cout << "Silahkan Login terlebih dahulu\n"
         << "Ketik 0 jika Anda belum memiliki akun"
         << "Nama: "; getline(cin, nama);
    if (nama == "0") {
        //register
    } else {
        cout << "Pass: "; getline(cin, pass);
        //login
    }

    if(database_read())
    cout << jumlahSepatu << " Terimput...";
    MAIN_PROGRAM();
}

void MAIN_PROGRAM() {

    getchar();
    do {
    bersihkanLayar();
    reset();
    member();
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


