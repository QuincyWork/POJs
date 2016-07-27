#include <gtest/gtest.h>
using namespace std;

string convertToTitle(int n)
{
	const char ALPHA[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int base = 26;

	string result;
	while (n)
	{
		int v = (n-1) % base;
		result += ALPHA[v];

		n = (n-1) / base;
	}

	reverse(result.begin(),result.end());
	return result;
}

TEST(Pratices, tConvertToTitle)
{
	ASSERT_EQ(convertToTitle(27),"AA");
	ASSERT_EQ(convertToTitle(26),"Z");
	ASSERT_EQ(convertToTitle(25894),"ALGX");
}