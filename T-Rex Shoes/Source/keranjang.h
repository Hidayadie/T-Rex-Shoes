#ifndef KERANJANG_H
#define KERANJANG_H

#include "../Database/database.h"



struct Node {
	int     nomor   ;
          //jml     ;
	Sepatu  data    ;
	Node    *next   ,
            *prev   ;
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

void TambahKeranjang(Sepatu _sepatu),     // fungsi tambah node baru di head
     HapusPilihan(),              // fungsi hapus node dari head
     Checkout(),              // hapus semua node
     Print(),                   // cetak semua isi node
     MetodeBayar();




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






void M_KERANJANG() {
    if (isEmpty()) {

        cout << Merah << "Keranjang anda masih kosong!!!" << RESET;
        getchar();
        return;
    }
    Print();
    cout << ((userSekarang.Bank == "" || userSekarang.Norek == "") ? Merah : Hijau)
         << ((userSekarang.Bank == "" || userSekarang.Norek == "")
         ? "Anda belum menambahkan Metode Pembayaran"
         : "Pembayaran dengan " + userSekarang.Bank + ": " + userSekarang.Norek);
    cout << RESET << "\n"
         << "Diatas adalah Daftar Keranjang Anda,\n"
         << "0. Kembali\n"
         << "1. Checkout Semua\n"
         << "2. Hapus Keranjang\n"
         << "3. Opsi Pembayaran\n"
         << "-> ";
    cin >> pil;
         cin.ignore();

         if (pil == 1) {
            Checkout();
         } else if (pil == 2) {
            HapusPilihan();
         } else if (pil == 3) {
            MetodeBayar();
         } else if (pil == 0) {
            return;
         }


    //getchar();
}

void Checkout() {
    char pil;
    if (userSekarang.Bank != "" && userSekarang.Norek != "") {
        cout << "Anda akan Men-Checkout keseluruhan keranjang\n"
             << "Total keseluruhan yang harus dibayar Rp " << total
             << "\nCheckout? (y/n): "; cin >> pil;
        cin.ignore();
        if (pil == 'Y' || pil == 'y') {

            cout << "Terimakasih sudah berbelanja..";
            tumbal = head;
            while (tumbal != NULL) {
                sepatu[Cari_ID(tumbal->data.ID)].stok.kondisi[sepatu[Cari_ID(tumbal->data.ID)].stok.jumlah] = false; //hehehehhe maap
                sepatu[Cari_ID(tumbal->data.ID)].stok.jumlah--;
                setelah = tumbal;
                tumbal = tumbal->next;
                delete setelah;
            }
            jumlah = 0;
            head = NULL;
            tail = NULL;

            total = 0;
            nomor = 1;
            getchar();
        } else if (pil == 'n' || pil == 'N') {
            M_KERANJANG();
            return;
        }
        database_update();
    } else {
        cout << Merah << "Silahkan lengkapi data pembayaran Anda terlebih dahulu..." << RESET;
        getchar();
    }
}

void HapusPilihan() {
    total = 0;
    int _nomor;
    bersihkanLayar();
    Print();
    cout << "Berikan nomor Barang yang ingin dihapus\n"
         << "-> "; cin >> _nomor;
         cin.ignore();

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
    if (!isEmpty()) {
        M_KERANJANG();
        return;
    }



}


void Print() {
    total = 0;
    bersihkanLayar();
    cout << "+--------------------------------------------------------------+\n"
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

    //total = 0;
}

void MetodeBayar() {
    string bank, norek;
    bersihkanLayar();
    cout << "Masukkan nama bank anda: "; getline(cin, bank);
    cout << "Nomor rekening: "; getline(cin, norek);
    cout << "Alamat pembayaran anda sudah diperbarui silahkan\n"
         << "cek email yang ada pada bank anda untuk verifikasi";
    getchar();
    userSekarang.Bank = bank;
    userSekarang.Norek = norek;

    user[Cari_User(userSekarang.Nama)].Bank = bank;
    user[Cari_User(userSekarang.Nama)].Norek = norek;

    datauser_update();
}
#endif // KERANJANG_H
