#include <gtest/gtest.h>
#include <map>
#include <strstream>
#include <Util.h>
using namespace std;

class NumMatrix1 
{
public:
    NumMatrix1(vector<vector<int>> matrix) {
        
		m_matrix = matrix;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
		if (row1 > row2 ||
			col1 > col2 ||
			row1 < 0 ||
			col1 < 0)
		{
			return 0;
		}	

		stringstream ss;
		ss << row1 << "," << col1 << "," << row2 << "," << col2;

		if (m_cache.count(ss.str()))
		{
			return m_cache[ss.str()];
		}
		
		int value = 0;
		if (row1 <= row2)
		{
			for (int i=col1;i<=col2;++i)
			{
				value += m_matrix[row1][i];
			}
		}		
		++row1;

		if(col1 <= col2)
		{
			for (int i=row1;i<=row2;++i)
			{
				value += m_matrix[i][col1];
			}
		}
		++col1;

		value += sumRegion(row1,col1,row2,col2);

		m_cache[ss.str()] = value;

		return value;
    }

	vector<vector<int>> m_matrix;
	map<string,int>     m_cache;
};

class NumMatrix 
{
public:
    NumMatrix(vector<vector<int>> matrix) {
        
		row = matrix.size();
		col = row > 0 ? matrix[0].size() : 0;
		cache = vector<vector<int>>(row+1,vector<int>(col+1,0));

		for (int i=1; i <= row; ++i)
		{
			for (int j=1; j<=col; ++j)
			{
				cache[i][j] = matrix[i-1][j-1] + cache[i][j-1] + cache[i-1][j] - cache[i-1][j-1];
			}
		}
    }

	int sumRegion(int row1, int col1, int row2, int col2)
	{
		if (row2 >= row ||
			col2 >= col)
		{
			return 0;
		}

		return cache[row2+1][col2+1] - cache[row1][col2+1] - cache[row2+1][col1]
			+ cache[row1][col1];
	}

private:
	int row;
	int col;
	vector<vector<int>> cache;
};

TEST(LeetCode,tNumMatrix)
{
	vector<vector<int>> m;
	m.push_back(V(5,3,0,1,4,2));
	m.push_back(V(5,5,6,3,2,1));
	m.push_back(V(5,1,2,0,1,5));
	m.push_back(V(5,4,1,0,1,7));
	m.push_back(V(5,1,0,3,0,5));

	NumMatrix nm(m);
	ASSERT_EQ(nm.sumRegion(2,1,4,3),8);
	ASSERT_EQ(nm.sumRegion(1,1,2,2),11);
	ASSERT_EQ(nm.sumRegion(1,2,2,4),12);
	
	vector<vector<int>> v1;
	NumMatrix nm1(v1);
	ASSERT_EQ(nm1.sumRegion(0,0,0,0),0);
}
