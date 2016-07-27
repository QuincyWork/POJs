#include <iostream>
#include <vector>
#include <algorithm>
#include <gtest/gtest.h>
using namespace std;

vector<int> EratosthenesPrime(int nSize)
{
	bool* Primes = new bool[nSize];
	memset(Primes, true, sizeof(bool)* nSize);

	for (int i=2; i * i <= nSize; ++i)
	{
		if (Primes[i])
		{
			for (int j = i*i; j < nSize; j+=i)
			{
				Primes[j] = false;
			}
		}
	}

	vector<int> Result;
	for (int i=2; i < nSize; ++i)
	{
		if (Primes[i])
		{
			Result.push_back(i);
		}
	}

	delete[] Primes;

	return Result;
}

TEST(Algo, tEratosthenesPrime)
{		
	vector<int> Result = EratosthenesPrime(100);
	cout << "N:100  " << Result.size() << endl;
	for (vector<int>::size_type i=0; i<Result.size(); ++i)
	{
		if (i % 16 == 0)
			cout << endl;

		cout << Result[i] << " ";
	}
	cout << endl << endl;
	
	Result = EratosthenesPrime(500);
	cout << "N:500  " << Result.size() << endl;
	for (vector<int>::size_type i=0; i<Result.size(); ++i)
	{
		if (i % 16 == 0)
			cout << endl;

		cout << Result[i] << " ";
	}
	cout << endl << endl;

	Result = EratosthenesPrime(1000);
	cout << "N:1000  " << Result.size() << endl;
	for (vector<int>::size_type i=0; i<Result.size(); ++i)
	{
		if (i % 16 == 0)
			cout << endl;

		cout << Result[i] << " ";
	}
	cout << endl << endl;
}