#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void swap(T &first, T &second)
{
	T tmp = first;

	first = second;
	second = tmp;
}

template <typename T>
T const &min(T const &first, T const &second)
{
	if (first < second)
		return first;
	return second;
}

template <typename T>
T const &max(T const &first, T const &second)
{
	if (first > second)
		return first;
	return second;
}

#endif
