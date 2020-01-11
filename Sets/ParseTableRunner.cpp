#include "ParseTableRunner.h"

string ParseTableRunner::GetLexem(string& inputString)
{
	stringstream ss;
	ss << inputString[0];
	string lexem;
	ss >> lexem;

	return lexem;
}

bool ParseTableRunner::GetPointerFromStack(int& cPointer, vector<int>& st)
{
	if (st.empty() == false)
	{
		cPointer = st[st.size() - 1];
		st.pop_back();
	}
	else
		return false;
	return true;
}

ParseTableRunner::ParseTableRunner()
{
	_pt.CreateParseTable();
	_pTbl = _pt.GetParseTable();
}

void ParseTableRunner::ShowParseTable()
{
	cout << "------Parse Table------" << endl;
	_pt.ShowParseTable();
}

bool ParseTableRunner::ProcessData(string& inputString, int& cPointer, vector <int>& st)
{
	while (true)
	{
		
	/*	cout << cPointer<<". " << inputString << " [ ";
		if (st.empty() == false)
		{
			for (auto e : st)
				cout << e << ", ";
		}
		cout << " ] ";
	
	*/
		int currPointer = cPointer - 1;

		stringstream ss;
		ss << inputString[0];
		string lexem;
		ss >> lexem;

		CharType ct = _pTbl.at(currPointer).char_type;

		if (_pTbl.at(currPointer).final == true && st.empty() == true && lexem==FINAL_CHAR)
			return true;

		if (ct == LEFT_NO_TERM)
		{
			if (find(_pTbl.at(currPointer).guideSet.begin(), _pTbl.at(currPointer).guideSet.end(), lexem) != _pTbl.at(currPointer).guideSet.end())
				cPointer = _pTbl.at(currPointer).go_to;
			else
			{
				if (_pTbl.at(currPointer).err == true)
					return false;
				else
					cPointer = _pTbl.at(currPointer).next_alt;
			}
		}
		else if (ct == RIGHT_NO_TERM)
		{
			if (find(_pTbl.at(currPointer).guideSet.begin(), _pTbl.at(currPointer).guideSet.end(), lexem) != _pTbl.at(currPointer).guideSet.end())
			{
				cPointer = _pTbl.at(currPointer).go_to;

				if (_pTbl.at(currPointer).to_stack == true)
					st.push_back(currPointer + 2);
			}
			else
				return false;
		}
		else if (ct == TERMINAL)
		{
			if (find(_pTbl.at(currPointer).guideSet.begin(), _pTbl.at(currPointer).guideSet.end(), lexem) != _pTbl.at(currPointer).guideSet.end())
			{
				inputString.erase(inputString.begin());

				cPointer = _pTbl.at(currPointer).go_to;

				if (cPointer == NULL)
				{
					if (!GetPointerFromStack(cPointer,st))
						return false;
				}
			}
			else
				return false;
		}
		else if (ct == EMPTY)
		{
			if (find(_pTbl.at(currPointer).guideSet.begin(), _pTbl.at(currPointer).guideSet.end(), lexem) != _pTbl.at(currPointer).guideSet.end())
			{
				if (!GetPointerFromStack(cPointer, st))
					return false;
			}
			else
				return false;
		}

		//cout << " -> " << cPointer << endl;
	}
}


/*
bool ParseTableRunner::ProcessData(string& inputString, int& cPointer, vector <int>& st)
{
	while (true)
	{

		
			int currPointer = cPointer - 1;

			stringstream ss;
			ss << inputString[0];
			string lexem;
			ss >> lexem;

			if (_pTbl.at(currPointer).final == true && st.empty() == true && lexem == "$")
				return true;
			else
			{
				auto it = find(_pTbl.at(currPointer).guideSet.begin(), _pTbl.at(currPointer).guideSet.end(), lexem);
				if (it != _pTbl.at(currPointer).guideSet.end())
				{
					cPointer = _pTbl.at(currPointer).go_to;
					if (cPointer == NULL)
					{
						if (st.empty() == false)
						{
							cPointer = st[st.size() - 1];
							st.pop_back();
						}
						else
							return false;
					}



					if (_pTbl.at(currPointer).shift == true)
					{
						if (inputString.size() != 0)
						{
							inputString.erase(inputString.begin());
						}
					}

					if (_pTbl.at(currPointer).to_stack == true)
						st.push_back(currPointer + 2);
				}
				else
				{                                          
					if (_pTbl.at(currPointer).err == false)
						cPointer = _pTbl.at(currPointer).next_alt;
					else
						return false;
				}

			}
	}
}
*/


/*
bool ParseTableRunner::ProcessData(string& inputString, int& cPointer, vector <int>& st)
{
	while (true)
	{

		cout << " STR: " << inputString<< " CUR Pointer: " << cPointer << " STACK IS: ";
		if (st.empty() == false)
		{
			for (auto e : st)
				cout << e << ", ";
		}
		cout << endl;
		
		
		int currPointer = cPointer - 1;

		stringstream ss;
		ss << inputString[0];
		string lexem;
		ss >> lexem;

		if (_pTbl.at(currPointer).final == true && st.empty() == true && lexem == "$")
			return true;
		else
		{
			auto it = find(_pTbl.at(currPointer).guideSet.begin(), _pTbl.at(currPointer).guideSet.end(), lexem);
			if (it != _pTbl.at(currPointer).guideSet.end())
			{
				cPointer = _pTbl.at(currPointer).go_to;
				if (cPointer == NULL)
				{
					if (st.empty() == false)
					{
						cPointer = st[st.size() - 1];
						st.pop_back();
					}
					else
						return false;
				}

				if (_pTbl.at(currPointer).shift == true)
				{
					if (inputString.size() != 0)
					{
						inputString.erase(inputString.begin());
					}
				}

				if (_pTbl.at(currPointer).to_stack == true)
					st.push_back(currPointer + 2);
			}
			else
			{
				if (_pTbl.at(currPointer).err == false)
					cPointer = _pTbl.at(currPointer).next_alt;
				else return false;
			}

		}
	}
}
*/