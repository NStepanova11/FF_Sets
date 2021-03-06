#include "GrammarReader.h"


void GrammarReader::ReadGrammarFromFile()
{
	ifstream fin(GRAMMAR_FILE);
	string line;
	stringstream ss;
	int lineNum = 0;

	while (getline(fin, line))
	{
		lineNum++; //������ ����������� ������

		ss << line;
		vector<string> ruleBody = {};
		string lexem = "";

		string leftNonTerminal;
		ss >> leftNonTerminal;

		//��������� ���������� ������ ���������� � ������ ������ � �����
		if (lineNum == START_RULE)
			_rules.startNoTerminal = leftNonTerminal;

		_rules.leftParts.push_back(leftNonTerminal);
		_rules.idxOfStartNoTerminal = _rules.leftParts.size() - 1;

		while (ss >> lexem)
		{
			if (lexem == "->")
				continue;
			else if (lexem == "|")
			{
				_rules.leftParts.push_back(leftNonTerminal);
				_rules.rightParts.push_back(ruleBody);
				ruleBody.clear();
			}
			else
				ruleBody.push_back(lexem);
		}
		_rules.rightParts.push_back(ruleBody); // ��. ��������� ������� ����������� �� ����� ��������� ������� ������� �� �����
		ss.clear();
	}
}

void GrammarReader::ReadGrammarStringsFromFile()
{
	ifstream fin(GRAMMAR_FILE);
	string line;
	stringstream ss;
	int lineNum = 0;

	while (getline(fin, line))
	{
		ss << line;
		vector<string> ruleBody = {};
		string lexem = "";
		string ruleString;

		string leftNonTerminal;
		ss >> leftNonTerminal;
		ruleBody.push_back(leftNonTerminal);

		while (ss >> lexem)
		{
			if (lexem == "->")
				continue;
			else if (lexem == "|")
			{
				ruleStrings.push_back(ruleBody);
				ruleBody.clear();
				ruleBody.push_back(leftNonTerminal);
			}
			else
				ruleBody.push_back(lexem);
		}
		ruleStrings.push_back(ruleBody); // ��. ��������� ������� ����������� �� ����� ��������� ������� ������� �� �����
		ss.clear();
	}
}

void GrammarReader::ShowRuleStrings()
{
	cout << "RULE STRINGS" << endl;
	for (auto rs : ruleStrings)
	{
		for (auto e : rs)
			cout << e << " ";
		cout << endl;
	}
}

vector<vector<string>> GrammarReader::GetRuleStrings()
{
	ReadGrammarStringsFromFile();
	return ruleStrings;
}

void GrammarReader::ShowGrammar()
{
	cout << "\n----- RULES -----" << endl;
	ofstream fout("parsed_grammar.txt");

	for (int i = 0; i < _rules.leftParts.size(); i++)
	{
		cout << _rules.leftParts[i] << " -> ";
		fout << _rules.leftParts[i] << " -> ";
		int n = 0;
		for (auto lexem : _rules.rightParts[i])
		{
			cout << " " << lexem;
			fout << " " << lexem;

		}
		cout << endl;
		fout << endl;
	}
}

Rules GrammarReader::GetRules()
{
	ReadGrammarFromFile();
	return _rules;
}