//jadiin file ini ke module buat dipanggil di main login
#include <bits/stdc++.h>
//masukin module register pendonor, screening, keluhan pasca donor
//masukin module riwayat pendonor
using namespace std;

bool a = true;

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
    cout << "2. Blood Donors History" << endl;
    cout << "3. Log Out" << endl;
    cout << "Your choice: ";
}

void homepageOperation() {
    while (a) {
        int choice1, choice2;
        cin >> choice1;
        switch(choice1) {
            case 1: //Fitur Entry Pendonor


                    a = false;
                    break;

            case 2: //Fitur Riwayat pendonor
                    historyDonorMenu();
                    htrDonorOperation();
    
                    a = false;
                    break;

            case 3: //Log Out
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