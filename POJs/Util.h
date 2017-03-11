#pragma once
#include <vector>
#include <string>
#include <stdarg.h>

class Vector
{
public:

	template<typename T>
	std::vector<T> operator() (int s,T p1, ...) const
	{
		std::vector<T> v;		
		va_list st;
		va_start(st,p1);
		v.push_back(p1);

		while (s-- > 1)
		{	
			v.push_back(va_arg(st, T));
		}
		
		va_end(st);

		return v;
	}
};

#define V Vector()
