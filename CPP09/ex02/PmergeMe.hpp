#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <list>
# include <vector>

class PmergeMe
{
	public:
		PmergeMe(void);
		PmergeMe(PmergeMe const &other);
		~PmergeMe(void);

		PmergeMe &operator=(PmergeMe const &other);

		std::vector<int> sortVector(std::vector<int> const &input) const;
		std::list<int> sortList(std::list<int> const &input) const;
};

#endif
