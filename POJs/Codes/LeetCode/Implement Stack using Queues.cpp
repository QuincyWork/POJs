#include <gtest\gtest.h>
#include <queue>
using namespace std;

class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
     
		int size = m_data.size();
		m_data.push(x);
		
		while (size--)
		{
			int val = m_data.front();
			m_data.pop();
			m_data.push(val);
		}
    }

    // Removes the element on top of the stack.
    void pop() {
     
		m_data.pop();
    }

    // Get the top element.
    int top() {
        
		return m_data.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        
		return m_data.empty();
    }

private:

	queue<int> m_data;
};

TEST(Pratices, tStack)
{
	Stack data;
	data.push(1);
	data.push(2);
	data.push(3);

	ASSERT_EQ(data.top(),3);
	data.pop();
	ASSERT_EQ(data.top(),2);
	data.push(4);
	ASSERT_EQ(data.top(),4);
}