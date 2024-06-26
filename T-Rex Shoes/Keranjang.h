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

void __KERANJANG(),
     TambahKeranjang(Sepatu _sepatu),     // fungsi tambah node baru di head
     HapusPilihan(),              // fungsi hapus node dari head
     Checkout(),              // hapus semua node
     Print();                   // cetak semua isi node
int jumlah = 0;



void TambahKeranjang(Sepatu _sepatu) {
    newNode = new Node;     // pembuatan node baru,
	newNode->data = _sepatu;   // pemasukan data node baru
	newNode->next	= NULL; // dari parameter data, next
	newNode->prev	= NULL; // dan prev masih kosong (null)

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


    getchar();
}

void Checkout() {
    cout << "h";
}

void HapusPilihan() {
    int nomor;
    cout << bersih;
    Print();
    cout << "Berikan nomor Barang yang ingin dihapus\n"
         << "-> "; cin >> nomor;
         cin.ignore();
}


void Print() {
    int total = 0;
    cout << bersih
         << "+--------------------------------------------------------------+\n"
         << "|                            KERANJANG                         |\n"
         << "+----+-----------+--------------------+------------+-----------+\n"
         << "| No | Merek     | Nama               | Jenis      | Harga     |\n"
         << "+----+-----------+--------------------+------------+-----------+\n";

    	tumbal = head;
    if (head != NULL)
    {
        while (tumbal != NULL)
        {
             cout << "| "
                 << setw(3) << tumbal->data.ID     << "| "
                 << setw(10) << tumbal->data.Merek  << "| "
                 << setw(19)<< tumbal->data.Nama   << "| "
                 << setw(11)<< tumbal->data.Jenis  << "| "
                 << setw(10) << tumbal->data.Harga  << "|\n";
                 total += tumbal->data.Harga;
            tumbal = tumbal->next;
        }
    }
    cout << "+----+-----------+--------------------+------------+-----------+\n"
         << "|                                         TOTAL    | Rp"<<setw(8)<< left << total<<"|\n"
         << "+--------------------------------------------------+-----------+\n";
}

#endif // KERANJANG_H
