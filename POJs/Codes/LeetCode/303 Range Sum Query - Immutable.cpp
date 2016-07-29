#include <gtest/gtest.h>
using namespace std;

// LeetCode
// 303. Range Sum Query - Immutable
// https://leetcode.com/problems/range-sum-query-immutable/

class NumArray {

public:
    NumArray(vector<int> &nums) {
        
		int nSum = 0;
		m_vecSums.push_back(0);
		vector<int>::const_iterator it = nums.begin();
		while(it != nums.end())
		{
			nSum += *it;
			m_vecSums.push_back(nSum);
			++it;
		}
    }

    int sumRange(int i, int j) {
        
		if ( (i < 0) || (j >= m_vecSums.size()-1))
			return 0;
		
		return m_vecSums[j+1] - m_vecSums[i];
    }

private:
	vector<int> m_vecSums;
};

TEST(LeetCode, tNumArray)
{
	int data[] = {-2, 0, 3, -5, 2, -1};
	vector<int> vecData(data, data+_countof(data));
	NumArray num(vecData);

	ASSERT_EQ(num.sumRange(0,2),1);
	ASSERT_EQ(num.sumRange(2,5),-1);
	ASSERT_EQ(num.sumRange(0,5),-3);
	ASSERT_EQ(num.sumRange(0,0),-2);
	ASSERT_EQ(num.sumRange(5,5),-1);
}