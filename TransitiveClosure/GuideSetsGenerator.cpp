#include "GuideSetsGenerator.h"

void GuideSetsGenerator::FindFirst()
{
	for (int i = 0; i < ruleStrings.size(); i++)
	{
		vector<string> fst;
		string firstInRule = ruleStrings[i][1];

		if (IsTerminal(firstInRule))
		{
			fst.push_back(firstInRule);
			_firsts[i]=fst;
			fst.clear();
		}
	}
}

void GuideSetsGenerator::FindFirstPlus()
{
	for (int i = 0; i < ruleStrings.size(); i++)
	{
		if (_firsts[i].empty() == true)
		{
			vector<string> fst;
			string startNoTerm = ruleStrings[i][0];
			string currentNoTerm = startNoTerm;
			GetFirstFor(startNoTerm, currentNoTerm, fst, i);
			_firsts[i] = fst;
		}
	}
}

void GuideSetsGenerator::GetFirstFor(string& startNoTerm, string& currentNoTerm, vector<string>& fst, int& indexOfStart)
{
	for (size_t i = 0; i < ruleStrings.size(); i++)
	{
		if (currentNoTerm == ruleStrings[i][0])
		{
			if (IsTerminal(ruleStrings[i][1]))
			{
				if (ruleStrings[indexOfStart][0]!= ruleStrings[i][0])
					fst.push_back(ruleStrings[i][1]);
			}
			else
			{
				currentNoTerm = ruleStrings[i][1];
				i = 0;
			}
		}
	}
}

void GuideSetsGenerator::ShowSet(string header, vector<vector<string>>& _set)
{
	cout << endl;
	cout << header << endl;
	for (size_t i = 0; i < _rules.leftParts.size(); i++)
	{
		cout << _rules.leftParts[i] << " : ";
		for (auto s : _set[i])
		{
			cout << s << " ";
		}
		cout << endl;
	}
}


bool GuideSetsGenerator::IsTerminal(string firstToken)
{
	if (find(_rules.leftParts.begin(), _rules.leftParts.end(), firstToken) == _rules.leftParts.end())
		return true;
	else return false;
}



void GuideSetsGenerator::FindFollow()
{
	for (int i = 0; i < _rules.leftParts.size(); i++)
	{
		vector<string> flw;
		if (i == 0)
			flw.push_back(FINAL_CHAR);
		
		for (int j = 0; j < _rules.rightParts.size(); j++)
		{
			auto nt_it = find(_rules.rightParts[j].begin(), _rules.rightParts[j].end(), _rules.leftParts[i]);
			if (nt_it != _rules.rightParts[j].end())
			{
				int nt_pos = distance(_rules.rightParts[j].begin(), nt_it);
				if (nt_pos != _rules.rightParts[j].size() - 1)
				{
					if (IsTerminal(_rules.rightParts[j][nt_pos+1]))
						flw.push_back(_rules.rightParts[j][nt_pos + 1]);
				}
			}
		}
		_follows[i] = flw;
		
	}
}

GuideSetsGenerator::GuideSetsGenerator()
{
	GrammarReader gr;

	_rules = gr.GetRules();
	gr.ShowGrammar();
	
	ruleStrings = gr.GetRuleStrings();
	gr.ShowRuleStrings();

	for (int i = 0; i < ruleStrings.size(); i++)
	{
		_firsts.push_back({});
		_follows.push_back({});
	}
}

vector<vector<string>> GuideSetsGenerator::GetFirst()
{
	FindFirst();
	FindFirstPlus();

	return _firsts;
}


vector<vector<string>> GuideSetsGenerator::GetFollow()
{
	FindFollow();

	return _follows;
}
