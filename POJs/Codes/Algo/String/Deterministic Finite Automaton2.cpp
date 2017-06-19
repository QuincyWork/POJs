#include <gtest/gtest.h>
using namespace std;

const int	ASIZE  = 53;
const char	AlphaTbl[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ";

void GeneralTransformTable(int*& ppTable, const char* szPattern)
{
	const int length = strlen(szPattern);
	const int tableSize = (length+1)*ASIZE;
	ppTable = new int[tableSize];
	memset(ppTable,0,tableSize*sizeof(int));
	
	char* temp = new char[length];
	for (int s = 0; s < length; ++s)	//State
	{		
		memcpy(temp,szPattern,s);
		for (int i = 0; i < ASIZE; ++i)	//Input char
		{
			temp[s] = AlphaTbl[i];
			int k = s+1;
			while ( k > 0 && strncmp(szPattern,temp+s+1-k,k)!=0) //Suffix
			{
				--k;
			}

			if (k >0)
			{
				ppTable[s*ASIZE + i] = k;
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

int DFA(const char* source, const char* pattern)
{
	int* transformTable = 0;
	GeneralTransformTable(transformTable,pattern);

	int result = -1;
	int length = strlen(source);
	int lengthPattern = strlen(pattern);
	int state = 0;
	for (int i=0; i<length; ++i)
	{
		int idx = Convert(source[i]);
		if (idx < 0)
		{
			break;
		}

		state = transformTable[state * ASIZE + idx];
		if (state == lengthPattern)
		{
			result = i + 1 - lengthPattern;
			break;
		}
	}

	return result;
}

TEST(Algo,tDFA2)
{
	ASSERT_EQ(DFA("GCATCGCAGAGAGTATACAGTACG","GCAGAGAG"),5);
}