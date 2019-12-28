#include "Header.h"
#include "GrammarReader.h"

class GuideSetsGenerator
{
private:

	Rules _rules;
	vector<vector<string>> ruleStrings;
	vector<vector<string>> _firsts;
	vector<vector<string>> _follows;
	
	bool IsTerminal(string firstToken);
	//First
	void FindFirst();
	void FindFirstPlus();
	void GetFirstFor(string& startNoTerm, string& currentNoTerm, vector<string>& fst, int& indexOfStart);

	//Follow
	void FindFollow();
	void FindFollowPlus1();
	void FindFollowPlus2();
	void AddFirstOfNoTerminal(int index, string noTermOnRight, int idxOfRule);
	void AddFollowOfLeftPart(int index, string leftNoTerm, int idxOfRule);

public:
	GuideSetsGenerator();
	vector<vector<string>> GetFirst();
	vector<vector<string>> GetFollow();

	void ShowSet(string header, vector<vector<string>> &_set);
};

