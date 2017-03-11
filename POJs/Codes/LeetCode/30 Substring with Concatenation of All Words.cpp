#include <gtest/gtest.h>
#include <unordered_map>
using namespace std;

vector<int> findSubstring(string s, vector<string>& words)
{
	vector<int> result;
	if (s.empty() || words.empty())
	{
		return result;
	}
	
	unordered_map<string,int> wordsTable;
	int wordLen = words[0].length();
	int seqLen  = wordLen * words.size();

	int next    = seqLen;
	int begin   = 0;	

	while (next <= s.length())
	{
		// reset table
		wordsTable.clear();
		for (int i=0; i<words.size(); ++i)
		{
			wordsTable[words[i]]++;
		}

		int current = begin;
		for (int i = 0; i < words.size(); ++i)
		{
			string val = s.substr(current,wordLen);
			if ( wordsTable.count(val) &&
				(wordsTable[val]-- > 0))		
			{				
				current += wordLen;								
			}
			else
			{
				break;
			}
		}

		if (current == next)
		{
			result.push_back(begin);
		}		

		begin++;
		next  = begin + seqLen;
	}

	return result;
}

TEST(LeetCode, tFindSubstring)
{
	vector<string> words;
	words.push_back("foo");
	words.push_back("bar");

	vector<int> result = findSubstring("barfoothefoobarman",words);

	words.clear();
	words.push_back("bar");
	words.push_back("foo");
	words.push_back("the");

	result = findSubstring("barfoofoobarthefoobarman",words);

	words.clear();
	words.push_back("word");
	words.push_back("good");
	words.push_back("best");
	words.push_back("good");

	result = findSubstring("wordgoodgoodgoodbestword", words);
}