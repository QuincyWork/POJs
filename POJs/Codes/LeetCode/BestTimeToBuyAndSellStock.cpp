#include <gtest/gtest.h>
using namespace std;

/**
 ����������������к͵��㷨���������ǰ������Ԫ�صĲ�
*/

int maxProfit(vector<int>& prices)
{
	if (prices.size() < 2)
	{
		return 0;
	}

	int current = 0;
	int max = 0;

	for (int i=1; i < prices.size(); ++i)
	{
		current += prices[i] - prices[i-1];
		if (current >= max)
		{
			max = current;
		}
		
		if (current < 0)
		{
			current = 0;
		}
	}

	return max;
}

TEST(Pratices, tMaxProfit)
{
	vector<int> data;
	ASSERT_EQ(maxProfit(data),0);

	data.push_back(1);
	ASSERT_EQ(maxProfit(data),0);

	data.push_back(2);
	data.push_back(10);
	ASSERT_EQ(maxProfit(data),9);
	data.push_back(0);
	ASSERT_EQ(maxProfit(data),9);

	int data2[] = {2,1,3,5,1};
	ASSERT_EQ(maxProfit(vector<int>(data2,data2+sizeof(data2)/sizeof(int))),4);
}