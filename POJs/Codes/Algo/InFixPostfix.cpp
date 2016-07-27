#include <iostream>
#include <stack>
#include <algorithm>
#include <gtest/gtest.h>
using namespace std;

int GetOperatorPrior(char value)
{
	int nResult = 0;
	switch(value)
	{
	case '+':
	case '-':
		{
			nResult = 1;
		}
		break;

	case '*':
	case '/':
		{
			nResult = 2;
		}
		break;
	}

	return nResult;
}

bool ConvertToPostfix(const string& infixExp, string& postfixExp)
{
	postfixExp.clear();
	stack<int> Operators;
	for (string::size_type i = 0; i < infixExp.size(); ++i)
	{
		char cValue = infixExp[i];
		switch(cValue)
		{
		case '(':
			{
				Operators.push(cValue);
			}
			break;

		case ')':
			{
				while(!Operators.empty() && 
					(Operators.top() != '('))
				{
					postfixExp += Operators.top();
					Operators.pop();
				}

				Operators.pop();
			}
			break;

		case '+':
		case '-':
		case '*':
		case '/':
			{
				while (!Operators.empty() && 
					(GetOperatorPrior(Operators.top()) >= GetOperatorPrior(cValue)) )
				{
					postfixExp += Operators.top();
					Operators.pop();
				}

				Operators.push(cValue);
			}
			break;

		default:
			postfixExp += cValue;
			break;
		}
	}

	while(!Operators.empty())
	{
		postfixExp += Operators.top();
		Operators.pop();
	}

	return true;
}

bool ConvertToPrefix(const string& infixExp, string& prefixExp)
{
	prefixExp.clear();
	int* Stack = new int[infixExp.size()+1];
	int  nTop = 0;

	for (int i = infixExp.size() - 1; i >= 0; --i)
	{
		char cValue = infixExp[i];
		switch (cValue)
		{
		case ')':
			{				
				Stack[++nTop] = ')';				
			}
			break;

		case '(':
			{
				while (nTop &&
					Stack[nTop] != ')')
				{
					prefixExp += Stack[nTop];
					nTop--;
				}

				nTop--;
			}
			break;

		case '+':
		case '-':
		case '*':
		case '/':
			{
				while (nTop &&
					GetOperatorPrior(Stack[nTop]) >= GetOperatorPrior(cValue))
				{
					prefixExp += Stack[nTop];
					nTop--;
				}

				Stack[++nTop] = cValue;
			}
			break;

		default:
			prefixExp += cValue;
			break;
		}
	}

	while (nTop)
	{
		prefixExp += Stack[nTop--];
	}

	reverse(prefixExp.begin(), prefixExp.end());

	delete[] Stack;

	return true;
}

TEST(Algo, tInFixPostfix)
{
	//
	//	Postfix Convert
	//

	// a+b*d+c/d => abd*+cd/+
	string strResult;
	ConvertToPostfix("a+b*d+c/d",strResult);
	ASSERT_EQ("abd*+cd/+",strResult);

	// (a+b)*c/d+e => ab+c*d/e+
	ConvertToPostfix("(a+b)*c/d+e",strResult);
	ASSERT_EQ("ab+c*d/e+",strResult);

	// ((a)+b*(c-d)+e/f)*g => abcd-*+ef/g*
	ConvertToPostfix("((a)+b*(c-d)+e/f)*g",strResult);
	ASSERT_EQ("abcd-*+ef/+g*",strResult);

	//
	//	Prefix Convert
	//

	// a+b*d+c/d => +a+*bd/cd
	ConvertToPrefix("a+b*d+c/d",strResult);
	ASSERT_EQ("+a+*bd/cd",strResult);

	// (a+b)*c/d+e => +*+ab/cde
	ConvertToPrefix("(a+b)*c/d+e",strResult);
	ASSERT_EQ("+*+ab/cde",strResult);

	// ((a)+b*(c-d)+e/f)*g => *+a+*b-cd/efg
	ConvertToPrefix("((a)+b*(c-d)+e/f)*g",strResult);
	ASSERT_EQ("*+a+*b-cd/efg",strResult);

}