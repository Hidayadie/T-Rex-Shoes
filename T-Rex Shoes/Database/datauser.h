#ifndef DATAUSER_H
#define DATAUSER_H

struct User {
    string Nama            ,
           Password        ,
           Status          ;
};

void Registrasi() {
    do {
        string _Nama, _Pass, _Konfirm;
        bersihkanLayar();
        cout << "Selamat datang\n"
             << "Masukkan identitas Anda\n"
             << "Nama: "; getline(cin, _Nama);
        cout << "Pass: "; getline(cin, _Pass);
        cout << "Konfirmasi Password: "; getline(cin, _Konfirm);
        if (_Pass == _Konfirm) {
            break;

        }
    } while (true);
}

bool Masuk() {
    cout << "Silahkan Login terlebih dahulu\n"
         << "Ketik 0 jika Anda belum memiliki akun"
         << "Nama: "; getline(cin, nama);
    if (nama == "0") {
        Registrasi();
        break;
    } else {
        cout << "Pass: "; getline(cin, pass);
        //login
    }
}

bool datauser_read() {

}

bool datauser_add() {

}

bool datauser_update() {

}
#endif // DATAUSER_H
