//jadiin file ini ke module buat dipanggil di main login
//masukin module register pendonor, screening, keluhan pasca donor
//masukin module riwayat pendonor

#include <bits/stdc++.h>
#include "Module_Entry_dan_Riwayat.h"

bool a = true,b = true;

void homepage() {
    cout << "=========================================" << endl;
    cout << "          SELAMAT DATANG DI HOMEPAGE" << endl;
    cout << "=========================================" << endl;
    cout << endl;
    cout << "Pilih menu di bawah" << endl;
    cout << "1. Masukkan pendonor baru" << endl;
    cout << "2. Antrian pendonoran" << endl;
    cout << "3. Lihat data pendonor" << endl;
    cout << "4. Lihat Stok darah" << endl;
    cout << "5. Log Out" << endl;
    cout << "Masukkan pilihan: ";
}

void registerDonor() {
        registrasiPendonor(); // fungsi entry donor dan screening
}

void homepageOperation() {
    while (a) {
        int choice1, choice2;
        char answer;
        cin >> choice1;
        system("cls");
        switch(choice1) {
            case 1: //Fungsi paket Entry Pendonor, screening, keluhan
                    registerDonor();
                    cout << "Penambahan data pendonor telah berhasil." << endl;
                    //masukin if else: entry pendonor lagi atau kembali ke homepage
                    while (b) {
                        cout << "Apakah Anda ingin menambah pendonor baru lagi? (Y/T)" << endl;
                        cin >> answer;
                        if(answer == 'Y' || answer == 'y') {
                                registerDonor();
                                cout << "Penambahan data pendonor telah berhasil." << endl;
                        } else {
                                b = false;
                                homepage();
                                homepageOperation();
                        }
                    }
                    a = false;
                    break;

            case 2: //donor queue
                    int menuAntrian ;
                    do {
                        cout << "=== Antrian ===" << endl;
                        cout << "1. tampilkan antrian" << endl; 
                        cout << "2. panggil antrian" << endl;
                        cout << "3. Kembali" << endl;
                        cout << "Pilih menu: "<<endl;
                        cin >> menuAntrian;
                        clearScreen ();
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
                    } while (menuAntrian != 3);
                    homepage();
                    homepageOperation();
                    a = false;
                    break;

            case 3: //Fitur Riwayat pendonor
                    daftarPendonor();
                    cout << endl;
                    if (vectorAntrian.empty()) {
                        homepage();
                        homepageOperation();
                    } else {
                        historyDonorMenu();
                        htrDonorOperation();
                    }
                    a = false;
                    break;

            case 4: //blood stocks
                    tampilkanStokDarah();
                    homepage();
                    homepageOperation();
                    a = false;
                    break;

            case 5: //log out
                    exit(0);
                    a = false;
                    break;

            default: //balik ke homepage
                    cout << "Pilih menu yang tersedia dengan benar!"<< endl;
                    homepage();
                    homepageOperation();
                    break;
        }
        clearScreen ();
    }
}

void historyDonorMenu() {
    cout << "=========================================" << endl;
    cout << "              DATA PENDONOR" << endl;
    cout << "=========================================" << endl;
    cout << endl;
    cout << "Pilih dari menu dibawah:" << endl;
    cout << "1. Cari pendonor" << endl;
    cout << "2. Edit data pendonor" << endl;
    cout << "3. Hapus data pendonor" << endl;
    cout << "4. Kembali ke homepage" << endl;
    cout << "Your choice: ";
}

void htrDonorOperation() {
    while (a) {
        int choice2;
        cin >> choice2;
        clearScreen ();
        switch(choice2) {
            case 1: //Search Donor
                    cariPendonor();
                    cout << endl;
                    historyDonorMenu();
                    htrDonorOperation();
                    a = false;
                    break;

            case 2: //Edit Donor
                    editDataPendonor();
                    cout << endl;
                    historyDonorMenu();
                    htrDonorOperation();
                    a = false;
                    break;

            case 3: //Remove Donor
                    hapusPendonor();
                    cout << endl;
                    historyDonorMenu();
                    htrDonorOperation();
                    a = false;
                    break;

            case 4: //Back to homepage
                    homepage();
                    homepageOperation();
                    a = false;
                    break;
                    
            default: //balik ke homepage
                    cout << "Pilih menu yang tersedia dengan benar!"<< endl;
                    clearScreen ();
                    historyDonorMenu();
                    htrDonorOperation();
                    break;
        }
        clearScreen ();
    } 
    
}
