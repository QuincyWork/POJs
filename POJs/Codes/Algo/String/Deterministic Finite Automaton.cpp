#include <gtest/gtest.h>
using namespace std;

const int ASIZE  = 53;
const char AlphaTbl[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ";

//
//	创建DFA状态转移表
//
void CreateDFATable(vector<vector<int>>& transTbl, const string& pattern)
{
	const int length = pattern.length();	
	
	// 设置二维表大小length+1 * ASIZE
	transTbl.assign(length+1,vector<int>(ASIZE,0));

	// 初始化二位数据
	for (int i=0; i < length; ++i)
	{
		for (int j=0; j < ASIZE; ++j)
		{			
			string newPattern(pattern.begin(),pattern.begin()+i);
			newPattern.push_back(AlphaTbl[j]);

			int k = i+1;
			while ( k > 0 && strncmp(pattern.c_str(),newPattern.c_str()+newPattern.length()-k,k) != 0)
			{
				--k;
			}

			if (k > 0)
			{
				transTbl[i][j] = k;
			}
		}
	}
}

//
//  Convert alpha char to index
//
int Convert(char value)
{
	int result = -1;
	if (value >= 'a' && value <= 'z')
	{
		result = value - 'a';
	}
	else if (value >= 'A' && value <= 'Z')
	{
		result = value - 'A' + 26;
	}
	else if(value == ' ')
	{
		result = ASIZE - 1;
	}

	return result;
}

//
//  DFA
//
int DFA(const string& source, const string& pattern)
{
	const int length = pattern.length();
	int result = -1;
	vector<vector<int>> transTbl;
	CreateDFATable(transTbl,pattern);

	int pos = 0;
	for (int i=0; i<source.length(); ++i)
	{
		int index = Convert(source[i]);
		if (index < 0)
		{
			break;
		}

		pos = transTbl[pos][index];
		if (pos == length)
		{
			result = i + 1 - length;
			break;
		}
	}

	return result;
}

TEST(tAlgoString, tDFA)
{
	ASSERT_EQ(DFA("GCATCGCAGAGAGTATACAGTACG","GCAGAGAG"),5);
}