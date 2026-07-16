#include "Span.hpp"
#include <algorithm>

static unsigned int getDistance(int low, int high)
{
	return static_cast<unsigned int>(high) - static_cast<unsigned int>(low);
}

const char *Span::FullSpanException::what(void) const throw()
{
	return "Span is full";
}

const char *Span::NoSpanException::what(void) const throw()
{
	return "Not enough numbers to calculate a span";
}

Span::Span(void) : _maxSize(0), _numbers()
{
}

Span::Span(unsigned int n) : _maxSize(n), _numbers()
{
}

Span::Span(Span const &other) : _maxSize(0), _numbers()
{
	*this = other;
}

Span::~Span(void)
{
}

Span &Span::operator=(Span const &other)
{
	if (this != &other)
	{
		_maxSize = other._maxSize;
		_numbers = other._numbers;
	}
	return *this;
}

void Span::addNumber(int number)
{
	if (_numbers.size() >= _maxSize)
		throw FullSpanException();
	_numbers.push_back(number);
}

unsigned int Span::shortestSpan(void) const
{
	std::vector<int> sorted;
	unsigned int shortest;

	if (_numbers.size() < 2)
		throw NoSpanException();
	sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());
	shortest = getDistance(sorted[0], sorted[1]);
	for (std::vector<int>::size_type i = 2; i < sorted.size(); ++i)
	{
		unsigned int current;

		current = getDistance(sorted[i - 1], sorted[i]);
		if (current < shortest)
			shortest = current;
	}
	return shortest;
}

unsigned int Span::longestSpan(void) const
{
	std::vector<int>::const_iterator min;
	std::vector<int>::const_iterator max;

	if (_numbers.size() < 2)
		throw NoSpanException();
	min = std::min_element(_numbers.begin(), _numbers.end());
	max = std::max_element(_numbers.begin(), _numbers.end());
	return getDistance(*min, *max);
}
