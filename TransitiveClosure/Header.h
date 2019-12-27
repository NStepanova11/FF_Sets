#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <iomanip>

using namespace std;

const string INPUT_FILE = "2_input.txt";
const string GRAMMAR_FILE = "7_grammar.txt";
const int START_RULE = 1;
const string EMPTY_CHAR = "#";
const string FINAL_CHAR = "$";

struct Rules {
	string startNoTerminal;
	int idxOfStartNoTerminal;
	vector<string> leftParts;
	vector<vector<string>> rightParts;
};