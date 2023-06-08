#include <iostream>
#include <cctype>
#include<string>
#include <fstream>
using namespace std;

bool isEmpty(std::ifstream& pFile);
void Clear();
bool checkVotingDate();

struct voting {
	string IC;
	int label=0;
};

struct candDetails {
	string IC;
	string ID;
	string program;
	int yr_ofStudy = 0;
	int label = 0;
	string nominateBy;
};

struct VotingBind {
	string votedCandidate;
	string votedByStudent;
};


void votingPage(string IC)
{
	int i = 0, j = 0, vote;
	int choice = 0;
	candDetails candidates[5];
	voting voters[100];
	ifstream nominees;
	ifstream voting;
	ofstream votings;
	ofstream results;
	bool checkNum = false;

	nominees.open("nominees.txt");
	while (!isEmpty(nominees) && !nominees.eof())
	{
		nominees >> candidates[i].IC;
		nominees >> candidates[i].ID;
		nominees >> candidates[i].program;
		nominees >> candidates[i].yr_ofStudy;
		nominees >> candidates[i].label;
		nominees >> candidates[i].nominateBy;
		i++;
	}
	nominees.close();

	voting.open("voting.txt");
	while (!isEmpty(voting) && !voting.eof())
	{
		voting >> voters[j].IC;
		voting >> voters[j].label;
		j++;
	}
	voting.close();

	cout << "\n\t\t\t\t     -----------------------------------------------\n";
	cout << "\t\t\t\t\t\t       VOTING SESSION\n";
	cout << "\t\t\t\t     -----------------------------------------------\n\n";

	if ( i<5 || !checkVotingDate()) {
		cout << "\t\t\t\t\t ########################################" << endl;
		cout << "\t\t\t\t\t #                                      #" << endl;
		cout << "\t\t\t\t\t #       Voting session is closed!      #" << endl;
		cout << "\t\t\t\t\t #                                      #" << endl;
		cout << "\t\t\t\t\t ########################################" << endl << endl;
		system("pause");
		return;
	}
	for (int z = 0; z < j; z++) {
		if (voters[z].IC == IC)
		{
			cout << "\t\t\t\t\t\tYou have already voted once! " << endl;
			system("pause");
			return;
		}
	}
	do {
		cout << "\n\t\t\t\t\tBelow are the list of candidates " << endl;
		cout << "\t\t\t\t\t====================================\n";

		for (int k = 0; k < i; k++)
		{
			cout << "Candidate " << candidates[k].label << endl;
			cout << "------------" << endl;
			cout <<"Mykad number : " << candidates[k].IC << endl;
			cout <<"Student ID : "<< candidates[k].ID << endl;
			cout << "Program : "<< candidates[k].program << endl;
			cout << "Year of Study : " << candidates[k].yr_ofStudy << endl << endl;
		}

		cout << "\n* Once a vote is cast, no amendment or changing of vote is allowed. * " << endl;
		cout << "Who do you want to vote?(1-5) Enter any number out of the valid range of candidate numbers to abstain." <<endl;
		cin >> vote;

		if (cin.bad())
		{
			cout << "Please cast your vote by entering a correct number " << endl;
			checkNum = false;
		} 
		else
		{
			if (vote > 5 || vote < 1)
			{
				cout << "Your vote is abstained! " << endl;
			}
			voters[j].label=vote;
			voters[j].IC =IC;
			checkNum = true;
		}
		Clear();
	} while (!checkNum);
	

	votings.open("voting.txt");
	for (int y = 0; y <= j; y++)
	{
		votings << voters[y].IC<< endl;
		votings << voters[y].label;
		if (y < j)
		{
			votings << endl;
		}
	}
	votings.close();

	cout << "Successful vote! " << endl;
	system("pause");
}

bool checkVotingDate()
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


	if ((now_local.tm_year > endDate.tm_year || now_local.tm_mon > endDate.tm_mon || now_local.tm_mday > endDate.tm_mday) ||
		(now_local.tm_year < startDate.tm_year || now_local.tm_mon < startDate.tm_mon || now_local.tm_mday < startDate.tm_mday))
	{
		return false;
	}
	return true;
}
