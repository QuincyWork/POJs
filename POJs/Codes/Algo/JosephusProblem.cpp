#include <gtest/gtest.h>
#include <vector>
using namespace std;

void JosephusCalc(int count, int m, vector<int>& value)
{
	int nCount = 0;
	int nPos = -1;
	int nIndex = 0;
	char* Status = new char[count];	//状态数组，0表示已经移除，1表示未移除

	memset(Status, 1, count * sizeof(char));
	value.clear();

	while (nCount < count)
	{
		nPos = (nPos+1) % count;
		nIndex += Status[nPos];

		if (nIndex == m)
		{
			value.push_back(nPos+1);

			Status[nPos] = 0;
			nCount++;
			nIndex = 0;
		}
	}
	
	delete[] Status;
}

void ShowResult(const vector<int>& Result)
{		
	for (int i=0; i<Result.size(); ++i)
	{
		if (i % 10 == 0)
			cout << endl;

		cout << Result[i] << " ";		
	}
}

TEST(Algo, tJosephusProblem)
{
	vector<int> Result;
	JosephusCalc(41,3,Result);
	ShowResult(Result);

	JosephusCalc(6,5,Result);
	ShowResult(Result);
}