#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

void Clear();
bool isEmpty(std::ifstream& pFile);
bool is_number(const std::string& s);

struct student {
	string IC;
	string ID;
};

void registration()
{
	int i = 0;
	char choice;
	char studentid[12];
	string IC;
	student students[100];
	ifstream inStudent;
	ofstream outStudent;
	inStudent.open("student.txt");
	bool checkMykad = false;
	bool checkStudID = false;

	while (!isEmpty(inStudent)&&!inStudent.eof()) 
	{
		inStudent >> students[i].IC;
		inStudent >> students[i].ID;
		i++;
	}
	inStudent.close();

	cout << "\n\t\t\t\t\t----------------------------------------\n";
	cout << "\t\t\t\t\t\tSTUDENT REGISTRATION PAGE\n";
	cout << "\t\t\t\t\t----------------------------------------\n" << endl;
	do 
	{
		checkMykad = false;
		checkStudID = false;
		do 
		{
			cout << "\t\t\t\tEnter Mykad Number (0 for back): " ;
			cin >> students[i].IC;
			Clear();

			if (students[i].IC == "0") 
			{
			system("cls");
			return;
			}

			for (int j = 0; j < i; j++)
			{
				if (is_number(students[i].IC) && students[i].IC.length()==12)
				{
				checkMykad = true;
				break;
				}
			}
			if (!checkMykad)
			{
			cout << "\n\t\t\t\tInvalid Mykad number! Please enter again " << endl;
			}
		} while (!checkMykad);

		do
		{
			cout << "\t\t\t\tEnter student ID : ";
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
			
			if (!checkStudID)
			{
				cout << "\n\t\t\t\tInvalid Student ID! Please enter again " << endl;
			}
			else
			{
				students[i].ID = studentid;
			}
		} while (!checkStudID);

	
		cout << "\n\t\t\t\tSuccessful registration! Do you want to register another student? (Y/N) ";
		do
		{
			cin >> choice;
			Clear();

			if (toupper(choice) != 'Y' && toupper(choice) != 'N')
			{
				cout << "\t\t\t\tInvalid choice. Please reenter! (Y/N) ";
			}

		} while (toupper(choice) != 'Y' && toupper(choice) != 'N');

		i++;
	} while (toupper(choice) =='Y');

	outStudent.open("student.txt");
	for (int y = 0; y < i; y++)
	{
		outStudent << students[y].IC << endl;
		outStudent << students[y].ID;
		if (y + 1 < i) {
			outStudent << endl;
		}
	}
	outStudent.close();
	system("cls");
}

bool isEmpty(std::ifstream& pFile)
{
	return pFile.peek() == std::ifstream::traits_type::eof();
}

bool is_number(const std::string& s)
{
	return !s.empty() && std::find_if(s.begin(),
		s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}