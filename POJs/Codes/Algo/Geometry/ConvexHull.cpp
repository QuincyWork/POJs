#include <gtest/gtest.h>
#include <algorithm>
using namespace std;

struct Point
{
	int x;
	int y;

	Point(int _x, int _y)
		: x(_x),y(_y)
	{
	}

	bool operator < (const Point& r) const
	{
		return ((x < r.x) || (x == r.x && y < r.y));
	}
};


vector<Point> ConvexHull(vector<Point>& P)
{
	int length = P.size();
	if (length < 3)
	{
		return P;
	}

	sort(P.begin(),P.end());

	// 计算上部分凸包
	vector<Point> upper(P.begin(),P.begin()+2);	
	for (int i=2; i<length; ++i)
	{
		upper.push_back(P[i]);
		while (upper.size() >= 3)
		{			
			int right = upper.size() - 1;
			int mid  = right - 1;
			int left = mid - 1;
			int cp = (upper[mid].x - upper[left].x) * (upper[right].y - upper[left].y)
				- (upper[mid].y - upper[left].y) * (upper[right].x - upper[left].x);

			if (cp < 0)
			{
				break;
			}
			
			upper[mid] = upper[right];
			upper.pop_back();
		}
	}

	//计算下部分凸包
	vector<Point> lower(P.rbegin(),P.rbegin()+2);
	for (int i=length-3; i>=0; --i)
	{
		lower.push_back(P[i]);
		while(lower.size()>=3)
		{
			int right = lower.size() - 1;
			int mid  = right - 1;
			int left = mid - 1;
			int cp = (lower[mid].x - lower[left].x) * (lower[right].y - lower[left].y)
				- (lower[mid].y - lower[left].y) * (lower[right].x - lower[left].x);

			if (cp < 0)
			{
				break;
			}

			lower[mid] = lower[right];
			lower.pop_back();			
		}
	}

	// 合并上下凸包	
	vector<Point> result(upper.begin(),upper.end());
	result.insert(result.end(),lower.begin()+1,lower.end()-1);

	return result;
}

TEST(Algo, tConvexHull)
{
	vector<Point> vecPoints;
		
	vecPoints.push_back(Point(3,9));
	vecPoints.push_back(Point(19,9));
	vecPoints.push_back(Point(19,12));
	vecPoints.push_back(Point(8,16));
	vecPoints.push_back(Point(1,10));
	vecPoints.push_back(Point(9,12));
	vecPoints.push_back(Point(11,5));
	vecPoints.push_back(Point(3,13));
	vecPoints.push_back(Point(11,16));
	vecPoints.push_back(Point(12,12));
	vecPoints.push_back(Point(6,4));
	vecPoints.push_back(Point(6,12));
	vecPoints.push_back(Point(15,4));
	vecPoints.push_back(Point(15,17));
	vecPoints.push_back(Point(13,18));
	vecPoints.push_back(Point(4,3));
	vecPoints.push_back(Point(5,17));
	vecPoints.push_back(Point(2,3));	
	vecPoints.push_back(Point(16,12));
	vecPoints.push_back(Point(2,15));
	vecPoints.push_back(Point(17,15));
	vecPoints.push_back(Point(18,6));
	
	vector<Point> result = ConvexHull(vecPoints);
}