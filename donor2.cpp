// Program Donor Darah kel.5 Struktur data
// Anggota kelompok : Annisa, Rama, Nabila

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <vector>

using namespace std;


// Deklarasi tipe data Queue untuk menua Antrian
vector<string> Antrian;
// Fungsi untuk menambah elemen ke Antrian
void enqueueAntrian(string nama) {
    Antrian.push_back(nama);
}

// Fungsi untuk menghapus elemen dari Antrian
void dequeueAntrian() {
    if (!Antrian.empty()) {
        Antrian.erase(Antrian.begin());
    }
}

// Fungsi untuk menampilkan seluruh data dalam Aueue
void daftarAntrian() {
    if (Antrian.empty()) {
        cout << "Queue kosong" << endl;
    } else {
        for (int i = 0; i < Antrian.size(); i++) {
            cout << Antrian[i] << " ";
        }
        cout << endl;
    }
}
// Struktur data untuk menyimpan informasi pendonor darah
struct Pendonor {
    string nama;
    int umur;
    char jenisKelamin;
    string tipeDarah;
    string status;
    Pendonor* next;
};

// Inisialisasi pointer kepala linked list
Pendonor* head = NULL;

// Fungsi untuk menambahkan pendonor ke linked list
void registrasiPendonor() {
    Pendonor* pendonorBaru = new Pendonor;
    cout << "Masukkan data pendonor:" << endl;
    cout << "Nama: ";
    getline(cin >> ws, pendonorBaru->nama); //'ws' untuk mengabaikan whitespacepada awal baris
    cout << "Umur: ";
    cin >> pendonorBaru->umur;
    cout << "Jenis Kelamin (L/P): ";
    cin >> pendonorBaru->jenisKelamin;
    pendonorBaru->jenisKelamin = toupper(pendonorBaru->jenisKelamin); //toupper untuk membuat char menjadi huruf besar
    while (pendonorBaru->jenisKelamin != 'L' && pendonorBaru->jenisKelamin != 'P') {
        cout << "Jenis kelamin tidak valid. Masukkan ulang (L/P): ";
        cin >> pendonorBaru->jenisKelamin;
    }
    cout << "Tipe Darah (A/B/AB/O): ";
    cin >> pendonorBaru->tipeDarah;
    transform(pendonorBaru->tipeDarah.begin(), pendonorBaru->tipeDarah.end(), pendonorBaru->tipeDarah.begin(), ::toupper); //transfor dan toupper untuk membuat setiap huruf dalam srting menjadi huruf besar
    while (pendonorBaru->tipeDarah != "A" && pendonorBaru->tipeDarah != "B" && pendonorBaru->tipeDarah != "AB" && pendonorBaru->tipeDarah != "O") {
        cout << "Tipe darah tidak valid. Masukkan ulang (A/B/AB/O): ";
        cin >> pendonorBaru->tipeDarah;
    }
    pendonorBaru->status = "belum mendonor";
    pendonorBaru->next = head;
    head = pendonorBaru;
    cout << "Pendonor " << pendonorBaru->nama << " telah berhasil terdaftar." << endl;
    //menambahkan nama ke antrian
    enqueueAntrian(pendonorBaru->nama) ;
}

// Fungsi untuk menampilkan daftar pendonor dari linked list
void daftarPendonor() {
    Pendonor* temp = head;
    if (temp == NULL) {
        cout << "Belum ada pendonor yang terdaftar." << endl;
        return;
    }
    cout << "Daftar Pendonor: " << endl;
    while (temp != NULL) {
        cout << "Nama: " << temp->nama << endl;
        cout << "Umur: " << temp->umur << endl;
        cout << "Jenis Kelamin: " << temp->jenisKelamin << endl;
        cout << "Tipe Darah: " << temp->tipeDarah << endl;
        cout << "Status: " << temp->status << endl;
        cout << endl;
        temp = temp->next;
    }
}

// Fungsi utama program
int main() {
    int pilihan;
    do {
        cout << "=== PROGRAM PENDONOR DARAH ===" << endl;
        cout << "1. Registrasi Pendonor" << endl;
        cout << "2. Daftar Pendonor" << endl;
        cout << "3. Antrian" << endl;
        cout << "4. keluar" << endl ;
        cout << "Pilih menu: ";
        cin >> pilihan;
        switch (pilihan) {
            case 1:
                registrasiPendonor();
                break;
            case 2:
                daftarPendonor();
                break;
            case 3: 
                int menuAntrian ;
                do {
                    cout << "=== Antrian ===" << endl;
                    cout << "1. tampilkan antrian" << endl;
                    cout << "2. panggil antrian" << endl;
                    cout << "3. Kembali" << endl;
                    cout << "Pilih menu: ";
                    cin >> menuAntrian;
                    switch (pilihan) {
                        case 1:
                            daftarAntrian();
                            break;
                        case 2:
                            dequeueAntrian();
                            break;

                        default:
                            cout << "Menu tidak tersedia" << endl;
                            cout << endl;
                            break;
                        } 
                }while (pilihan != 3);
            case 4:
                cout << "Terima kasih" << endl;
                break;
            default:
                cout << "Menu tidak tersedia" << endl;
                cout << endl;
                break;
            } 
    }while (pilihan != 4);

    return 0;
}