#include "Span.hpp"
	
Span::Span(unsigned int n) : N(n) {}

Span::~Span(){}

Span::Span(const Span& other)
{
	this->N = other.N;
	this->vec = other.vec;
}
Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		this->N = other.N;
		this->vec = other.vec;
	}
	return (*this);
}

void Span::addNumber(int x)
{
	
	if (this->vec.size() == this->N)
		throw std::logic_error("Span vector already full");
	if (this->vec.size() < this->N)
		this->vec.push_back(x);
}

int Span::shortestSpan() const
{
	if (vec.empty() || vec.size() == 1)
		throw std::out_of_range("Span vector has less than 2 values");
	
	std::vector<int>	tmpvec = vec;
	std::sort(tmpvec.begin(), tmpvec.end());
	int minspan = tmpvec[1] - tmpvec[0];
    int span;
	for (size_t i = 1; i < vec.size() - 1; ++i)
	{
		span = tmpvec[i + 1] - tmpvec[i];
		if (span < minspan)
			minspan = span;
	}
	return (minspan);
}

int Span::longestSpan() const
{
	if (vec.empty() || vec.size() == 1)
		throw std::out_of_range("Span vector has less than 2 values");
	std::vector<int>::const_iterator maxIt = std::max_element(vec.begin(), vec.end());
	std::vector<int>::const_iterator minIt = std::min_element(vec.begin(), vec.end());
	return (*maxIt - *minIt);
}

void Span::printVec() const
{
	if (vec.empty())
	{
		std::cout << "empty vector \n";
		return;
	}
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << "[" << vec[i] <<"] ";
	std::cout << std::endl;
}

void Span::multipleAdd(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (vec.size() + std::distance(begin, end) > this->N)
		throw std::out_of_range("ERROR : Range Filling would outgrow the Span instance");
	this->vec.insert(vec.begin(), begin, end);
}