#include <gtest/gtest.h>
#include <list>
using namespace std;

void getVersionNumbers(string version, list<int>& v)
{
	while (!version.empty())
	{
		string v1;
		string::size_type p1 = version.find_first_of('.');
		if (p1 != string::npos)
		{
			v1 = version.substr(0,p1);
			version = version.substr(p1+1);
		}
		else
		{
			v1 = version;
			version.clear();
		}

		v.push_back(atoi(v1.c_str()));
	}
}

int compareVersion(string version1, string version2)
{
	list<int> ver1;
	list<int> ver2;
	getVersionNumbers(version1, ver1);
	getVersionNumbers(version2, ver2);

	int v1 = 0;
	int v2 = 0;
	while (!ver1.empty() && !ver2.empty())
	{
		v1 = ver1.front();
		ver1.pop_front();
		v2 = ver2.front();
		ver2.pop_front();

		if (v1 > v2)
			return 1;
		else if(v1 < v2)
			return -1;
	}

	// 相同的部分的版本号是相同的，计算剩余一个的数字
	v1 = 0;
	v2 = 0;

	for (list<int>::const_iterator it = ver1.begin();
		it != ver1.end(); ++it)
	{
		if (*it)
			return 1;
	}
	
	for (list<int>::const_iterator it = ver2.begin();
		it != ver2.end(); ++it)
	{
		if (*it)
			return -1;
	}

	return 0;
}

TEST(Pratices, tCompareVersion)
{
	ASSERT_EQ(compareVersion("1.2.3","1.2.3"),0);
	ASSERT_EQ(compareVersion("1.2.3.4","1.2.3"),1);
	ASSERT_EQ(compareVersion("12.2.3","3.2.3.3.1"),1);
	ASSERT_EQ(compareVersion("4.2.3","31"),-1);
	ASSERT_EQ(compareVersion("4","4.0.0.0"),0);
}