#include <gtest\gtest.h>
#include <queue>
using namespace std;

class MedianFinder {
public:

	// Adds a number into the data structure.
	void addNum(int num) {

		int r = m_minValues.top();
		int l = m_maxValues.top();

		if (num < r)
	}

	// Returns the median of current data stream
	double findMedian() {

	}

private:

	priority_queue<int,vector<int>,less<int>> m_minValues;
	priority_queue<int,vector<int>, greater<int>> m_maxValues;

};