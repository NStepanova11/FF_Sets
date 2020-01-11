#include "TableGeneratorSLR.h"

int main()
{
	TableGeneratorSLR t_slr;
	t_slr.GenerateSlrTable();
	t_slr.ShowSlrTable();

	system("pause");
	return 0;
}
