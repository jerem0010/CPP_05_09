#include "MutantStack.hpp"
#include <iostream>
#include <list>

template <typename T>
void printContainer(T const &container)
{
	typename T::const_iterator it;

	for (it = container.begin(); it != container.end(); ++it)
		std::cout << *it << std::endl;
}

int main(void)
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	printContainer(mstack);

	std::stack<int> copy(mstack);
	std::cout << "stack copy size: " << copy.size() << std::endl;

	std::list<int> list;
	list.push_back(5);
	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	list.push_back(0);
	printContainer(list);

	return 0;
}
