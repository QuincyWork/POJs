#include <gtest/gtest.h>
#include <stack>
using namespace std;

class MinStack {
public:
    void push(int x) {
        
		int min = x;
		if (!minStack.empty())
		{
			min = x < minStack.top() ? x : minStack.top();
		}

		dataStack.push(x);
		minStack.push(min);
    }

    void pop() {
        
		if (!dataStack.empty())
			dataStack.pop();

		if (!minStack.empty())
			minStack.pop();
    }

    int top() {
        
		int v = 0;
		if (!dataStack.empty())
			v = dataStack.top();

		return v;
    }

    int getMin() {
        
		int v = numeric_limits<int>::min();
		if (!minStack.empty())
			v = minStack.top();

		return v;
    }

private:

	stack<int> dataStack;
	stack<int> minStack;
};

TEST(Pratices, tMinStack)
{
	MinStack t1;
	t1.pop();

	t1.push(1);
	t1.push(10);
	t1.push(-1);

	ASSERT_EQ(t1.getMin(),-1);
}