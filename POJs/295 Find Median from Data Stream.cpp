#include <gtest\gtest.h>
#include <util.h>
#include <queue>
#include <math.h>
using namespace std;

class MedianFinder 
{
public:

    // Adds a number into the data structure.
    void addNum(int num) 
	{
        if (maxHeap.size() == 0 || num < maxHeap.top())
		{
			maxHeap.push(num);
			if (maxHeap.size() > minHeap.size()+1)
			{								
				minHeap.push(maxHeap.top());
				maxHeap.pop();
			}
		}
		else
		{
			minHeap.push(num);
			if (minHeap.size() > maxHeap.size()+1)
			{
				maxHeap.push(minHeap.top());
				minHeap.pop();
			}
		}
    }

    // Returns the median of current data stream
    double findMedian() 
	{
        double r = 0;
		if (maxHeap.size() == minHeap.size())
		{
			r = (double)(maxHeap.top() + minHeap.top()) / 2;
		}
		else if(maxHeap.size() > minHeap.size())
		{
			r = maxHeap.top();
		}
		else
		{
			r = minHeap.top();
		}

		return r;
    }

private:

	priority_queue<int> maxHeap;
	priority_queue<int,vector<int>,greater<int>> minHeap;
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();

TEST(LeetCode, tMedianFinder)
{	
	MedianFinder mf;
	mf.addNum(1);
	ASSERT_DOUBLE_EQ(mf.findMedian(),1.0);
	mf.addNum(2);
	ASSERT_DOUBLE_EQ(mf.findMedian(),1.5);

	mf.addNum(5);
	mf.addNum(11);
	mf.addNum(3);
	ASSERT_DOUBLE_EQ(mf.findMedian(),3.0);
}