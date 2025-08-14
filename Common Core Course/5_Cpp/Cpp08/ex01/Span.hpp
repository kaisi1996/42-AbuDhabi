#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iostream>

class Span
{
private:
	std::vector<int> vec;
	unsigned int N;

public:
	Span(unsigned int n);
	~Span();
	Span(const Span& src);
	Span& operator=(const Span& src);
	
	void addNumber(int x);
	int shortestSpan() const;
	int longestSpan() const;
	
	void multipleAdd(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	
	void printVec() const;
};


#endif