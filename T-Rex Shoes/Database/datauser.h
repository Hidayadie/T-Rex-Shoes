#ifndef DATAUSER_H
#define DATAUSER_H

struct User {
    string Nama            ,
           Password        ,
           Status          ;
};

User user[MAX_ISI],
     userSekarang ;
int jumlahUser = 0;


bool Registrasi()   ;
bool Login()        ;

bool datauser_read(),
     datauser_add(string nama, string pass) ,
     datauser_update();


bool Registrasi() {
    bersihkanLayar();
    do {
        string _Nama, _Pass, _Konfirm;
        cout << "Selamat datang\n"
             << "Masukkan identitas Anda\n"
             << "Nama: "; getline(cin, _Nama);
        cout << "Pass: "; getline(cin, _Pass);
        cout << "Konfirmasi Password: "; getline(cin, _Konfirm);
        if (_Pass == _Konfirm) {
            if(datauser_add(_Nama, _Pass)) {
                cout << "\nAkun berhasil dibuat\n"
                     << "Silahkan login ulang untuk masuk...";
                getchar();
                return Login();
            }
            break;
        } else {
            bersihkanLayar();
            cout << "Maaf password tidak sinkron, silahkan coba ulang\n";

        }
    } while (true);

    return false;
}
bool Login() {
    string nama, pass;
    bersihkanLayar();
    cout << "Silahkan Login terlebih dahulu\n"
         << "Ketik 0 jika Anda belum memiliki akun\n"
         << "Nama: "; getline(cin, nama);
    if (nama == "0") {
        return Registrasi();
    } else {
        cout << "Pass: "; getline(cin, pass);
        for (int i = 0; i < jumlahUser; i++) {
            if (nama == user[i].Nama) {
                if (pass == user[i].Password) {
                    userSekarang.Nama = user[i].Nama;
                    userSekarang.Status = user[i].Status;
                    return true;
                }
            }
        }
    }
    return false;

}


bool datauser_read() {
    ifstream fileUser("Datauser/datauser.txt");


    fileUser.open("Database/datauser.txt");
    if (fileUser.is_open()) {
        string nama     ,
           pass     ,
           status   ;
        while(getline(fileUser, nama, ',')) {
              getline(fileUser, pass, ',')  ;
              getline(fileUser, status)      ;

              user[jumlahUser].Nama = nama      ;
              user[jumlahUser].Password = pass  ;
              user[jumlahUser].Status = status  ;

              jumlahUser++;

        }
        return true;
    }
    fileUser.close();
    return true;
}

bool datauser_add(string nama, string pass) {
    ofstream fileUser;

    fileUser.open("Database/datauser.txt", ios::app);

    if (fileUser.is_open()) {
        fileUser << nama << ',' << pass << ',' << "Member" << "\n";
        user[jumlahUser].Nama = nama;
        user[jumlahUser].Password = pass;
        user[jumlahUser].Status = "Member";
        jumlahUser++;
    } else {
        fileUser.close();
        return false;
    }
    fileUser.close();
    return true;
}

bool datauser_update() {
    ofstream fileUser;

    fileUser.open("Database/datauser.txt");
    if (fileUser.is_open()) {
        for (int i = 0; i < jumlahUser; i++) {
            fileUser << user[i].Nama        << ','
                     << user[i].Password    << ','
                     << user[i].Status      << "\n";
        }
    } else {
        fileUser.close();
        return false;
    }
    fileUser.close();
    return true;
}
#endif // DATAUSER_H
