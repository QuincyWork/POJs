#include <gtest/gtest.h>
#include <stack>
using namespace std;

bool isValid(string s)
{
	//static char validChars[] = {'(',')','[',']','{','}'};
	const int length = s.length();

	stack<int> content;
	for (int i=0; i<length; ++i)
	{
		char val = s[i];
		switch(val)
		{
		case '(':
		case '[':
		case '{':
			content.push(val);
			break;
		case ')':
			if (content.empty() || content.top()!= '(')
				return false;
			content.pop();
			break;
		case ']':
			if (content.empty() || content.top()!= '[')
				return false;
			content.pop();
			break;
		case '}':
			if (content.empty() || content.top()!= '{')
				return false;
			content.pop();
			break;
		default:
			return false;
		}
	}

	return content.empty();
}

TEST(Pratices, tIsValid)
{
	ASSERT_TRUE(isValid(""));
	ASSERT_TRUE(isValid("()"));
	ASSERT_FALSE(isValid("()A"));
	ASSERT_FALSE(isValid("(B)"));
	ASSERT_FALSE(isValid("C()"));
	ASSERT_FALSE(isValid(")("));
	ASSERT_TRUE(isValid("(((([[[{{{}}}]]]))))"));
	ASSERT_FALSE(isValid("(((([[[{{{}}}]]])))"));
}