#include <iostream>
#include <fstream>
using namespace std;

void adminLogin();
void userLogin();
void Clear();
void ShowLogo();

int main()
{
	ShowLogo();
	system("pause");
	system("cls");

mainMenu:
	int choice=0;
	bool checkChoice = false;

	do
	{
		cout << "\n\t\t\t\t\t\tWelcome ! " << endl;
		cout << "\t\t\t\t-------------------------------------------" << endl << endl;
		cout << "\t\t\t\t\t1. User Level" << endl;
		cout << "\t\t\t\t\t2. Administrator Level " << endl;
		cout << "\t\t\t\t\t3. Exit " << endl << endl;
		cout << "\t\t\t\tEnter your number of choice : ";	
		cin >> choice;

		if (cin.bad() || (choice != 1 && choice != 2 && choice != 3)) {
			
			cout << "\n\t\t\t\tInvalid choice. Please reenter " << endl << endl;
			system("pause");
			system("cls");

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
			userLogin();
			system("cls");
			goto mainMenu;
		case 2:
			cout << endl;
			adminLogin();
			system("cls");
			goto mainMenu;
		default:
			cout << "\nThank you and Have a nice day!" << endl;	
			exit(0);
		}
			
}

void ShowLogo() {
	cout << "\n\n\n\n\n\t\t++|___|--------------------------------Welcome to--------------------------------|___|++ " << endl;
	cout << "\t\t++ ___ \t\t\t\t\t\t\t\t\t\t  ___ ++" << endl;
	cout << " \t\t++|   |      ========     /\\\       =====    ||    ||  |\\      /|  ========  \t |   |++" << endl;
	cout << " \t\t++|   |         ||       //\\\\     ||   ||   ||    ||  ||\\    /||     ||     \t |   |++" << endl;
	cout << " \t\t++|___|         ||      //  \\\\    ||___||   ||    ||  || \\  / ||     ||     \t |___|++" << endl;
	cout << " \t\t                ||     //----\\\\   ||\\\\      ||    ||  ||  \\/  ||     ||    " <<endl;
	cout << " \t\t++ ___          ||    //      \\\\  || \\\\     ||____||  ||      ||     ||    \t  ___ ++" << endl ;
	cout << " \t\t++|   | \t\t\t\t\t\t\t\t\t |   |++"<< endl;
	cout << " \t\t++|   | \t\t\t\t\t\t\t\t\t |   |++"<< endl;
	cout << " \t\t++|___|--------------------------------------------------------------------------|___|++"<< endl;
	cout << " \t\t  "<< endl;
	cout << endl << "\t\t\t\t\t\t    E-voting session " << endl << endl;
}
	








	
