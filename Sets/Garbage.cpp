/*if (SetContainOnlyNoTerm(_firsts[start]))
{
	if (SetCanBeEmpty(_firsts[start]))
	{
		_haveEmptyAlternative.at(_rules.leftParts[start]) = true;
		string emptyElement = EMPTY_CHAR;
		AddElementToSet(_firsts[start], emptyElement);
	}
}

bool SetContainOnlyNoTerm(vector<string>& guideSet);
bool GuideSetGenerator::SetContainOnlyNoTerm(vector<string>& guideSet)
{
	for (auto &e : guideSet)
	{
		//если очередной символ является терминалом
		if (find(_rules.leftParts.begin(), _rules.leftParts.end(), e) == _rules.leftParts.end())
			return false;
	}
	return true;
}
bool SetCanBeEmpty(vector<string>& guideSet);//если все напр множество состоить из НТ которые мб пустыми
bool GuideSetGenerator::SetCanBeEmpty(vector<string>& guideSet)
{
	for (auto& e : guideSet)
	{
		if (_haveEmptyAlternative.at(e) == false)//Если у НТ нет пустой альтернативы, значит все множество не может быть пустым
			return false;
	}
	return true;
}
*/