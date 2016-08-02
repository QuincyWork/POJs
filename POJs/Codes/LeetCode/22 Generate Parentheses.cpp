#include <gtest/gtest.h>
#include <set>
using namespace std;

void generateChild(int n, set<string>& result)
{	
    if (n == 1)
    {
    	result.insert("()");
    }
    else if (n > 1)
    {
    	set<string> childs;
    	generateChild(n-1, childs);
    	for (set<string>::const_iterator it = childs.begin();
    		it != childs.end();
    		++it)
    	{			
    		result.insert("()" + *it);
    		result.insert(*it + "()");
    		result.insert("(" + *it + ")");
    	}
    }
}
    
vector<string> generateParenthesis(int n) {
        
    set<string> childs;
	generateChild(n, childs);
	return vector<string>(childs.begin(),childs.end());
}

 TEST(LeetCode, tGenerateParenthesis)
 {
	 vector<string> result = generateParenthesis(3);
	 result = generateParenthesis(4);
 }