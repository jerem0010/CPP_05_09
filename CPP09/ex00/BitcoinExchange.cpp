#include "BitcoinExchange.hpp"

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>

static std::string trim(std::string const &value)
{
	std::string::size_type start;
	std::string::size_type end;

	start = value.find_first_not_of(" \t\r\n");
	if (start == std::string::npos)
		return "";
	end = value.find_last_not_of(" \t\r\n");
	return value.substr(start, end - start + 1);
}

static bool isLeapYear(int year)
{
	if (year % 400 == 0)
		return true;
	if (year % 100 == 0)
		return false;
	return year % 4 == 0;
}

static bool isValidDate(std::string const &date)
{
	int year;
	int month;
	int day;
	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;
	for (std::string::size_type i = 0; i < date.length(); ++i)
	{
		if (i != 4 && i != 7 && (date[i] < '0' || date[i] > '9'))
			return false;
	}
	year = std::atoi(date.substr(0, 4).c_str());
	month = std::atoi(date.substr(5, 2).c_str());
	day = std::atoi(date.substr(8, 2).c_str());
	if (month < 1 || month > 12 || day < 1)
		return false;
	if (month == 2 && isLeapYear(year))
		daysInMonth[1] = 29;
	return day <= daysInMonth[month - 1];
}

static bool parseNumber(std::string const &text, double &number)
{
	char *end;
	std::string trimmed;

	trimmed = trim(text);
	if (trimmed.empty())
		return false;
	number = std::strtod(trimmed.c_str(), &end);
	return *end == '\0';
}

BitcoinExchange::BitcoinExchange(void) : _rates()
{
	loadDatabase("data.csv");
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &other) : _rates()
{
	*this = other;
}

BitcoinExchange::~BitcoinExchange(void)
{
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &other)
{
	if (this != &other)
		_rates = other._rates;
	return *this;
}

void BitcoinExchange::loadDatabase(std::string const &filename)
{
	std::ifstream file(filename.c_str());
	std::string line;

	if (!file)
		throw std::runtime_error("could not open database.");
	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::string::size_type comma;
		std::string date;
		double rate;

		comma = line.find(',');
		if (comma == std::string::npos)
			continue;
		date = trim(line.substr(0, comma));
		if (!isValidDate(date) || !parseNumber(line.substr(comma + 1), rate))
			continue;
		_rates[date] = rate;
	}
	if (_rates.empty())
		throw std::runtime_error("empty database.");
}

double BitcoinExchange::getRate(std::string const &date) const
{
	std::map<std::string, double>::const_iterator it;

	it = _rates.upper_bound(date);
	if (it == _rates.begin())
		throw std::runtime_error("bad input => " + date);
	--it;
	return it->second;
}

void BitcoinExchange::processFile(std::string const &filename) const
{
	std::ifstream file(filename.c_str());
	std::string line;

	if (!file)
		throw std::runtime_error("could not open file.");
	if (std::getline(file, line) && trim(line) != "date | value")
	{
		file.clear();
		file.seekg(0);
	}
	while (std::getline(file, line))
	{
		std::string::size_type separator;
		std::string date;
		std::string valueText;
		double value;

		separator = line.find('|');
		if (separator == std::string::npos)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		date = trim(line.substr(0, separator));
		valueText = trim(line.substr(separator + 1));
		if (!isValidDate(date) || !parseNumber(valueText, value))
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		if (value < 0)
			std::cout << "Error: not a positive number." << std::endl;
		else if (value > 1000)
			std::cout << "Error: too large a number." << std::endl;
		else
		{
			try
			{
				std::cout << date << " => " << value << " = "
					<< value * getRate(date) << std::endl;
			}
			catch (std::exception const &error)
			{
				std::cout << "Error: " << error.what() << std::endl;
			}
		}
	}
}
