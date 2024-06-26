#ifndef KERANJANG_H
#define KERANJANG_H

#include "database.h"

struct Node {
	int nomor;
	Sepatu data;
	Node *next,
         *prev;
};

Node *head,         // ujung kiri
     *tail,         // ujung kanan
     *tumbal,       // dipake buat mindah mindah
     *del,          // dipake buat nghapus
     *newNode,      // dipake buat mbuat node baru
     *setelah,      // dipake buat ngapus (kanannya)
     *sebelum;      // dipake buat ngapus (kirinya)

bool isEmpty() {
	return (head == NULL && tail == NULL);
}

int total = 0;
int jumlah = 0;
int nomor = 1;

void __KERANJANG(),
     TambahKeranjang(Sepatu _sepatu),     // fungsi tambah node baru di head
     HapusPilihan(),              // fungsi hapus node dari head
     Checkout(),              // hapus semua node
     Print();                   // cetak semua isi node




void TambahKeranjang(Sepatu _sepatu) {
    newNode = new Node;     // pembuatan node baru,
	newNode->data = _sepatu;   // pemasukan data node baru
	newNode->next	= NULL; // dari parameter data, next
	newNode->prev	= NULL; // dan prev masih kosong (null)
	newNode->nomor   = nomor;
	nomor++;

	if (isEmpty()) {        // Jika node sebelumnya ga ada,
		head	= newNode;  //
		head->next	= NULL;
		head->prev	= NULL;
		tail		= head;

	}
	else {
		newNode->next	= head;
		head->prev		= newNode;
		head 			= newNode;
	}
}






void __KERANJANG() {
    if (isEmpty()) {

        cout << "Keranjang anda masih kosong!!!";
        getchar();
        return;
    }
    Print();
    cout << "Diatas adalah Daftar Keranjang Anda,\n"
         << "1. Checkout Semua\n"
         << "2. Hapus Keranjang\n"
         << "3. Kembali\n"
         << "-> "; cin >> pil;
         cin.ignore();

         if (pil == 1) {
            Checkout();
         } else if (pil == 2) {
            HapusPilihan();
         } else if (pil == 3) {

         }


    //getchar();
}

void Checkout() {
    char pil;
    cout << "Anda akan Men-Checkout keseluruhan keranjang\n"
         << "Total keseluruhan yang harus dibayar Rp " << total
         << "\nCheckout? (y/n): "; cin >> pil;
    cin.ignore();
    if (pil == 'Y' || pil == 'y') {
        cout << "Terimakasih sudah berbelanja..";
        if (isEmpty()) {
        cout << "kosong";
        }
        else {
            tumbal = head;
            while (tumbal != NULL) {
                setelah = tumbal;
                tumbal = tumbal->next;
                delete setelah;

            }
            jumlah = 0;
            head = NULL;
            tail = NULL;

        }
        total = 0;
        nomor = 1;
    } else if (pil == 'n' || pil == 'N') {

    }
}

void HapusPilihan() {
    int _nomor;
    system("cls");
    Print();
    cout << "Berikan nomor Barang yang ingin dihapus\n"
         << "-> "; cin >> _nomor;
         cin.ignore();
    if (isEmpty()) {
        cout << "Keranjang kosong!" << endl;
        return;
    }

    tumbal = head;
    while (tumbal != NULL && tumbal->nomor != _nomor) {
        tumbal = tumbal->next;
    }

    if (tumbal == NULL) {
        cout << "Nomor tidak ditemukan!" << endl;
        return;
    }

    if (tumbal == head && tumbal == tail) {
        head = tail = NULL;
    } else if (tumbal == head) {
        head = head->next;
        head->prev = NULL;
    } else if (tumbal == tail) {
        tail = tail->prev;
        tail->next = NULL;
    } else {
        tumbal->prev->next = tumbal->next;
        tumbal->next->prev = tumbal->prev;
    }

    delete tumbal;


    tumbal = tail;
    int newNomor = 1;
    total = 0;
    while (tumbal != NULL) {
        tumbal->nomor = newNomor++;
        total += tumbal->data.Harga;
        tumbal = tumbal->prev;
    }
}


void Print() {

    cout << bersih
         << "+--------------------------------------------------------------+\n"
         << "|                            KERANJANG                         |\n"
         << "+----+-----------+--------------------+------------+-----------+\n"
         << "| No | Merek     | Nama               | Jenis      | Harga     |\n"
         << "+----+-----------+--------------------+------------+-----------+\n";

    	tumbal = tail;
    if (tail != NULL)
    {
        while (tumbal != NULL)
        {
             cout << "| "
                 << setw(3) << tumbal->nomor     << "| "
                 << setw(10) << tumbal->data.Merek  << "| "
                 << setw(19)<< tumbal->data.Nama   << "| "
                 << setw(11)<< tumbal->data.Jenis  << "| "
                 << setw(10) << tumbal->data.Harga  << "|\n";
                 total += tumbal->data.Harga;
            tumbal = tumbal->prev;
        }
    }
    cout << "+----+-----------+--------------------+------------+-----------+\n"
         << "|                                         TOTAL    | Rp"<<setw(8)<< left << total<<"|\n"
         << "+--------------------------------------------------+-----------+\n";
}

#endif // KERANJANG_H
