#include <gtest/gtest.h>
using namespace std;

void ShowResult(bool Bits[], int nSize)
{
	cout << "{";
	for (int i=0; i<nSize; ++i)
	{
		if (Bits[i])
		{
			cout << i+1 << " ";
		}
	}
	cout << "}\n";
}

bool Add(bool Bits[], int nSize)
{
	for (int i = nSize -1; i >= 0; --i)
	{
		Bits[i] = !Bits[i];	// 如果是1变成0再进位，如果是0变成1退出。
		if (Bits[i])
		{
			return true;			
		}	
	}

	return false;
}

// 二进制法
int GenerateSubset(int nSize)
{	
	if (nSize==0)
	{	
		cout << "{}" << endl;
		return 1;
	}
	
	int nCount = 0;
	bool *Bits = new bool[nSize];
	memset(Bits, false, sizeof(bool)*nSize);

	do
	{
		ShowResult(Bits, nSize);
		nCount++;
	}
	while(Add(Bits, nSize));

	delete[] Bits;

	return nCount;
}

void ShowResult2(int State[], int nPos)
{
	cout << "{";
	for (int i=0; i<nPos; ++i)
	{
		cout << State[i] << " ";
	}
	cout << "}\n";
}

// 产生字典序的子集
int GenerateOrderSubset(int nSize)
{
	if (nSize==0)
	{	
		cout << "{}" << endl;
		return 1;
	}
	
	int nCount = 0;
	int nPos = -1;
	int *State = new int[nSize];
	memset(State, 0, sizeof(int)*nSize);

	do
	{
		nCount++;
		ShowResult2(State, nPos+1);
		if (nPos==-1)
		{
			State[++nPos] = 1;
			continue;
		}

		if (State[nPos] < nSize) // 递增集合个数
		{
			State[nPos+1] = State[nPos] + 1;
			nPos++;
		}		
		else if(nPos > 0)
		{
			nPos--;
			State[nPos]++;
		}
		else
		{ 
			break;
		}
	}
	while(true);

	delete[] State;

	return nCount;
}

TEST(Algo, tCombination)
{
	// 0个数子集合数 =〉2^0 = 1
	ASSERT_EQ(GenerateSubset(0), 1);

	// 3个数子集合数 =〉2^3 = 8
	ASSERT_EQ(GenerateSubset(3), 8);

	// 5个数子集合数 =〉2^5 = 32
	ASSERT_EQ(GenerateSubset(5), 32);

	// 10个数子集合数 =〉2^10 = 1024
	ASSERT_EQ(GenerateSubset(10), 1024);

	// 有字节序

	// 0个数子集合数 =〉2^0 = 1
	ASSERT_EQ(GenerateOrderSubset(0), 1);

	// 3个数子集合数 =〉2^3 = 8
	ASSERT_EQ(GenerateOrderSubset(3), 8);

	// 5个数子集合数 =〉2^5 = 32
	ASSERT_EQ(GenerateOrderSubset(5), 32);

	// 10个数子集合数 =〉2^10 = 1024
	ASSERT_EQ(GenerateOrderSubset(10), 1024);
}