#include <gtest/gtest.h>
using namespace std;


void BruteForce(char* S,char* P,vector<int>& result)
{
	int N = strlen(S);
	int M = strlen(P);
	for (int i=0; i<N-M; ++i)
	{
		int j=0;
		while(j < M && S[i] == P[j++]);
		if (j == M)
		{
			result.push_back(i);
		}
	}
}

TEST(tAlgoString, tBruteForce)
{
	vector<int> result;
	BruteForce("ABCDEFGHABCDEGABA","AB",result);
	ASSERT_EQ(result.size(),3);
}