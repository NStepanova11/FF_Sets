#pragma once
#include "Header.h"

class GrammarReader
{
private:
	Rules _rules;
	vector<vector<string>> ruleStrings;
	void ReadGrammarStringsFromFile();
	void ReadGrammarFromFile();
	
public:
	Rules GetRules();
	void ShowGrammar();

	vector<vector<string>> GetRuleStrings();
	void ShowRuleStrings();
};

