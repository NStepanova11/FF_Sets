#include "ParseTableRunner.h"

int main()
{
	ParseTableRunner ptr;
	ptr.ShowParseTable();

	ifstream fin(INPUT_FILE);
	string inputText;

	cout << "\n------Parsing------" << endl;
	while (getline(fin, inputText))
	{
		cout << setw(15) << left << inputText;// << endl;
		if (inputText != FINAL_CHAR)
			inputText.append(FINAL_CHAR);
		vector <int> st;
		int cPointer = 1;
		cout << ptr.ProcessData(inputText, cPointer, st) << " : " << inputText << endl;

	}
	system("pause");
	return 0;
}