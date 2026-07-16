#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{
}

PmergeMe::PmergeMe(PmergeMe const &other)
{
	*this = other;
}

PmergeMe::~PmergeMe(void)
{
}

PmergeMe &PmergeMe::operator=(PmergeMe const &other)
{
	(void)other;
	return *this;
}

static void insertSortedVector(std::vector<int> &sorted, int value)
{
	std::vector<int>::size_type low;
	std::vector<int>::size_type high;

	low = 0;
	high = sorted.size();
	while (low < high)
	{
		std::vector<int>::size_type middle = low + (high - low) / 2;

		if (sorted[middle] < value)
			low = middle + 1;
		else
			high = middle;
	}
	sorted.insert(sorted.begin() + low, value);
}

std::vector<int> PmergeMe::sortVector(std::vector<int> const &input) const
{
	std::vector<int> winners;
	std::vector<int> pending;
	std::vector<int> sorted;
	bool hasOdd;
	int oddValue;

	if (input.size() < 2)
		return input;
	hasOdd = input.size() % 2 != 0;
	oddValue = hasOdd ? input[input.size() - 1] : 0;
	for (std::vector<int>::size_type i = 0; i + 1 < input.size(); i += 2)
	{
		if (input[i] < input[i + 1])
		{
			pending.push_back(input[i]);
			winners.push_back(input[i + 1]);
		}
		else
		{
			pending.push_back(input[i + 1]);
			winners.push_back(input[i]);
		}
	}
	sorted = sortVector(winners);
	if (hasOdd)
		insertSortedVector(sorted, oddValue);
	for (std::vector<int>::size_type i = 0; i < pending.size(); ++i)
		insertSortedVector(sorted, pending[i]);
	return sorted;
}

static void insertSortedList(std::list<int> &sorted, int value)
{
	std::list<int>::iterator it;

	it = sorted.begin();
	while (it != sorted.end() && *it < value)
		++it;
	sorted.insert(it, value);
}

std::list<int> PmergeMe::sortList(std::list<int> const &input) const
{
	std::list<int> winners;
	std::list<int> pending;
	std::list<int> sorted;
	std::list<int>::const_iterator it;
	bool hasOdd;
	int oddValue;

	if (input.size() < 2)
		return input;
	hasOdd = input.size() % 2 != 0;
	oddValue = 0;
	it = input.begin();
	while (it != input.end())
	{
		int first = *it;

		++it;
		if (it == input.end())
		{
			oddValue = first;
			break;
		}
		if (first < *it)
		{
			pending.push_back(first);
			winners.push_back(*it);
		}
		else
		{
			pending.push_back(*it);
			winners.push_back(first);
		}
		++it;
	}
	sorted = sortList(winners);
	if (hasOdd)
		insertSortedList(sorted, oddValue);
	for (it = pending.begin(); it != pending.end(); ++it)
		insertSortedList(sorted, *it);
	return sorted;
}
