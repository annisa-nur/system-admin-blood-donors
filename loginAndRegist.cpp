#include <bits/stdc++.h>
using namespace std;

void menuRegist () {
    cout << "Administrator Login Page" << endl;
    cout << "1. Sign In" << endl;
    cout << "2. Sign Up" << endl;
    cout << "Your choice: ";
}

struct Systems {
    char username[50];
    char password[50];
    void reg(int);
} admin[100];

void Systems::reg(int i) {
    int a=i;
    cout << "\nEnter username: ";
    cin >> username;
    cout << "\nEnter password: ";
    cin >> password;

    ofstream filout;
    filout.open("D:\\kuliah\\Dokumen sanur\\Works\\Kuliah IPB\\Semester 4\\Struktur Data\\Project\\registrationData.txt", ios::app | ios::binary);
    if(!filout) {
        cout << "\nFile cannot be opened";
    } else {
        cout << endl;
        filout.write((char *)&admin[i],sizeof(Systems));
        filout.close();
    }

    cout << "\nYou are now successfully registered!\n" << endl;
}

void login() {
    char usern, pwd;
    cout << "Enter your username: ";
    cin >> usern;
    cout << endl;
    cout << "Enter your password: ";
    cin >> pwd;
    cout << endl;

    ifstream filei;
    filei.open("D:\\kuliah\\Dokumen sanur\\Works\\Kuliah IPB\\Semester 4\\Struktur Data\\Project\\registrationData.txt", ios::app | ios::binary);
    if(!filei.is_open() && filei.fail()) {
        cout << "You are not registered. Please register before logging as an Admin";
        filei.close();
    } else {
        Systems admn2;
        filei.read((char *)&admn2, sizeof(admn2));
        if(usern == &admn2.username && pwd == &admn2.password) {
            cout << "\n You are successfully logged in";
            filei.close();
            //go to module homepage;
        } else {
            cout << " \n Wrong username or password! \nPlease try again.";
            cout << endl;
        }
    }
}

int main () {
    int choice0, i, a = true;
    string usern, line, pw;

    cout << "============================================" << endl;
    cout << "     Blood Donors System Administration" << endl;
    cout << "============================================" << endl;

    while(a) {
        menuRegist();
        cin >> choice0;
        switch (choice0) {
            case 1: //sign in
                cout << "Log In Page for Admin" << endl;
                login();
                a = false;
                break;

            case 2://sign up
                int t;
                cout << "Registration Page for Admin" << endl;
                cout << "How many admin do you want to register?";
                cin >> t;
                cout << endl;

                if(t>100) {
                    cout << "There are only 100 admins allowed in system" << endl;
                } else {
                    for (int i=0;i<t;i++) {
                        cout << "Enter Registration Details for admin " << i << ": " << endl;
                        admin[i].reg(i);
                    }
                }  
                a = false;
                break;
        
            default:
                cout << "Please, select the option above!";
                menuRegist();
                break;
        }
    }
}

