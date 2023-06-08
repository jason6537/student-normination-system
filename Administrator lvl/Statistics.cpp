#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

void totalNumOfVoters();
void totalStudDidntVote();
void percentStudentsVoted();
void totalVotesOfEachCand();
void breakdownByGender();
void Clear();
bool isEmpty(std::ifstream& pFile);
int getNumOfVoters();
int getNumofStudent();
int getCand_totalVote(struct voting voters[100], int votersNum, int label);
void displayDetailsofEachVote();
	
struct result {
	int label;
	int totalVotes;
};

struct voting {
	string IC;
	int label = 0;
};

struct student {
	string IC;
	string ID;
};

struct candDetails {
	string IC;
	string ID;
	string program;
	int yr_ofStudy;
	int label;
	string nominateBy;
};


void statistics()
{
statisticMenu:
	int choice = 0;
	bool checkChoice = false;

	
		cout << "\n\t\t\t\t=================*=====*=====*=================" << endl;
		cout << " \t\t\t\t\tWelcome to the Statistics Page ! " ;
		cout << "\n\t\t\t\t=================*=====*=====*=================" << endl << endl;
		cout << "\t\t\t\t1. Total number of voters " << endl;
		cout << "\t\t\t\t2. Total number of students who did not vote " << endl;
		cout << "\t\t\t\t3. Percentage of students who voted" << endl;
		cout << "\t\t\t\t4. Total votes obtained by each candidate" << endl;
		cout << "\t\t\t\t5. Breakdown of votes by gender " << endl;
		cout << "\t\t\t\t6. Display Details of Each Vote " << endl;
		cout << "\t\t\t\t7. Show All " << endl;
		cout << "\t\t\t\t8. Exit " << endl << endl;
		
	do{
		cout << "\t\t\t\tEnter your choice: ";
		cin >> choice;

		if (cin.bad() || choice < 1 || choice > 8)
		{
			cout << "\n\t\t\t\tInvalid choice. Please reenter " << endl << endl;
		}
		else 
		{
			checkChoice = true;
		}
		Clear();
	} while (!checkChoice);
	system("cls");

	switch (choice) {
	case 1:
		totalNumOfVoters();	
		break;
	case 2:
		totalStudDidntVote();	
		break;
	case 3:
		percentStudentsVoted();
		break;
	case 4: 
		totalVotesOfEachCand();	
		break;
	case 5:
		breakdownByGender();
		break;
	case 6:
		displayDetailsofEachVote();
		break;
	case 7:
		cout << "1. Total number of voters " << endl;
		totalNumOfVoters();
		cout << "2. Total number of students who did not vote " << endl;
		totalStudDidntVote();
		cout << "3. Percentage of students who voted" << endl;
		percentStudentsVoted();
		cout << "4. Total votes obtained by each candidate" << endl;
		totalVotesOfEachCand();
		cout << "5. Breakdown of votes by gender " << endl;
		breakdownByGender();
		break;
	default:
		return;
	}
	system("pause");
	system("cls");
	goto statisticMenu;
}

