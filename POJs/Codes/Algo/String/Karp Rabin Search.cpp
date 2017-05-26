#include <gtest/gtest.h>
using namespace std;

int ReHash(int PreHash, int PreValue, int shift, char value)
{
	return (PreHash - PreValue*shift) * 2 + value;
}

int KarpRabin(char* S,int N,char* P,int M)
{
	int result = -1;
	int ShiftValue = 1;
	int HashS = 0;
	int HashP = 0;
	for (int i=0; i<M; ++i)
	{
		ShiftValue = i ? (ShiftValue << 1) : 1;
		HashS = (HashS << 1) + S[i];
		HashP = (HashP << 1) + P[i];
	}
	
	int pos = 0;
	while (pos <= N-M )
	{
		if (HashS == HashP && (strncmp(S+pos,P,M)==0))
		{
			result = pos;
			break;
		}

		HashS = ReHash(HashS,S[pos],ShiftValue,S[pos+M]);
		pos++;
	}

	return result;
}

int Search(char* S,char* P)
{
	return KarpRabin(S,strlen(S),P,strlen(P));
}

TEST(tAlgoString, tKarpRabin)
{
	ASSERT_EQ(Search("GCATCGCAGAGAGTATACAGTACG","GCAGAGAG"),5);
	ASSERT_EQ(Search("GCATCGCAGAGAGTATACAGTACG","GTACG"),19);
}