// Program Donor Darah kel.5 Struktur data
// Anggota kelompok : Annisa, Rama, Nabila

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <vector>

using namespace std;

// Struct untuk menyimpan data stok darah
struct structStokDarah
{
    int A = 0 ;
    int B = 0 ;
    int AB = 0 ;
    int O = 0 ;
};
//iniiasi stok darah
structStokDarah stokDarah ;
//fungsi untuk menambah stok darah
void tambahStok(string tipe) {
    if (tipe == "A") {
        stokDarah.A ++ ;
    }
    if (tipe == "B") {
        stokDarah.B ++ ;
    }
    if (tipe == "AB") {
        stokDarah.AB ++ ;
    }
    if (tipe == "O") {
        stokDarah.O ++ ;
    }

};
//fungsi untuk menampilkan stok darah
void tampilkanStokDarah(){
    cout << "Stok darah: " << endl;
    cout << "A: " << stokDarah.A<< endl;
    cout << "B: " << stokDarah.B << endl;
    cout << "AB: " << stokDarah.AB << endl;
    cout << "O: " << stokDarah.O << endl;
    cout << endl;
} ;


// Struct untuk menyimpan data antrian
struct dataAntrian {
    string nama;
    string tipe ;
    string* status;
};

// Deklarasi tipe data Queue untuk menyimpan Antrian
vector<dataAntrian> vectorAntrian;

// Fungsi untuk menambah elemen ke Antrian
void enqueueAntrian(string namaPendonor, string* statusPendonor, string tipeDarah) {
    dataAntrian antrianPendonor;
    antrianPendonor.nama = namaPendonor;
    antrianPendonor.status = statusPendonor;
    antrianPendonor.tipe = tipeDarah;
    vectorAntrian.push_back(antrianPendonor);

}

// Fungsi untuk menghapus elemen dari Antrian
void dequeueAntrian() {
    if (!vectorAntrian.empty()) {
        vectorAntrian.erase(vectorAntrian.begin());
    }
}

// Fungsi untuk menampilkan seluruh data dalam Antrian
void daftarAntrian() {
    if (vectorAntrian.empty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < vectorAntrian.size(); i++) {
            cout << vectorAntrian[i].nama << endl;
        }
    }
}
void changeStatus () {
    *vectorAntrian[0].status = "telah mendonor" ;
    tambahStok(vectorAntrian[0].tipe) ;
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
    cout <<endl<< "Pendonor " << pendonorBaru->nama << " telah berhasil terdaftar." << endl << endl;
    //menambahkan nama dan alamat status ke ANTRIAN ke antrian
    enqueueAntrian(pendonorBaru->nama, &pendonorBaru->status, pendonorBaru->tipeDarah) ;
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
} ;


// Fungsi utama program
int main() {
    int pilihan;
    do {
        cout << "=== PROGRAM PENDONOR DARAH ===" << endl;
        cout << "1. Registrasi Pendonor" << endl;
        cout << "2. Daftar Pendonor" << endl;
        cout << "3. Antrian" << endl;
        cout << "4. stok Darah" << endl ;
        cout << "5. keluar" << endl ;
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
                    cout << "Pilih menu: "<<endl;
                    cin >> menuAntrian;
                    switch (menuAntrian) {
                        case 1:
                            daftarAntrian();
                            break;
                        case 2:
                            changeStatus () ;
                            dequeueAntrian();

                            break;

                        default:
                            cout << "Menu tidak tersedia" << endl;
                            cout << endl;
                            break;
                        } 
                }while (menuAntrian != 3);
            case 4 :
                tampilkanStokDarah() ;
                break;
            case 5:
                cout << "Terima kasih" << endl;
                break;
            default:
                cout << "Menu tidak tersedia" << endl;
                cout << endl;
                break;
            } 
    }while (pilihan != 5);

    return 0;
}