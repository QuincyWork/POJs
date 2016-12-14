#include <gtest/gtest.h>
#include <stack>
using namespace std;

int longestValidParentheses(string s)
{
	if (s.empty())
	{
		return 0;
	}

	stack<int>  leftBracket;
	vector<int> dp(s.length(),0);

	// Init first
	dp[0] = 0;
	if (s[0] == '(')
	{
		leftBracket.push(0);
	}

	for (int i=1; i<s.length(); ++i)
	{		
		if ('(' == s[i])
		{			
			int val = 0;
			if ('(' != s[i-1])
			{
				val = dp[i] = dp[i-1];
			}			

			leftBracket.push(dp[i]);						
		}
		else if( (')' == s[i]) && (leftBracket.size() > 0) )
		{			
			dp[i] = dp[i-1] + 2;
			if (')' == s[i-1])
			{
				dp[i] += leftBracket.top();
			}

			leftBracket.pop();
		}
		else
		{
			dp[i] = 0;
		}
	}

	int result = 0;
	for (int i=0; i<s.length(); ++i)
	{
		if (dp[i] > result)
		{
			result  = dp[i];
		}
	}

	return result;
}

TEST(LeetCode, tLongestValidParentheses)
{
	// "(()" = 2
	ASSERT_EQ(longestValidParentheses("(()"),2);

	// "()(()" = 2
	ASSERT_EQ(longestValidParentheses("()(()"),2);

	// ")()())" = 4
	ASSERT_EQ(longestValidParentheses(")()())"),4);

	// ")()())(()()()( = 6
	ASSERT_EQ(longestValidParentheses(")()())(()()()("),6);

	// "(((((()()())))(()))) = 26
	ASSERT_EQ(longestValidParentheses("(((((()()())))(())))"),20);
}