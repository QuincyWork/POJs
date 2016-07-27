#include <gtest/gtest.h>
#include<iostream>
using namespace std;

int Compare1(char* s1, char* s2)
{
    int p1 = 0;
    int p2 = 0;

    while(s1[p1] != '\0' ||
          s2[p2] != '\0')
    {
        char c1 = s1[p1];
        if (c1 == '\0')
            return -1;

        if (c1 >= 'a' && c1 <= 'z')
            c1 -= 'a' - 'A';

        char c2 = s2[p2];
        if (c2 == '\0')
            return 1;

        if (c2 >= 'a' && c2 <= 'z')
            c2 -= 'a' - 'A';

        if (c1 != c2)
            return c1-c2;

        ++p1;
        ++p2;
    }

    return 0;
}

int Compare(const char* src, const char* dst)
{
	int c1,c2;
	do
	{
		c1 = *src++;
		c2 = *dst++;

		if (c1 >= 'a' && c1 <= 'z')
            c1 -= 'a' - 'A';

		if (c2 >= 'a' && c2 <= 'z')
            c2 -= 'a' - 'A';
	}
	while(c1 && (c1==c2));

	return c1-c2;
}

int main1()
{
    char s1[80]={0};
    char s2[80]={0};
    cin.getline(s1,80);
    cin.getline(s2,80);

    int r = Compare(s1, s2);
    if (r==0)
    {
        cout << "=" << endl;
    }
    else if(r > 0)
    {
        cout << ">" << endl;
    }
    else
    {
        cout << "<" << endl;
    }
	
    return 0;
} 

/// ²âÊÔÓÃÀý
//  abc         abc
//  NULL        NULL
//  ABC         abc
//  abc{        ABC{
//  abc[        ABc[
//  12ABC       12abc

//  ABc         abc e
//  bde         Abd a
//  ¿Õ          Space

TEST(BaiLian, tStringCompareNoCase2721)
{	
	ASSERT_EQ(Compare("abc", "abc"), 0);
	ASSERT_EQ(Compare("", ""), 0);
	ASSERT_EQ(Compare("ABC", "abc"), 0);
	ASSERT_EQ(Compare("abc{", "ABC{"), 0);
	ASSERT_EQ(Compare("abc[", "ABc["), 0);
	ASSERT_EQ(Compare("12ABC", "12abc"), 0);

	ASSERT_LT(Compare("ABc", "abc e"), 0);
	ASSERT_GT(Compare("bde", "Abd a"), 0);
	ASSERT_LT(Compare("", " "), 0);
}
