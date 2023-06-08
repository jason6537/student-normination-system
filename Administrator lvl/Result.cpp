#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

bool isEmpty(std::ifstream& pFile);
int getCand_totalVote(struct voting voters[100], int votersNum, int label);

struct candDetails{
	string IC;
	string ID;
	string program;
	int yr_ofStudy;
	int label;
	string nominateBy;
};

struct voting {
	string IC;
	int label=0;
};

struct result {
	int label;
	int totalVotes;
};


void resultScreen()
{
	int totalVotes = 0;
	int i = 0, j = 0, max = -1;
	candDetails candidates[5];
	voting voters[100];
	result candidateResult[5];
	int winner=0;
	ifstream inCandidates;
	ifstream voting;
	bool resultTie = false;
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

	cout << "\n\t\t\t\t\t==============*=====*=====*==============" << endl;
	cout << "\t\t\t\t\t\tWelcome to the Results Page ! " << endl;
	cout << "\t\t\t\t\t==============*=====*=====*==============" << endl;

	for (int m = 0; m < i; m++)
	{
		candidateResult[m].label = candidates[m].label;
		candidateResult[m].totalVotes = getCand_totalVote(voters, j, candidates[m].label);
		cout << "Total vote for Candidate " << candidates[m].label << ": " << candidateResult[m].totalVotes << endl;
	}	

	for (int k = 0; k < i; k++)
	{
		if (candidateResult[k].totalVotes > max)
		{
			max = candidateResult[k].totalVotes;
			winner = candidateResult[k].label;
			resultTie = false;
		}
		else if (candidateResult[k].totalVotes == max)
		{
			resultTie = true;
		}
	}
	if (resultTie)
	{
		cout << "The result is a tie! Another voting session will be held again" << endl;
	}
	else
	{
		cout << "The winner is candidate " << winner << endl;
	}
	system("pause");
}
	
int getCand_totalVote(struct voting voters[100], int votersNum, int label)
{
	int totalVotes = 0;

	for (int i = 0; i < votersNum; i++)
	{
		if (voters[i].label == label)
		{
			totalVotes++;
		}
	}
	return totalVotes;
}

