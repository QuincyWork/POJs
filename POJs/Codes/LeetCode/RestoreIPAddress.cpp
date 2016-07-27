#include <gtest/gtest.h>
#include <vector>

using namespace std;

vector<string> RestoreIpAddresses(string& s) 
{
	vector<string> result;
	int nLength		= s.length();
	int nValue;
	for (int i=1; i<=3 && i<nLength; ++i)
	{
		string strFirst = s.substr(0,i);
		nValue = atoi(strFirst.c_str());
		if (nValue > 255)
		{
			break;
		}

		for (int j=1; j<=3 && i+j<nLength; ++j)
		{
			string strSecond = s.substr(i,j);
			nValue = atoi(strSecond.c_str());
			if (nValue > 255)
			{
				break;
			}

			for (int m=1; m<=3 && i+j+m<nLength; ++m)
			{
				string strThrid = s.substr(i+j,m);
				nValue = atoi(strThrid.c_str());
				if (nValue > 255)
				{
					break;
				}
				
				string strFour = s.substr(i+j+m,nLength-i+j+m);				
				nValue = atoi(strFour.c_str());
				if (nValue > 255)
				{
					continue;
				}

				result.push_back(strFirst+"."+strSecond+"."+strThrid+"."+strFour);
			}
		}
	}

	return result;
}

TEST(Pratices, tRestoreIpAddresses)
{
	string strValue = "25525511135";
	vector<string> result = RestoreIpAddresses(strValue);
	ASSERT_EQ(result.size(),2);

	strValue = "123123123";
	result = RestoreIpAddresses(strValue);

	strValue = "1111";
	result = RestoreIpAddresses(strValue);
	ASSERT_EQ(result.size(),1);

	strValue = "192168221120";
	result = RestoreIpAddresses(strValue);
	ASSERT_EQ(result.size(),1);
}