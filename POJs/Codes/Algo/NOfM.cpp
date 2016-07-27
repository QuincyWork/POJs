#include <gtest/gtest.h>
using namespace std;

void ShowResult(int data[], int N)
{
	for (int i=0; i<N; i++)
	{
		cout << data[i] << " ";
	}
	cout << endl;
}

int GenerateMFromN(int N, int M)
{    
    int nCount = 0;    
    if (M==0)
    {
        return 1;
    }

    int* State = new int[M];
    for (int i=0; i<M; i++)
    {
        State[i] = i+1;
    }

    nCount++;
    ShowResult(State, M);

    int nPos = M-1;

    while (State[0] < N-M+1)
    {        
        if (State[M-1] == N)
        {
            nPos--;
        }
        else
        {
            nPos = M-1;
        }

        State[nPos]++;

        for (int i = nPos+1; i < M; i++)
        {
            State[i] = State[i-1] + 1;
        }

        ShowResult(State, M);
        nCount++;
    }

    delete [] State;

    return nCount;
}

TEST(Algo, tGenerateMFromN)
{
    // 3选0组合 3!/(0!*(3)!) = 1
    ASSERT_EQ(GenerateMFromN(3,0), 1);

    // 5选3组合 5!/(3!*(5-3)!) = 10
    ASSERT_EQ(GenerateMFromN(5,3), 10);

    // 5选5组合 5!/(5!*8!) = 1
    ASSERT_EQ(GenerateMFromN(5,5), 1);

    // 10选2组合 10!/(2!*8!) = 45
    ASSERT_EQ(GenerateMFromN(10,2), 45);
}