#include <gtest/gtest.h>
using namespace std;

string addBinary(string a, string b)
{
	int idxA = a.length() - 1;
	int idxB = b.length() - 1;

	string c;
	int carry = 0;
	while (idxA >= 0 || idxB >= 0)
	{
		int val = 0;
		if (idxA >=0)
		{
			val = a[idxA--] - '0';
		}

		if (idxB >=0)
		{
			val += b[idxB--] - '0';
		}

		val += carry;

		carry = val / 2;
		c.insert(c.begin(),val % 2 + '0');
	}

	if (carry)
	{
		c.insert(c.begin(),carry + '0');
	}

	return c;
}
 
TEST(Pratice, tAddBinary)
{
	// 1 0 0 + 1 => 1 0 1
	ASSERT_EQ(addBinary("100","1"),"101");
	// 1 0 1 + 1 1 => 2 0 0
	ASSERT_EQ(addBinary("101","11"),"1000");
	// 1 1 1 + 1 0 1=> 1 1 0 0
	ASSERT_EQ(addBinary("111","101"),"1100");
	// 0 + 0 => 1
	ASSERT_EQ(addBinary("","0"),"0");
	// 0 + 1 1 => 11
	ASSERT_EQ(addBinary("","11"),"11");
}