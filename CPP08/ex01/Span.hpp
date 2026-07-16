#ifndef SPAN_HPP
# define SPAN_HPP

# include <exception>
# include <vector>

class Span
{
	public:
		class FullSpanException : public std::exception
		{
			public:
				virtual const char *what(void) const throw();
		};

		class NoSpanException : public std::exception
		{
			public:
				virtual const char *what(void) const throw();
		};

		Span(void);
		Span(unsigned int n);
		Span(Span const &other);
		~Span(void);

		Span &operator=(Span const &other);

		void addNumber(int number);

		template <typename Iterator>
		void addNumbers(Iterator begin, Iterator end)
		{
			std::vector<int> values(begin, end);

			if (values.size() > _maxSize - _numbers.size())
				throw FullSpanException();
			_numbers.insert(_numbers.end(), values.begin(), values.end());
		}

		unsigned int shortestSpan(void) const;
		unsigned int longestSpan(void) const;

	private:
		unsigned int _maxSize;
		std::vector<int> _numbers;
};

#endif
