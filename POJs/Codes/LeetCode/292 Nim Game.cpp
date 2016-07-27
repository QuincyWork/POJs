#include <gtest/gtest.h>
using namespace std;

// LeetCode
// 292. Nim Game
// https://leetcode.com/problems/nim-game/

bool canWinNim(int n)
{	
	// ֻҪ��4�ı��������䣬�����Ӯ�����������ж�n�Ƿ���4�ı�����
	// �����ж�n�����2bit�Ƿ�Ϊ0���ж�
	return (n & 0x3);
}


TEST(LeetCode, tCanWinNim)
{
	ASSERT_TRUE(canWinNim(5));
	ASSERT_FALSE(canWinNim(228));
}