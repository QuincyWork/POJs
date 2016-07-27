#include <gtest/gtest.h>
using namespace std;

vector<vector<int>> generate(int numRows)
{
	vector<vector<int>> results;
	vector<int> last;
	vector<int> line;

	for (int i=0; i<numRows; ++i)
	{
		for (int j=0; j <=i; ++j)
		{
			int v = 1;
			if (j > 0)
				v = last[j-1] + last[j];
			line.push_back(v);
		}

		results.push_back(line);
		last = line;
		last.push_back(0);
		line.clear();
	}

	return results;
}

// n个数选择m个数的组合数
int Combine(int n, int m)
{
	long long p = 1;
	for (int i=1; i<=m; ++i)
	{
		p = p * (n-i+1)/i;
	}

	return p;
}

vector<int> getRow(int rowIndex)
{
	vector<int> result;

	for (int i=0; i<=rowIndex; ++i)
	{
		result.push_back(Combine(rowIndex,i));
	}

	return result;
}

TEST(Pratices, tGenerate)
{
	vector<vector<int>> results;
	results = generate(0);
	results = generate(1);
	results = generate(5);
	results = generate(6);

	vector<int> line;
	line = getRow(0);
	line = getRow(1);
	line = getRow(4);
}