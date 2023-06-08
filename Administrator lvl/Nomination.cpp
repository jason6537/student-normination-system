#include <iostream>
#include <cctype>
#include<string>
#include <fstream>
#include <ctime>
using namespace std;

void Clear();
bool isEmpty(std::ifstream& pFile);
bool checkNominationDate();

struct student {
	string IC;
	string ID;
};

struct candDetails {
	string IC;
	string ID;
	string program;
	int yr_ofStudy = 0;
	int label = 0;
	string nominateBy;
};

string removeSpaces(string str)
{
	str.erase(remove(str.begin(), str.end(), ' '), str.end());
	return str;
}

void studentNomination(string IC)
{
	int i = 0, k = 0;
	char choice, answer;
	string program;
	string ID;
	student students[100];
	candDetails candidates[5];
	char studentid[12];
	ifstream inStudent;
	ifstream inNominees;
	ofstream nominees;
	bool checkMykad = false;
	bool checkStudID = false;
	bool isMykadDuplicate = false;

	inStudent.open("student.txt");
	while (!isEmpty(inStudent) && !inStudent.eof())
	{
		inStudent >> students[i].IC;
		inStudent >> students[i].ID;
		i++;
	}
	inStudent.close();

	inNominees.open("nominees.txt");

	while (!isEmpty(inNominees) && !inNominees.eof())
	{
		inNominees >> candidates[k].IC;
		inNominees >> candidates[k].ID;
		inNominees >> candidates[k].program;
		inNominees >> candidates[k].yr_ofStudy;
		inNominees >> candidates[k].label;
		inNominees >> candidates[k].nominateBy;
		k++;
	}
	inNominees.close();

	cout << "\n\t\t\t\t---------------------------------------------------\n";
	cout << "\t\t\t\t\t\tSTUDENT NOMINATION\n";
	cout << "\t\t\t\t---------------------------------------------------\n" << endl;


	if (k == 5 || !checkNominationDate()) {
		cout << "\t\t\t\t     ########################################"  << endl;
		cout << "\t\t\t\t     #                                      #" << endl;
		cout << "\t\t\t\t     #         Nomination is closed!        #" << endl;
		cout << "\t\t\t\t     #                                      #" << endl;
		cout << "\t\t\t\t     ########################################" << endl << endl;
		system("pause");
		system("cls");
		return;
		
	}


	for (int z = 0; z < k; z++) {
		if (candidates[z].nominateBy == IC)
		{
			cout << "\t\t\t\t\tYou have already nominated once! " << endl; //check
			system("pause");
			return;
		}
	}

	cout << "\t\t\t\t  *one person can only nominate one student* \n\n";
	
	do
	{
		checkMykad = false;
		isMykadDuplicate = false;
		cout << "\n\t\tEnter MYKad number :";
		cin >> candidates[k].IC;
		Clear();

		for (int j = 0; j < i; j++)
		{
			if (candidates[k].IC == students[j].IC)
			{
				checkMykad = true;

				for (int m = 0; m < k; m++)
				{
					if (candidates[k].IC == candidates[m].IC)
					{
						isMykadDuplicate = true;
						break;
					}
				}
				break;
			}
		}
		if (!checkMykad)
		{
			cout << "\t\tInvalid Mykad number! Please enter again " << endl;
		
		}
		else if (checkMykad && isMykadDuplicate)
		{
			cout << "\t\tThis nominee has been nominated! Do you want to nominate again? (Y/N) ";
			do
			{
				cin >>choice;
				Clear();
				
				if (toupper(choice) != 'Y' && toupper(choice) != 'N')
				{
					cout << "\t\tInvalid choice. Please reenter! (Y/N) ";
				}
				
			} while (toupper(choice) != 'Y' && toupper(choice) != 'N');
			
		}

	} while (!checkMykad || (isMykadDuplicate && toupper(choice) == 'Y'));

	if (isMykadDuplicate && toupper(choice) == 'N')
	{
		nominees.open("nominees.txt");
		for (int y = 0; y < k; y++)
		{
			nominees << candidates[y].IC << endl;
			nominees << candidates[y].ID << endl;
			nominees << candidates[y].program << endl;
			nominees << candidates[y].yr_ofStudy << endl;
			nominees << candidates[y].label << endl;
			nominees << candidates[y].nominateBy;
			if (y + 1 < k) {
				nominees << endl;
			}
		}
		nominees.close();

		return;
	}

	do
	{
		cout << "\t\tEnter Student ID :";
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
					studentid[i] = toupper(studentid[i]);
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
			for (int j = 0; j < i; j++)
			{
				if (candidates[k].IC == students[j].IC)
				{
					if (studentid == students[j].ID)
					{
						checkStudID = true;
						candidates[k].ID = studentid;
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
			cout << "\t\tInvalid Student ID! Do you want to enter again?(Y/N) ";
			do
			{
				cin >> answer;
				Clear();

				if (toupper(answer) != 'Y' && toupper(answer) != 'N')
				{
					cout << "\t\tInvalid choice. Please reenter! (Y/N) ";
				}

			} while (toupper(answer) != 'Y' && toupper(answer) != 'N');

			
		}

	} while (!checkStudID && toupper(answer) == 'Y');

	if (!checkStudID && toupper(answer) == 'N')
	{
		nominees.open("nominees.txt");
		for (int y = 0; y < k; y++)
		{
			nominees << candidates[y].IC << endl;
			nominees << candidates[y].ID << endl;
			nominees << candidates[y].program << endl;
			nominees << candidates[y].yr_ofStudy << endl;
			nominees << candidates[y].label << endl;
			nominees << candidates[y].nominateBy;
			if (y + 1 < k) {
				nominees << endl;
			}
		}
		nominees.close();

		return;
	}


	cout << "\t\tEnter Program :";
	getline(cin, candidates[k].program);
	candidates[k].program = removeSpaces(candidates[k].program);

	cout << "\t\tEnter Year of Study :";
	cin >> candidates[k].yr_ofStudy;
	Clear();

	candidates[k].label = k + 1;
	candidates[k].nominateBy = IC;

	nominees.open("nominees.txt");
	for (int y = 0; y <= k; y++)
	{
		nominees << candidates[y].IC << endl;
		nominees << candidates[y].ID << endl;
		nominees << candidates[y].program << endl;
		nominees << candidates[y].yr_ofStudy << endl;
		nominees << candidates[y].label << endl;
		nominees << candidates[y].nominateBy;
		if (y < k) {
			nominees << endl;
		}
	}
	nominees.close();

	cout << "\n\t     ########################################" << endl;
	cout << "\t     #                                      #" << endl;
	cout << "\t     #        Successful nomination!        #" << endl;
	cout << "\t     #                                      #" << endl;
	cout << "\t     ########################################" << endl;
	system("pause");
}

bool checkNominationDate()
{
	tm startDate{ 0 };
	startDate.tm_mday = 26;
	startDate.tm_mon = 12;
	startDate.tm_year = 2022;

	tm endDate{ 0 };
	endDate.tm_mday = 30;
	endDate.tm_mon = 12;
	endDate.tm_year = 2022;

	time_t now = time(0);
	tm now_local;
	localtime_s(&now_local, &now);
	now_local.tm_year += 1900;
	now_local.tm_mon += 1;


	if( (now_local.tm_year > endDate.tm_year || now_local.tm_mon > endDate.tm_mon || now_local.tm_mday > endDate.tm_mday) ||
		(now_local.tm_year < startDate.tm_year || now_local.tm_mon < startDate.tm_mon || now_local.tm_mday < startDate.tm_mday)) 
	{
		return false;
	}
	return true;
}
