#include "Database/database.h"
#include "Database/datauser.h"
#include "Source/katalog.h"
#include "Source/pencarian.h"
#include "Source/sorting.h"


using namespace std;

int main() {

    if (!datauser_read())
        return 1;
    if (!database_read())
        return 1;
    Login();
    cout << "DEBUG: "
         << jumlahSepatu << " Terimput...\n"
         << "Masuk sebagai "<<userSekarang.Nama <<" dengan status " <<userSekarang.Status;
    MAIN_PROGRAM();
}

void MAIN_PROGRAM() {

    getchar();
    bersihkanLayar();
    reset();
    if (userSekarang.Status == "Admin") {
        Admin();
    } else if (userSekarang.Status == "Member") {
        Member();
    }
}


