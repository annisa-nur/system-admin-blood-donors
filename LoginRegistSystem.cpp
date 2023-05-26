#include <bits/stdc++.h>
#include "Homepage.h"
using namespace std;
bool c = true;

//--------------------Class untuk menyatukan login dan registrasi
class login {
    public:
        void Login();
        void Registrasi();
};

void menuLogin();
void menuLoginProcess();


//-----------------------------------------fungsi login
void login::Login() {
    string count;
    string username, password, id, recordPass;
    cout << "Masukkan username dan password" << endl;
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    string loginHash = password;
    hash<string> mystdhash;
    int loginHashPassword = mystdhash(loginHash);

    ifstream input("data.txt");

    while (input >> id >> recordPass) {
        if(id == username && stoi(recordPass) == loginHashPassword ) {
            count = "1";
            clearScreen ();
        }
    }
    input.close();
    if (count == "1") {
        cout << username << "\nLogin successful!" << endl;
        homepage();
        homepageOperation();
    } else {
        clearScreen ();
        cout << "\nUsername atau password salah. Coba lagi." << endl;
        menuLogin();
    }
}

//-----------------------------------------Fungsi registrasi
void login::Registrasi() {
    string idAdmin, regAdmin, regPassword, regId, regPass, regCount;
    clearScreen ();
    cout << "Selamat Datang di Halaman Register Admin" << endl;
    cout << "\nMasukkan id admin: ";
    cin >> idAdmin;
    cout << "\nMasukkan username: ";
    cin >> regAdmin;
    cout << "\nMasukkan password: ";
    cin >> regPassword;

    string hashing = regPassword;
    hash<string> mystdhash;
    int hassPassword = mystdhash(hashing);

    ifstream input("data.txt");
    input.seekg(0, ios::end);

    if(input.tellg() == 0) {
        ofstream f1("data.txt", ios::app);
        f1 << regAdmin << ' ' << hassPassword << ' ' << endl;
        clearScreen ();
        cout << "Registrasi admin berhasil." << endl ;
        menuLogin();
        menuLoginProcess();
    } else {
        ifstream input("data.txt");
        while (input >> regId >> regPass) {
            if(regAdmin == regId) {
                int decision;
                cout << "Username sudah ada." << endl;
                cout << "Ketik 1 untuk mengulang registrasi." << endl;
                cin >> decision;

                if (decision == 1) {
                    Registrasi();
                } else {
                    cout << "Pilihan tidak sesuai. Kembali ke halaman registrasi." << endl;
                    Registrasi();
                }
            } else {
                regCount = "1";
            }
        }
    }

    if(regCount == "1"){
        ofstream f1("data.txt", ios::app);
        f1 << regAdmin << ' ' << hassPassword << ' ' << endl;
        clearScreen ();
        cout << "Regitrasi Admin berhasil." << endl;
        menuLogin();
        menuLoginProcess();
    }
}

//------------------------------Fungsi untuk menampilkan menu login
void menuLogin() {
    cout << "==================================================" << endl;
    cout << "Selamat Datang di Sistem Administrasi Donor Darah" << endl;
    cout << "=================================================="<< endl;
    cout << "1. Login Admin"<< endl;
    cout << "2. Register Admin"<< endl;
    cout << "3. Exit"<< endl;
    cout << "Masukkan pilihan: "<< endl;
}

//------------------------------Fungsi untuk memproses login
void menuLoginProcess() {
    while (c) {
        int userChoice;
        login adminLogin;
        cin >> userChoice;
        cout << endl;

        switch(userChoice) {
            case 1: adminLogin.Login();
                    a = false;
                    break;
            case 2: adminLogin.Registrasi();
                    menuLogin();
                    a = false;
                    break;
            case 3: exit(0);
                    a = false;
                    break;
            default:cout << "Pilihan tidak tersedia.";    
        }
    }
}

//------------------------------Fungsi utama
int main() {
    menuLogin();
    menuLoginProcess();
    return 0;
}
