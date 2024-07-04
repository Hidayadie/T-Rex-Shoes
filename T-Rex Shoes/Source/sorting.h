#ifndef SORTING_H
#define SORTING_H

#include "../Database/database.h"

void sortAZ(),
     sortHarga(),
     sortMerek(),
     reset()    ;

int menuSort() {
    int pilSort;
    cout << "Apa yang ingin diurutkan?\n"
         << "1. Reset | 2. Merek | 3. Nama | 4. Harga\n"
         << "-> "; cin >> pilSort;
    cin.ignore();
    switch (pilSort) {
        case 1:
            reset();
            return 0;
        break;
        case 2:
            sortMerek();
            return 1;
        break;
        case 3:
            sortAZ();
            return 2;
        break;
        case 4:
            sortHarga();
            return 3;
        break;
    }
    return 0;
}


void sortAZ() {
    for (int i = 0; i < jumlahSepatu - 1; i++) {
        for (int j = 0; j < jumlahSepatu - i - 1; j++) {
            if (sepatu[j].Nama > sepatu[j + 1].Nama) {
                // Tukar data
                Sepatu temp = sepatu[j];
                sepatu[j] = sepatu[j + 1];
                sepatu[j + 1] = temp;
            }
        }
    }
}

void sortMerek() {
    for (int i = 0; i < jumlahSepatu - 1; i++) {
        for (int j = 0; j < jumlahSepatu - i - 1; j++) {
            if (sepatu[j].Merek > sepatu[j + 1].Merek) {
                // Tukar data
                Sepatu temp = sepatu[j];
                sepatu[j] = sepatu[j + 1];
                sepatu[j + 1] = temp;
            }
        }
    }
}

void sortHarga() {
    for (int i = 0; i < jumlahSepatu - 1; i++) {
        for (int j = 0; j < jumlahSepatu - i - 1; j++) {
            if (sepatu[j].Harga > sepatu[j + 1].Harga) {
                // Tukar data
                Sepatu temp = sepatu[j];
                sepatu[j] = sepatu[j + 1];
                sepatu[j + 1] = temp;
            }
        }
    }
}

void reset() {
    for (int i = 0; i < jumlahSepatu - 1; i++) {
        for (int j = 0; j < jumlahSepatu - i - 1; j++) {
            if (stoi(sepatu[j].ID) > stoi(sepatu[j + 1].ID)) {
                // Tukar data
                Sepatu temp = sepatu[j];
                sepatu[j] = sepatu[j + 1];
                sepatu[j + 1] = temp;
            }
        }
    }
}

void penghapusanSepatu(int in) {
    for (int i = in;i < jumlahSepatu; i++) {
        sepatu[i] = sepatu[i+1];
    }
    jumlahSepatu--;
}

void penghapusanUser(int in) {
    for (int i = in;i < jumlahUser; i++) {
        user[i] = user[i+1];
    }
    jumlahUser--;
}
#endif // SORTING_H
