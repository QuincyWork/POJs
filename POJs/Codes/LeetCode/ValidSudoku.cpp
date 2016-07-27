#include <gtest/gtest.h>
using namespace std;

bool isValidSudoku(vector< vector<char> >& board)
{
	//满足每一行、每一列、每一个粗线宫内的数字均含1-9，不重复
	const int N = 9;
	int flags[N] = {0};

	for (int i = 0; i<N; ++i)
	{
		memset(flags,0,sizeof(flags));
		for (int j=0; j<N; ++j)
		{
			char v = board[i][j];
			if ( v!='.' && flags[v-'1']++)
			{
				return false;
			}
		}
	}

	for (int j = 0; j<N; ++j)
	{
		memset(flags,0,sizeof(flags));
		for (int i=0; i<N; ++i)
		{
			char v = board[i][j];
			if (v!='.' && flags[v-'1']++)
			{
				return false;
			}
		}
	}

	for (int t = 0; t<N; t+=3)
	{
		for (int m=0; m<N; m+=3)
		{
			memset(flags,0,sizeof(flags));
			for (int i = 0; i<N/3; ++i)
			{
				for (int j=0; j<N/3; ++j)
				{
					char v = board[t+i][m+j];
					if (v!='.' && flags[v-'1']++)
					{
						return false;
					}
				}
			}
		}
	}

	return true;
}

TEST(Pratices, tIsValidSudoku)
{

}