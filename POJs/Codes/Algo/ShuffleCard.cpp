#include <gtest/gtest.h>
#include <vector>
#include <time.h>
using namespace std;

void ShuffleCard(vector<int>& cards)
{
	srand(time(0));

	unsigned int nCount = cards.size();
	for (unsigned int i = 0; i < nCount; ++i)
	{
		int nRand = rand() % nCount;
		int nTemp = cards[i];
		cards[i] = cards[nRand];
		cards[nRand] = nTemp;
	}
}

void InitCard(vector<int>& cards)
{
	for (int i=1; i<=52; ++i)
	{
		cards.push_back(i);
	}
}

void ShowCard(const vector<int>& cards)
{
	unsigned int nCount = cards.size();
	for (unsigned int i = 0; i < nCount; ++i)
	{
		switch ((cards[i]-1) / 13)
		{
		case 0:
			wcout << L"ÌÒ";
			break;

		case 1:
			wcout << L"ÐÄ";
			break;

		case 2:
			wcout << L"×©";
			break;

		case 3:
			wcout << L"Ã·";
			break;
		}

		unsigned int nValue = cards[i] % 13;
		wcout << nValue << L" ";

		if ((i+1) % 13 == 0)
		{
			wcout << endl;
		}
	}

	wcout << endl;
}

TEST(Algo, tShuffleCard)
{
	vector<int> Cards;
	InitCard(Cards);
	ShuffleCard(Cards);
	ShowCard(Cards);

	ShuffleCard(Cards);
	ShowCard(Cards);
}