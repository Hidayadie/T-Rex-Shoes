#ifndef SORTING_H
#define SORTING_H

#include "../Database/database.h"

void sortAZ(),
     sortHarga(),
     sortMerek();

void menuSort() {
    int pilSort;
    cout << "Apa yang ingin diurutkan?\n"
         << "1. Merek | 2. Nama | 3. Harga\n"
         << "-> "; cin >> pilSort;
    cin.ignore();
    switch (pilSort) {
        case 1:
            sortMerek();
        break;
        case 2:
            sortAZ();
        break;
        case 3:
            sortHarga();
        break;
    }
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
