#include <gtest/gtest.h>
using namespace std;

string convert(string s, int numRows)
{
	if (s.empty() || !numRows || (numRows==1))
	{
		return s;
	}

	string result;
	int length = s.length();
	char* data = new char[length*numRows];
	memset(data,0,length * numRows);

	int delta = 0;
	int offset = 0;
	int flag = 1;

	for (int i= 0; i<length; ++i)
	{
		data[offset + delta * length] = s[i];		
		if ( (delta+flag) >= numRows)
		{
			flag = -1;
		}
		else if ((delta+flag) < 0)
		{
			flag = 1;
		}
		delta += flag;

		if (flag == -1)
		{
			offset ++;
		}
	}

	for (int i=0; i<numRows; ++i)
	{
		for (int j=0; j < length; ++j)
		{
			if (data[j+i*length])
				result += data[j+i*length];
		}
	}

	delete data;

	return result;
}

TEST(Pratices, tZigZagConversion)
{
	// ''=> ''
	// ABCDEFG 3 => A   E  => AEBDFCG
	//              B D F 
	//              C   G

	ASSERT_EQ(convert("",1),"");
	ASSERT_EQ(convert("ABCDEFG",1),"ABCDEFG");
}