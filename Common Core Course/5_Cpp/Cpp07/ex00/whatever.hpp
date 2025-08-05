#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include<iostream>

template<typename T1>
void swap(T1 &a, T1 &b)
{
	T1 tmp = a;
	a = b;
	b = tmp;
}

template<typename T2>
T2 min(const T2 &a, const T2 &b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

template<typename T3>
T3 max(const T3 &a, const T3 &b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

#endif