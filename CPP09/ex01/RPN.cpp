#include "RPN.hpp"

#include <deque>
#include <sstream>
#include <stdexcept>

RPN::RPN(void)
{
}

RPN::RPN(RPN const &other)
{
	*this = other;
}

RPN::~RPN(void)
{
}

RPN &RPN::operator=(RPN const &other)
{
	(void)other;
	return *this;
}

static bool isOperator(std::string const &token)
{
	return token.length() == 1
		&& (token[0] == '+' || token[0] == '-'
			|| token[0] == '*' || token[0] == '/');
}

static int applyOperation(int left, int right, char operation)
{
	if (operation == '+')
		return left + right;
	if (operation == '-')
		return left - right;
	if (operation == '*')
		return left * right;
	if (right == 0)
		throw std::runtime_error("Error");
	return left / right;
}

int RPN::evaluate(std::string const &expression) const
{
	std::istringstream input(expression);
	std::deque<int> stack;
	std::string token;

	while (input >> token)
	{
		if (token.length() == 1 && token[0] >= '0' && token[0] <= '9')
			stack.push_back(token[0] - '0');
		else if (isOperator(token))
		{
			int right;
			int left;

			if (stack.size() < 2)
				throw std::runtime_error("Error");
			right = stack.back();
			stack.pop_back();
			left = stack.back();
			stack.pop_back();
			stack.push_back(applyOperation(left, right, token[0]));
		}
		else
			throw std::runtime_error("Error");
	}
	if (stack.size() != 1)
		throw std::runtime_error("Error");
	return stack.back();
}