void totalNumOfVoters()
{
	cout << "The total number of voters : " << getNumOfVoters() << " voters" << endl << endl;
	
}
void totalStudDidntVote() {
	int totalVoters = getNumOfVoters();
	int totalStudents = getNumofStudent();

	cout << "The total of students that didn't vote : " << totalStudents - totalVoters << " students" << endl << endl;
	
}
void percentStudentsVoted() {
	int totalVoters = getNumOfVoters();
	int totalStudents = getNumofStudent();
	
	cout << "The percentage of students voted : " << fixed << setprecision(2)<< (float)totalVoters/(float)totalStudents *100 << " %" << endl << endl;
	
}
void totalVotesOfEachCand() {
	int i = 0, j = 0;
	result candidateResult[5];
	candDetails candidates[5];
	voting voters[100];
	ifstream inCandidates;
	ifstream voting;

	inCandidates.open("nominees.txt");
	while (!isEmpty(inCandidates) && !inCandidates.eof())
	{
		inCandidates >> candidates[i].IC;
		inCandidates >> candidates[i].ID;
		inCandidates >> candidates[i].program;
		inCandidates >> candidates[i].yr_ofStudy;
		inCandidates >> candidates[i].label;
		inCandidates >> candidates[i].nominateBy;
		i++;
	}
	inCandidates.close();

	voting.open("voting.txt");
	while (!isEmpty(voting) && !voting.eof())
	{
		voting >> voters[j].IC;
		voting >> voters[j].label;
		j++;
	}
	voting.close();

	for (int m = 0; m < i; m++)
	{
		candidateResult[m].label = candidates[m].label;
		candidateResult[m].totalVotes = getCand_totalVote(voters, j, candidates[m].label);
		cout << "Total vote for Candidate " << candidates[m].label << ": " << candidateResult[m].totalVotes << endl;
	}
	cout << endl;
}
void breakdownByGender()
{
	int i = 0, j = 0;
	candDetails candidates[5];
	voting voters[100];
	ifstream inCandidates;
	ifstream voting;

	inCandidates.open("nominees.txt");
	while (!isEmpty(inCandidates) && !inCandidates.eof())
	{
		inCandidates >> candidates[i].IC;
		inCandidates >> candidates[i].ID;
		inCandidates >> candidates[i].program;
		inCandidates >> candidates[i].yr_ofStudy;
		inCandidates >> candidates[i].label;
		inCandidates >> candidates[i].nominateBy;
		i++;
	}
	inCandidates.close();

	voting.open("voting.txt");
	while (!isEmpty(voting) && !voting.eof())
	{
		voting >> voters[j].IC;
		voting >> voters[j].label;
		j++;
	}
	voting.close();

	for (int m = 0; m < i; m++)
	{
		int female = 0, male = 0;
		for (int k = 0; k < j; k++) 
		{ 			
			if (voters[k].label == candidates[m].label) 
			{
				if (voters[k].IC.back() % 2 == 0)
				{
					female++;
				}
				else
				{
					male++; 
				}
			}
		}
	
		cout << "Total votes by female for Candidate " << candidates[m].label << " : " << female << endl;
		cout << "Total votes by male for Candidate " << candidates[m].label << " : " << male << endl << endl;
	}
	
}

int getNumOfVoters()
{
	int i = 0;
	voting voters[100];
	ifstream numOfVoters;

	numOfVoters.open("voting.txt");
	while (!isEmpty(numOfVoters) && !numOfVoters.eof())
	{
		numOfVoters >> voters[i].IC;
		numOfVoters >> voters[i].label;
		i++;
	}
	numOfVoters.close();

	return i;
}

int getNumofStudent()
{
	int i = 0;
	student students[100];
	ifstream numOfStudent;

	numOfStudent.open("student.txt");
	while (!isEmpty(numOfStudent) && !numOfStudent.eof())
	{
		numOfStudent >> students[i].IC;
		numOfStudent >> students[i].ID;
		i++;
	}
	numOfStudent.close();
	return i;
}

void displayDetailsofEachVote() {

	int i = 0, j = 0;
	candDetails candidates[5];
	voting voters[100];
	ifstream inCandidates;
	ifstream voting;

	inCandidates.open("nominees.txt");
	while (!isEmpty(inCandidates) && !inCandidates.eof())
	{
		inCandidates >> candidates[i].IC;
		inCandidates >> candidates[i].ID;
		inCandidates >> candidates[i].program;
		inCandidates >> candidates[i].yr_ofStudy;
		inCandidates >> candidates[i].label;
		inCandidates >> candidates[i].nominateBy;
		i++;
	}
	inCandidates.close();

	voting.open("voting.txt");
	while (!isEmpty(voting) && !voting.eof())
	{
		voting >> voters[j].IC;
		voting >> voters[j].label;
		j++;
	}
	voting.close();

	cout << "Summary of Each Votes from Each Voters to To Candidates" << endl;
	cout << "Voting Student ID  ->  Voted Student ID" << endl;
	for (int i = 0; i < j; i++) {
		cout << voters[i].IC << " -> " << candidates[voters[i].label].IC << "-> Label - " << voters[i].label << endl;
	}

}