#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
using namespace std;

int GetLCS(const string& strA, const string& strB, vector<string>& result)
{
	int nLengthA = strA.length();
	int nLengthB = strB.length();
	int nLongest = 0;
	vector<int> vecSubStrEnd;

	if (!nLengthA || !nLengthB)
	{
		return 0;
	}

	result.clear();

	//           strB
	//   0 1 2 3 4 5 6 7 8
	//   1
	// s 2
	// t 3
	// r 4
	// A 5
	//   6

	char* arrRecordInfo = new char[(nLengthA + 1) * (nLengthB + 1)];
	memset(arrRecordInfo, 0, (nLengthA + 1) * (nLengthB + 1));

	for (int i = 1; i <= nLengthA; ++i)
	{
		for (int j = 1; j <= nLengthB; ++j)
		{
			if (strA[i-1] == strB[j-1])
			{
				int nNewCount = arrRecordInfo[(i-1)*(nLengthB+1) + j-1] + 1;				
				if (nNewCount > nLongest)
				{
					nLongest = nNewCount;
					vecSubStrEnd.clear();
					vecSubStrEnd.push_back(j);					
				}
				else if (nNewCount == nLongest)
				{
					vecSubStrEnd.push_back(j);
				}

				arrRecordInfo[i*(nLengthB+1) + j] = nNewCount;
			}
		}
	}

	for (int i=0; i < vecSubStrEnd.size(); ++i)
	{
		int nOffset = vecSubStrEnd[i];		
		result.push_back(strB.substr(nOffset-nLongest, nLongest));
	}
	// 移除重复公共字符串
	sort(result.begin(), result.end());
	result.erase(unique(result.begin(), result.end()), result.end());

	delete[] arrRecordInfo;

	return nLongest;
}

// 一种节省空间的方法
// 在构造这个二维矩阵的过程中由于得出矩阵的某一行后其上一行就没用了，所以实际上在程序中可以用一维数组来代替这个矩阵
// 如果把strB的长度假设为短的那个字符串，空间更少
int GetLCS2(const string& strA, const string& strB, vector<string>& result)
{
	int nLengthA = strA.length();
	int nLengthB = strB.length();
	int nLongest = 0;
	vector<int> vecSubStrEnd;

	if (!nLengthA || !nLengthB)
	{
		return 0;
	}

	result.clear();

	//        strB
	//   0 1 2 3 4 5 
	//   1
	// s 2
	// t 3
	// r 4
	// A 5
	//   6

	char* arrRecordInfo = new char[nLengthB+1];	
	memset(arrRecordInfo, 0, nLengthB+1);

	for (int i = 1; i <= nLengthA; ++i)
	{
		for (int j = nLengthB; j >= 1; --j)
		{
			if (strA[i-1] == strB[j-1])
			{
				int nNewCount = arrRecordInfo[j-1] + 1;
				if (nNewCount > nLongest)
				{
					nLongest = nNewCount;
					vecSubStrEnd.clear();
					vecSubStrEnd.push_back(j);					
				}
				else if (nNewCount == nLongest)
				{
					vecSubStrEnd.push_back(j);
				}

				arrRecordInfo[j] = nNewCount;
			}
			else
			{
				arrRecordInfo[j] = 0;
			}
		}
	}

	for (int i=0; i < vecSubStrEnd.size(); ++i)
	{
		int nOffset = vecSubStrEnd[i];
		result.push_back(strB.substr(nOffset-nLongest, nLongest));
	}
	// 移除重复公共字符串
	sort(result.begin(), result.end());
	result.erase(unique(result.begin(), result.end()), result.end());	

	delete[] arrRecordInfo;

	return nLongest;
}


TEST(Algo, tLongestCommonSubString)
{
	// 
	// "" ""
	// abcdefg   bdacafg
	// abcabcagc abcdcagb

	vector<string> result;
	ASSERT_EQ(GetLCS("","",result),0);
	ASSERT_EQ(GetLCS("abcdefg","bdacafg",result),2);
	ASSERT_EQ(GetLCS("abcabcagc","abcdcagb",result),3);

	ASSERT_EQ(GetLCS2("abcdefg","bdacafg",result),2);
	ASSERT_EQ(GetLCS2("abcabcagc","abcdcagb",result),3);
}
