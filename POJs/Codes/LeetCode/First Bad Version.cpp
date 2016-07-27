#include <gtest/gtest.h>
using namespace std;

char data[100] = {0};
bool isBadVersion(int version)
{
	return data[version-1];
}

int find(int l, int r)
{
	if (l==r)
	{
		return l;
	}

	int mid = l + (r-l) / 2;
	if (isBadVersion(mid))
	{
		return find(l, mid);
	}
	else
	{
		return find(mid+1, r);
	}
}

int firstBadVersion(int n)
{
	return find(1, n);
}

TEST(Pratices, tFirstBadVersion)
{
	memset(data+60,1,40);
	int result = firstBadVersion(100);
}