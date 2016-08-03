#include <gtest/gtest.h>
#include <set>
using namespace std;

void generateChild(vector<string>& result, string& value, int left, int right)
{
	if (left==0 && right==0)
	{
		result.push_back(value);
	}

	if (left > 0)
	{
		generateChild(result, value + "(", left-1, right);
	}

	if (right > left && right > 0)
	{
		generateChild(result, value + ")", left, right-1);
	}
}

vector<string> generateParenthesis(int n) {
        
    vector<string> result;
	generateChild(result, string(), n, n);
	return result;
}

 TEST(LeetCode, tGenerateParenthesis)
 {
	 vector<string> result = generateParenthesis(3);
	 result = generateParenthesis(4);
 }