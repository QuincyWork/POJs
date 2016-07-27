#include <gtest/gtest.h>
#include <stack>
using namespace std;

class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        
		stack<int> temp;
		int size = m_data.size();
		while (size--)
		{			
			temp.push(m_data.top());
			m_data.pop();
		}

		m_data.push(x);
		size = temp.size();
		while (size--)
		{
			m_data.push(temp.top());
			temp.pop();
		}
    }

    // Removes the element from in front of queue.
    void pop(void) {
        
		m_data.pop();
    }

    // Get the front element.
    int peek(void) {
        
		return m_data.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        
		return m_data.empty();
    }

private:

	stack<int> m_data;
};

TEST(Pratices, tQueue)
{
	Queue q;
	q.push(1);
	q.push(2);
	q.push(3);
	ASSERT_EQ(q.peek(),1);
	q.pop();
	ASSERT_EQ(q.peek(),2);
	ASSERT_FALSE(q.empty());
	q.pop();
}