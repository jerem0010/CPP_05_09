#ifndef RPN_HPP
# define RPN_HPP

# include <string>

class RPN
{
	public:
		RPN(void);
		RPN(RPN const &other);
		~RPN(void);

		RPN &operator=(RPN const &other);

		int evaluate(std::string const &expression) const;
};

#endif
