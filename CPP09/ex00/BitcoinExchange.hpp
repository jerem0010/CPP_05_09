#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <string>

class BitcoinExchange
{
	public:
		BitcoinExchange(void);
		BitcoinExchange(BitcoinExchange const &other);
		~BitcoinExchange(void);

		BitcoinExchange &operator=(BitcoinExchange const &other);

		void processFile(std::string const &filename) const;

	private:
		std::map<std::string, double> _rates;

		void loadDatabase(std::string const &filename);
		double getRate(std::string const &date) const;
};

#endif
