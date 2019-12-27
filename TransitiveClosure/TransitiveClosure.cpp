#pragma once
#include "GuideSetsGenerator.h"

int main()
{
	GuideSetsGenerator gsg;
	vector<vector<string>> firsts = gsg.GetFirst();
	gsg.ShowSet("--FIRSTS--", firsts);

	vector<vector<string>> follows = gsg.GetFollow();
	gsg.ShowSet("--FOLLOWS--", follows);
	system("pause");
	return 0;
}