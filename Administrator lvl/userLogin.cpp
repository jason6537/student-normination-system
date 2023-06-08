#include <iostream>
#include <cctype>
#include<string>
#include <fstream>
using namespace std;

void userLogin();
void studentNomination(string ICnum);
void Clear();
bool isEmpty(std::ifstream& pFile);
void votingPage(string IC);
void studMenu(string IC);

struct student {
	string IC;
	string ID;
};

void userLogin()
{
	int i = 0;
	char studentid[12];
	string ICnum;
	student students[100];
	ifstream inStudent;
	inStudent.open("student.txt");
	bool checkMykad = false;
	bool checkStudID = false;

	while (!isEmpty(inStudent) && !inStudent.eof())
	{
		inStudent >> students[i].IC;
		inStudent >> students[i].ID;
		i++;
	}
	inStudent.close();

	do {
		cout << "Enter your MY Kad number (0 for back) :";
		cin >> ICnum;
		Clear();

		if (ICnum == "0") {
			system("cls");
			return;
		}
		
		for (int j = 0; j < i; j++) 
		{
			if (ICnum == students[j].IC) 
			{
				checkMykad = true;
				break;
			}
		}
		if (!checkMykad)
		{
			cout << "Invalid Mykad number! Please enter again " << endl;
		}
	} while (!checkMykad);

	do {
		cout << "Enter your Student ID :";
		cin >> studentid;
		Clear();

		if (isdigit(studentid[0]) && isdigit(studentid[1]))
			checkStudID = true;
		
		if (checkStudID)
		{
			for (int i = 2; i <= 4; i++)
			{
				if (!isalpha(studentid[i]))
				{
					checkStudID = false;
					break;
				}
				else
				{
					studentid[i]=toupper(studentid[i]);
				}
			}
		}
		if (checkStudID)
		{
			for (int i = 5; i <= 9; i++)
			{
				if (!isdigit(studentid[i]))
				{
					checkStudID = false;
					break;
				}
			}
		}
		if (checkStudID)
		{
			for (int k = 0; k < i; k++)
			{
				if (ICnum == students[k].IC)
				{
					if (studentid == students[k].ID)
					{
						checkStudID = true;
					}
					else
					{
						checkStudID = false;
					}
					break;
				}
			}
		}
		if (!checkStudID)
		{
			cout << "Invalid Student ID! Please enter again " << endl;
		}
	} while (!checkStudID);
	system("cls");
	studMenu (ICnum);
}



void studMenu(string IC)
{
menu:
	int choice = 0;
	bool checkChoice = false;
	do
	{
		
		cout << "\n\t\t\t\t\t\tWelcome to the Menu! " << endl;
		cout << "\t\t\t\t-----------------------------------------------------" << endl << endl;
		cout << "\t\t\t\t\t\t1. Nomination Page " << endl;
		cout << "\t\t\t\t\t\t2. Voting Page " << endl;
		cout << "\t\t\t\t\t\t3. Exit " << endl << endl;
		cout << "\t\t\t\t\tEnter your number of choice : ";
		cin >> choice;

		if (cin.bad() || (choice != 1 && choice != 2 && choice != 3) ){

			cout << "\n\t\t\t\t\tInvalid choice. Please reenter " << endl << endl;
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
		studentNomination(IC);
		system("cls");
		goto menu;
	case 2:
		cout << endl;
		votingPage (IC);
		system("cls");
		goto menu;
	default:
		cout << "\nThank you and Have a nice day!" << endl;
		system("pause");
		return;
		
	}
}




	
	

