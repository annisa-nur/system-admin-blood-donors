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
    if (vectorAntrian.empty()) {
        cout << "Antrian kosong" << endl;
    } else {
        *vectorAntrian[0].status = "telah mendonor" ;
        tambahStok(vectorAntrian[0].tipe) ;
    }
}
// Struktur data untuk menyimpan informasi pendonor darah
struct Pendonor {
    string nama;
    string id ;
    int umur;
    char jenisKelamin;
    string tipeDarah;
    string status;
    Pendonor* next;
};

// Inisialisasi pointer kepala linked list
Pendonor* head = NULL;
struct forID {
    int A = 0;
    int B = 0;
    int AB = 0 ;
    int O = 0 ;
};
forID idPendonor ;

struct Screening {
    string idS;
    int tekananDarah;
    int beratBadan;
    int tinggiBadan;
    int suhu;
    int kadarHB;
    string statusPengambilan;
    int lajuBerhenti;
    Screening* nextScr;
};

Screening* headScr = NULL;
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
    // menambakan id pendonor
    if (pendonorBaru->tipeDarah == "A") {
        pendonorBaru->id = "A" + to_string(++idPendonor.A);
    } else if (pendonorBaru->tipeDarah == "B") {
        pendonorBaru->id = "B" + to_string(++idPendonor.B);
    } else if (pendonorBaru->tipeDarah == "AB") {
        pendonorBaru->id = "AB" + to_string(++idPendonor.AB);
    } else if (pendonorBaru->tipeDarah == "O") {
        pendonorBaru->id = "O" + to_string(++idPendonor.O);
    }
    //menambahkan nama dan alamat status ke ANTRIAN ke antrian
    enqueueAntrian(pendonorBaru->nama, &pendonorBaru->status, pendonorBaru->tipeDarah) ;

    //fungsi screening kerjaan Sanur
    system("cls");
    Screening* screeningBaru = new Screening;

    cout << "Screening Awal Pendonor" << endl;
    cout << "Tekanan Darah (mmHg): ";
    cin >> screeningBaru -> tekananDarah;
    cout << "Berat Badan (kg): ";
    cin >> screeningBaru -> beratBadan;
    cout << "Tinggi Badan (cm): ";
    cin >> screeningBaru -> tinggiBadan;
    cout << "Suhu (Celcius): ";
    cin >> screeningBaru -> suhu;
    cout << "Kadar HB (mg/dL): ";
    cin >> screeningBaru -> kadarHB;
    cout << "Status Pengambilan (L/TL/TM): ";
    cin >> screeningBaru -> statusPengambilan;
    while (screeningBaru -> statusPengambilan != "L" && screeningBaru -> statusPengambilan != "TL" && screeningBaru -> statusPengambilan != "TM") {
        cout << "Pilihan status tidak sesuai. Masukkan ulang (L/TL/TM): ";
        cin >> screeningBaru -> statusPengambilan;
    }
    cout << "Stop (cc): ";
    cin >> screeningBaru -> lajuBerhenti;
    screeningBaru -> idS = pendonorBaru->id;
    screeningBaru -> nextScr = headScr;
    headScr = screeningBaru;
    system("cls");
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
        cout << "ID: " << temp->id << endl;
        cout << "Nama: " << temp->nama << endl;
        cout << "Umur: " << temp->umur << endl;
        cout << "Jenis Kelamin: " << temp->jenisKelamin << endl;
        cout << "Tipe Darah: " << temp->tipeDarah << endl;
        cout << "Status: " << temp->status << endl;
        cout << endl;
        temp = temp->next;
    }
};

