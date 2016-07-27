#include <iostream>
using namespace std;

#define LIMIT 8
#define N 5
#define MIN 1

struct object {
	char name[20];
	int size;
	int price;
};

int Calc()
{
	int item[LIMIT+1] = {0};
	int value[LIMIT+1] = {0};
	int newvalue, i, s, p;

	object a[] = 
	{
		{"李子", 4, 4500},
		{"苹果", 5, 5700},
		{"橘子", 2, 2250},
		{"草莓", 1, 1100},
		{"甜瓜", 6, 6700}
	};

	for (int i=0; i < N; i++)
	{
		for (int s = a[i].size; s <= LIMIT; s++)
		{
			p = s - a[i].size;
			newvalue = value[p] + a[i].price;
			if (newvalue > value[s])
			{
				value[s] = newvalue;
				item[s] = i;
			}
		}
	}
}