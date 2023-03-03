#include <bits/stdc++.h>
#include <conio.h>
using namespace std;

void login(void);
void loginConnected(void);
void adminAcc(void);
void adminAccCreated(void);

//creating a structure to store data of the admin
struct dataAdmin {
    char adminUsername[50];
    char adminName[50];
    char adminNumber[50];
};

struct passAdmin {
    char password[50];
};

void loginRegistMenu() {
    cout << "===============================================================" << endl;
    cout << "        WELCOME TO SYSTEM ADMINISTRATOR OF BLOOD DONORS" << endl;
    cout << "===============================================================" << endl;
    cout << "\nSelect the menu below: " << endl;
    cout << "1. Sign In" << endl;
    cout << "2. Sign Up" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter your choice: ";
}


int main() {
    int choice;
    bool a = true;
    loginRegistMenu();
    while(a) {
        cin >> choice;
        switch (choice) {
            case 1: //sign in
                    system("cls");
                    cout << "Please be caution that username and password are only 50 characters max for each.";
                    login();//fungsi login
                    a = false;
                    break;

            case 2: //sign up
                    system("cls");
                    adminAcc();//fungsi sign up
                    a = false;
                    break;

            case 3: // exit (done)
                    a = false;
                    exit(0);
                    break;

            default: //return to menu (done)
                    cout << "Invalid number of choice.";
                    loginRegistMenu();
                    break;


        }   
    }
}

void adminAcc(void) {
    char password[20];
    int passwordLength, seek = 0;
    char ch;
    struct dataAdmin dt1;
    struct passAdmin pa1;
    struct passAdmin pa2;

    fstream fout;
    fout.open("username.txt", ios::binary | ios::app);
    if (!fout) {
        cout << "File not created!";
    } else {
        cout << "/CREATE ACCOUNT FOR ADMIN";
        cout << "\nFull Name: ";
        cin >> dt1.adminName;

        cout << "\nUsername: ";
        cin >> dt1.adminUsername;

        cout << "\nAdmin Number: ";
        cin >> dt1.adminNumber;

        cout << "\nPassword: ";
        //taking password in the form of stars
        for (int i = 0;i < 50; i++) {
            ch = getch(); //ini ky fungsi cin juga cmn nerima spasi
            if (ch != 13) { //ini kenapa 13 ? apa karena ascii
                password[i] = ch; //password disimpen dari ch ke password[i]
                ch = '*'; //nanti return nya bentuk star
                cout << ch;
            } else {
                break;
            }
        }

    }

    fout.write(reinterpret_cast<char*>(&dt1), sizeof(dt1));
    fout.close();
    
    adminAccCreated();
}

void adminAccCreated(void) {
    char ch;
    system("cls");
    cout << "\nPlease wait... Your data is processing...";
    for (int i = 0; i<200000000; i++) { //knp 200 jt
        i++;
        i--;
    }

    cout << "\nAccount for admin created successfully..." << endl;
    cout << "Press enter to login";

    getch();
    login();
}

void login(void) {
    system("cls");
    char Username[50];
    char password[50];

    char ch;
    ofstream fout;
    ifstream fin;
    struct dataAdmin dt1;
    struct passAdmin dt2;

    fout.open("username.txt", ios::binary | ios::app);

    if (!fout) {
        cout << "File not created!"; 
    } else {
        cout << " ADMIN ACCOUNT SIGN IN ";
        cout << "\nUsername: ";
        cin >> Username;
        cout << "\nPassword: ";
        for (int i = 0;i < 50; i++) {
            ch = getch(); //ini ky fungsi cin juga cmn nerima spasi
            if (ch != 13) { //ini kenapa 13 ? apa karena ascii
                password[i] = ch; //password disimpen dari ch ke password[i]
                ch = '*'; //nanti return nya bentuk star
                cout << ch;
            } else {
                break;
            }
        }

        while (fin.read(reinterpret_cast<char*>(&dt1), sizeof(dt1))) {
            if (strcmp(Username, dt1.adminUsername) == 0) {
                loginConnected(); //SUSAH BGT INI BERMASALAH
            } else {
                cout << "Invalid username or password. Try again.";
                login();
            }
        }

    }
}

void loginConnected(void) {
    ofstream fout;
    struct dataAdmin dt1;
    system("cls");
    cout << "We are getting your account...";
    for (int i = 0; i < 20000; i++) {
        i++;
        i--;
    }

    cout << "\nLogin Successful...";
    cout << "\nDirecting to Homepage";
    cout << "\nPress enter to continue";

    getch();
    //masukin module homepage disini
}