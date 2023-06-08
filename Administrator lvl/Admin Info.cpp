#include <iostream>
#include <fstream>
#include <string>
#include <conio.h> //to use getch()
 
using namespace std;
void Clear();
void registration();
void adminPage();
void statistics();
void resultScreen();
string takePasswdFromUser(char);

struct administrator
{
    string username;
    string password; 
};

void adminLogin()
{
    string password;
    administrator admins[3];
    ifstream adminFile;
    string user;
    string pass;
    bool checkUsername = false;
    bool checkPW = false;
    adminFile.open("admin.txt");
    int choice=0;

    for (int i = 0; i < 3; i++)
    {
        adminFile >> admins[i].username;
        adminFile >> admins[i].password;
    }
    adminFile.close();

    cout << "\n\t\t\t\t\tHello, Welcome to Admin Login Page!" << endl;
    cout << "\t\t\t\t---------------------------------------------------\n" << endl << endl;

    do {
        cout << "\t\t\t\tEnter your username(0 for back): ";
        cin >> user;
        Clear();

        if (user == "0") {
            system("cls");
            return;
        }
        
        for (administrator admin : admins) {
            if (admin.username == user) {
                checkUsername = true;
                break;
            }
        }
        if (!checkUsername)
            cout << "\n\t\t\t\tIncorrect Username! Please reenter \n" << endl;
    } while (!checkUsername);

    do {
        cout << "\t\t\t\tEnter your password: ";
        pass = takePasswdFromUser('*');
             
        for (administrator admin : admins) {
            if (admin.username == user) {
                if (admin.password == pass) {
                    checkPW = true;
                    break;
                }
            }
        }
        if (!checkPW)
            cout << "\n\t\t\t\tIncorrect Password. Please reenter \n" << endl;
    } while (!checkPW);
    system("cls");
    adminPage();
}

void adminPage()
{
menu:
    int choice=0;
    bool checkChoice = false;
    
 do {
    cout << "\n\t\t\t\t\tWelcome to the Administrator page! " << endl;
    cout << "\t\t\t\t---------------------------------------------------" << endl << endl;
    cout << "\t\t\t\t\t1. Student's Registration Page " << endl;
    cout << "\t\t\t\t\t2. Results Page " << endl;
    cout << "\t\t\t\t\t3. Statistics Page " << endl;
    cout << "\t\t\t\t\t4. Logout " << endl << endl;

    cout << "\t\t\t\tEnter your number of choice : ";
    cin >> choice;
    
        if (cin.bad() || choice < 1 || choice > 4 )
        {
            cout << "\nInvalid choice. Please reenter " << endl << endl;
        }
        else {
            checkChoice = true;
        }
        Clear();
    } while (!checkChoice);
    system("cls");

    switch (choice)
    {
    case 1:
        cout << endl;
        registration();
        system("cls");
       goto menu;
    case 2:
        cout << endl;
        resultScreen();
        system("cls");
        goto menu;
    case 3:
        cout << endl;
        statistics();
        system("cls");
        goto menu;
    default:
        cout << "\nLogging out..." << endl;
        system("pause");
        system("cls");
    }
}

void Clear() {
    cin.clear();
    cin.ignore(::numeric_limits<::streamsize> ::max(), '\n');
}

// Enumerator
enum IN {

    // 13 is ASCII for carriage
    // return
    IN_BACK = 8,
    IN_RET = 13

};

string takePasswdFromUser(char sp = '*') // Function that accepts the password
{
    // Stores the password
    string passwd = "";
    char ch_ipt;

    while (true) {  // Until condition is true

        ch_ipt = _getch();

        // if the ch_ipt
        if (ch_ipt == IN::IN_RET) {
            cout << endl;
            return passwd;
        }
        else if (ch_ipt == IN::IN_BACK
            && passwd.length() != 0) {
            passwd.pop_back();

            // Cout statement is very
            // important as it will erase
            // previously printed character
            cout << "\b \b";

            continue;
        }

        // Without using this, program
        // will crash as \b can't be
        // print in beginning of line
        else if (ch_ipt == IN::IN_BACK
            && passwd.length() == 0) {
            continue;
        }

        passwd.push_back(ch_ipt);
        cout << sp;
    }
}
