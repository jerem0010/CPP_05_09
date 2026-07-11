#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <cstddef>
# include <exception>

template <typename T>
class Array
{
	public:
		class OutOfBoundsException : public std::exception
		{
			public:
				virtual const char *what(void) const throw()
				{
					return "Array index out of bounds";
				}
		};

		Array(void) : _data(NULL), _size(0)
		{
		}

		Array(unsigned int n) : _data(NULL), _size(n)
		{
			if (_size > 0)
				_data = new T[_size]();
		}

		Array(Array const &other) : _data(NULL), _size(0)
		{
			*this = other;
		}

		~Array(void)
		{
			delete[] _data;
		}

		Array &operator=(Array const &other)
		{
			T *copy = NULL;

			if (this == &other)
				return *this;
			if (other._size > 0)
			{
				copy = new T[other._size]();
				for (unsigned int i = 0; i < other._size; ++i)
					copy[i] = other._data[i];
			}
			delete[] _data;
			_data = copy;
			_size = other._size;
			return *this;
		}

		T &operator[](unsigned int index)
		{
			if (index >= _size)
				throw OutOfBoundsException();
			return _data[index];
		}

		T const &operator[](unsigned int index) const
		{
			if (index >= _size)
				throw OutOfBoundsException();
			return _data[index];
		}

		unsigned int size(void) const
		{
			return _size;
		}

	private:
		T *_data;
		unsigned int _size;
};

#endif
