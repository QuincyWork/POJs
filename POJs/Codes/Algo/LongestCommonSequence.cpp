#include <gtest/gtest.h>
#include <vector>
using namespace std;

enum DirectionType
{
	TypeUp,
	TypeLeftUp,
	TypeLeft
};

int TMaxVal(int A, int B, int C, DirectionType& index)
{
	int nVal = A;
	index = TypeUp;

	if (B > nVal)
	{
		nVal = B;
		index = TypeLeftUp;
	}

	if (C > nVal)
	{
		nVal = C;
		index = TypeLeft;
	}
				
	return nVal;
}

// 按照上、左上、左的比较顺序
string GetLCS(const string& strA, const string& strB)
{
	int nLengthA = strA.length();
	int nLengthB = strB.length();

	if (!nLengthA || !nLengthB)
	{
		return "";
	}
	
	struct RecordInfo
	{
		char Direction;
		char Count;
	};

	RecordInfo* arrRecordInfo = new RecordInfo[(nLengthA + 1) * (nLengthB+1)];
	memset(arrRecordInfo, 0, (nLengthA + 1) * (nLengthB + 1) * sizeof(RecordInfo));

	for (int i = 1; i <= nLengthA; ++i)
	{
		for (int j = 1; j <= nLengthB; ++j)
		{
			int nNewVal = 0;
			DirectionType nDirect;
			if (strA[i-1] == strB[j-1])
			{
				nNewVal = TMaxVal(
					arrRecordInfo[(i-1)*(nLengthB+1) + j].Count,
					arrRecordInfo[(i-1)*(nLengthB+1) + j-1].Count + 1,
					arrRecordInfo[i*(nLengthB+1) + j-1].Count,
					nDirect);				
			}
			else
			{
				nNewVal = TMaxVal(
					arrRecordInfo[(i-1)*(nLengthB+1) + j].Count,
					arrRecordInfo[(i-1)*(nLengthB+1) + j-1].Count,
					arrRecordInfo[i*(nLengthB+1) + j-1].Count,
					nDirect);
			}

			arrRecordInfo[i*(nLengthB+1) + j].Count = nNewVal;
			arrRecordInfo[i*(nLengthB+1) + j].Direction = nDirect;
		}
	}

	string strValue;
	int i = nLengthA;
	int j = nLengthB;
	while ((i > 0) && (j > 0))
	{
		int nDirect = arrRecordInfo[i*(nLengthB+1) + j].Direction;
		if (TypeLeftUp == nDirect)
		{
			if (strA[i-1] == strB[j-1])
			{
				strValue += strA[i-1];
			}

			--i;
			--j;
		}
		else if(TypeUp == nDirect)
		{
			--i;
		}
		else if(TypeLeft == nDirect)
		{
			--j;
		}		
	}
	
	reverse(strValue.begin(),strValue.end());
	
	return strValue;
}

TEST(Algo, tLongestCommonSequence)
{
	// 
	// "" ""
	// abcdefg   bdacafg
	// abcabcagc abcdcagb

	vector<string> result;
	ASSERT_EQ(GetLCS("",""),"");
	ASSERT_EQ(GetLCS("abcdefg","bdacafg"), "acfg");	
}
