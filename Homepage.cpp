//jadiin file ini ke module buat dipanggil di main login
#include <bits/stdc++.h>
//masukin module register pendonor, screening, keluhan pasca donor
//masukin module riwayat pendonor
#include "Module_Entry_dan_Riwayat.h"
using namespace std;

bool a = true,b = true;

void homepage();
void homepageOperation();

void historyDonorMenu() {
    cout << "=========================================" << endl;
    cout << "              HISTORY OF DONORS" << endl;
    cout << "=========================================" << endl;
    cout << endl;
    cout << "Select from menu below:" << endl;
    cout << "1. Search Donor" << endl;
    cout << "2. Edit Donor" << endl;
    cout << "3. Remove Donor" << endl;
    cout << "4. Display Donors" << endl;
    cout << "5. Back to homepage" << endl;
    cout << "Your choice: ";
}

void htrDonorOperation() {
    while (a) {
        int choice2;
        cin >> choice2;
        switch(choice2) {
            case 1: //Search Donor


                    a = false;
                    break;

            case 2: //Edit Donor

                    a = false;
                    break;

            case 3: //Remove Donor

                    a = false;
                    break;

            case 4: //Display Donors
                    cout << endl;
                    daftarPendonor();
                    cout << endl;
                    historyDonorMenu();
                    htrDonorOperation();
                    a = false;
                    break;

            case 5: //Back to homepage
                    homepage();
                    homepageOperation();
                    a = false;
                    break;


            default: //balik ke homepage
                    cout << "Please appropriately select the menu above!"<< endl;
                    historyDonorMenu();
                    break;
        }
    }

}

void homepage() {
    cout << "=========================================" << endl;
    cout << "          WELCOME TO THE HOMEPAGE" << endl;
    cout << "=========================================" << endl;
    cout << endl;
    cout << "Select from menu below:" << endl;
    cout << "1. Entry Blood Donor" << endl;
    cout << "2. Donors Queue" << endl;
    cout << "3. Blood Donors History" << endl;
    cout << "4. Blood stocks" << endl;
    cout << "5. Log Out" << endl;
    cout << "Your choice: ";
}

void registerDonor() {
        entryDonor(); // fungsi entry donor
        screening();//fungsi screening
        keluhanPascaDonor();//fungsi keluhan pasca donor
}

void homepageOperation() {
    while (a) {
        int choice1, choice2;
        char answer;
        cin >> choice1;
        switch(choice1) {
            case 1: //Fungsi paket Entry Pendonor, screening, keluhan
                    registerDonor();
                    //masukin if else: entry pendonor lagi atau kembali ke homepage
                    while (b) {
                        cout << "Do you want to entry another donors? (Y/N)" << endl;
                        cin >> answer;
                        if(answer == 'Y' || answer == 'y') {
                                registerDonor();
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
                    historyDonorMenu();
                    htrDonorOperation();
                    a = false;
                    break;

            case 4: //blood stocks
                    a = false;
                    break;

            case 5: //log out
                    a = false;
                    break;

            default: //balik ke homepage
                    cout << "Please appropriately select the menu above!"<< endl;
                    homepage();
                    break;
        }
    }
}

int main() {
    homepage();
    homepageOperation();

    return 0;
}