void editDataPendonor() {
    string rubahId ;
    cout << "id: ";
    cin >> rubahId ;
    Pendonor* current = head;
    bool found = false;

    while (current != NULL && !found) {
        if (current->id == rubahId) {
            found = true;
        } else {
            current = current->next;
        }
    }

    if (found) {
        // melakukan perubahan data yang diinginkan
        cout << "Masukkan data baru untuk pendonor " << rubahId << ":" << endl;
        cout << "Nama: ";
        getline(cin >> ws, current->nama);
        cout << "Umur: ";
        cin >> current->umur;
        cout << "Jenis Kelamin (L/P): ";
        cin >> current->jenisKelamin;
        current->jenisKelamin = toupper(current->jenisKelamin);
        while (current->jenisKelamin != 'L' && current->jenisKelamin != 'P') {
            cout << "Jenis kelamin tidak valid. Masukkan ulang (L/P): ";
            cin >> current->jenisKelamin;
        }
        cout << "Tipe Darah (A/B/AB/O): ";
        getline(cin >> ws, current->tipeDarah);
        transform(current->tipeDarah.begin(), current->tipeDarah.end(), current->tipeDarah.begin(), ::toupper);
        while (current->tipeDarah != "A" && current->tipeDarah != "B" && current->tipeDarah != "AB" && current->tipeDarah != "O") {
            cout << "Tipe darah tidak valid. Masukkan ulang (A/B/AB/O): ";
            cin >> current->tipeDarah;
        }
        // cout << "Status (belum/telah mendonor): ";
        // cin >> current->status;
        // transform(current->status.begin(), current->status.end(), current->status.begin(), ::tolower);
        // while (current->status != "belum mendonor" && current->status != "telah mendonor") {
        //     cout << "Status tidak valid. Masukkan ulang (belum/telah mendonor): ";
        //     cin >> current->status;
        //     transform(current->status.begin(), current->status.end(), current->status.begin(), ::tolower);
        // }
        cout << "Data pendonor " << rubahId << " berhasil diubah." << endl;
    } else {
        cout << "Data pendonor " << rubahId << " tidak ditemukan." << endl;
    }
};

// Fungsi untuk menghapus data pendonor berdasarkan id
void hapusPendonor() {
    string hapusId ;
    cout << "id: ";
    cin >> hapusId ;
    Pendonor* curr = head;
    Pendonor* prev = NULL;
    Screening* currScr = headScr;
    Screening* prevScr = NULL;

    // Traverse linked list hingga menemukan data dengan id yang sesuai
    while (curr != NULL && curr->id != hapusId && currScr != NULL && currScr->idS != hapusId) {
        prev = curr;
        curr = curr->next;
        prevScr = currScr;
        currScr = currScr->nextScr;
    }

    // Jika id tidak ditemukan
    if (curr == NULL && currScr == NULL) {
        cout << "Data pendonor dengan id " << hapusId << " tidak ditemukan." << endl;
        return;
    }

    // Menghapus data dari linked list
    if (prev == NULL && prevScr == NULL) { // Data yang dihapus adalah data pertama
        head = curr->next;
        headScr = currScr->nextScr;
    } else {
        prev->next = curr->next;
        prevScr->nextScr = currScr->nextScr;
    }

    // Menghapus data dari antrian jika ada
    for (int i = 0; i < vectorAntrian.size(); i++) {
        if (vectorAntrian[i].nama == curr->nama) {
            vectorAntrian.erase(vectorAntrian.begin() + i);
            break;
        }
    }

    // Menghapus data dari linked list
    delete curr;
    delete currScr;

    cout << "Data pendonor dengan id " << hapusId << " berhasil dihapus." << endl;
}

// Fungsi untuk mencari pendonor berdasarkan nama atau id
void cariPendonor() {
    string cari ;
    cin >> cari ;
    Pendonor* temp = head;
    bool found = false;
    while (temp != NULL) {
        // Jika nama atau id ditemukan
        if (temp->nama == cari || temp->id == cari) {
            // Menampilkan informasi pendonor
            cout << "Nama: " << temp->nama << endl;
            cout << "ID: " << temp->id << endl;
            cout << "Umur: " << temp->umur << endl;
            cout << "Jenis Kelamin: " << temp->jenisKelamin << endl;
            cout << "Tipe Darah: " << temp->tipeDarah << endl;
            cout << "Status: " << temp->status << endl;
            found = true;
        }
        temp = temp->next;
    }
    if (!found) {
        cout << "Data tidak ditemukan." << endl;
    }
}

//kerjaannya Aba
void keluhanPascaDonor() {
    
}



