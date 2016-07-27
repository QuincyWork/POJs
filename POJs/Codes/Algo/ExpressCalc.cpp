#include <gtest/gtest.h>
#include <memory>

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
	int* pStack = new int[infixExp.size()];

	int nTop = -1;

	for (string::size_type i=0; i < infixExp.size(); i++)
	{
		char cValue = infixExp[i];
		switch (cValue)
		{
		case '(':
			{
				pStack[++nTop] = cValue;
			}
			break;

		case ')':
			{
				while ( (nTop >= 0) && pStack[nTop] != '(')
				{
					postfixExp += pStack[nTop];
					--nTop;
				}
				// not find '(', express is invalid.
				if (nTop < 0)
				{
					delete[] pStack;
					return false;
				}

				--nTop;
			}
			break;

		case '+':
		case '-':
		case '*':
		case '/':
			{
				while ( (nTop >= 0) &&
					GetOperatorPrior(pStack[nTop]) >= GetOperatorPrior(cValue))
				{
					postfixExp += pStack[nTop];
					--nTop;
				}

				pStack[++nTop] = cValue;
			}
			break;

		default:
			postfixExp += cValue;
			break;
		}
	}

	while (nTop >= 0)
	{
		postfixExp += pStack[nTop--];
	}

	delete[] pStack;

	return true;
}

bool CalcValue(double v1, double v2, double& value, char express)
{	
	bool bResult = true;
	switch (express)
	{
	case '+':
		value = v1 + v2;		
		break;

	case '-':
		value = v1 - v2;
		break;

	case '*':
		value = v1 * v2;
		break;

	case '/':
		if (fabs(v2) < 1e-15)
		{
			return false;
		}

		value = v1 / v2;
		break;

	default:
		bResult = false;
		break;
	}

	return bResult;
}

bool ExpressCalc(const string& express, double& value)
{
	string PostfixExpress;
	if (!ConvertToPostfix(express, PostfixExpress))
	{
		return false;
	}

	double* OperandStack = new double[PostfixExpress.size()];
	int nTop = -1;

	for (string::size_type i = 0; i < PostfixExpress.size(); ++i)
	{
		char cValue = PostfixExpress[i];
		switch (cValue)
		{
		case '+':			
		case '-':
		case '*':
		case '/':
			{
				// Operand not enough
				if (nTop < 1)
				{
					delete[] OperandStack;
					return false;
				}

				double dResult;
				if (!CalcValue(OperandStack[nTop-1], OperandStack[nTop], dResult, cValue))
				{
					delete[] OperandStack;
					return false;
				}

				OperandStack[nTop-1] = dResult;
				--nTop;
			}
			break;

		default:
			if (cValue < '0' && cValue > '9')
			{
				delete[] OperandStack;
				return false;	
			}
			OperandStack[++nTop] = cValue - '0';

			break;
		}
	}

	if (nTop >= 1)
	{
		delete[] OperandStack;
		return false;
	}

	value = OperandStack[0];
	delete[] OperandStack;

	return true;
}

TEST(Algo, tExpressCalc)
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

	// 1+3*4+2/5 => 13.4
	double dResult = 0.0;
	ExpressCalc("1+3*4+2/5",dResult);
	ASSERT_DOUBLE_EQ(13.4,dResult);

	// (4+6)*1/9+7 => 8.1111111111111111111111111111111
	ExpressCalc("(4+6)*1/9+7",dResult);
	ASSERT_DOUBLE_EQ(8.1111111111111111111111111111111,dResult);

	// ((5)+2*(1-7)+3/8)*4 => -26.5
	ExpressCalc("((5)+2*(1-7)+3/8)*4",dResult);
	ASSERT_DOUBLE_EQ(-26.5,dResult);
}