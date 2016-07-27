#include <gtest/gtest.h>
using namespace std;

int titleToNumber(string s)
{
	const int length = s.length();
	if (!length)
		return 0;

	int base = 1;
	int result = 0;
	for (int i=length-1; i>=0; --i)
	{
		int v = s[i]-'A'+1;
		result += v*base;
		base *= 26;
	}

	return result;
}

TEST(Pratices, tTitleToNumber)
{
	//A
	//Z
	//AA
	//AAA

	ASSERT_EQ(titleToNumber("A"),1);
	ASSERT_EQ(titleToNumber("Z"),26);
	ASSERT_EQ(titleToNumber("AA"),27);
}