#include <gtest/gtest.h>
using namespace std;

// LeetCode
// 292. Nim Game
// https://leetcode.com/problems/nim-game/

bool canWinNim(int n)
{	
	// 只要是4的倍数都会输，否则会赢，因而变成了判断n是否是4的倍数。
	// 可以判断n的最后2bit是否为0来判断
	return (n & 0x3);
}


TEST(LeetCode, tCanWinNim)
{
	ASSERT_TRUE(canWinNim(5));
	ASSERT_FALSE(canWinNim(228));
}