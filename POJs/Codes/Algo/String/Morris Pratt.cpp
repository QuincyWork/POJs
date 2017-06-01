#include <gtest/gtest.h>

using namespace std;

void preMp(char* x, int m, int mpNext[])
{
	mpNext[0] = -1;
	for(int i=0; i<m; ++i)
	{
		int j = -1;
		while (j > -1 && x[i] != x[j])
		{
			j = mpNext[j];
		}

		i++;
		j++;
		if (x[i] != x[j])
		{
			mpNext[i] = j;
		}
		else
		{
			mpNext[i] = mpNext[j];
		}		
	}
}

int MorrisPratt(char* S,int N,char* P,int M)
{
	int result = -1;
	int mpNext[100] = {0};
	// Ô¤´¦Àí
	preMp(P,M,mpNext);

	// ËÑË÷
	for (int i=0; i<N; ++i)
	{
		int j=0;
		while (j > -1 && S[i] != P[j])
		{
			j = mpNext[j];
		}
		
		j++;
		i++;
		if (j >= M)
		{
			result = j - i;
			break;
		}
	}
}