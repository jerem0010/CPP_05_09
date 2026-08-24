#include "ScalarConverter.hpp"

#include <cctype>
#include <cerrno>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>

namespace {
    bool isPseudoLiteral(const std::string& literal, double& value) {
        if (literal == "nan" || literal == "nanf") {
            value = std::numeric_limits<double>::quiet_NaN();
            return true;
        }
        if (literal == "+inf" || literal == "+inff") {
            value = std::numeric_limits<double>::infinity();
            return true;
        }
        if (literal == "-inf" || literal == "-inff") {
            value = -std::numeric_limits<double>::infinity();
            return true;
        }
        return false;
    }

    bool parseNumber(const std::string& literal, double& value) {
        std::string number = literal;
        char* end = 0;

        if (number.size() > 1 && number[number.size() - 1] == 'f')
            number.erase(number.size() - 1);
        if (number.empty())
            return false;
        errno = 0;
        value = std::strtod(number.c_str(), &end);
        return end != number.c_str() && *end == '\0' && errno != ERANGE;
    }

    void printFloating(double value, bool isFloat) {
        if (std::floor(value) == value)
            std::cout << std::fixed << std::setprecision(1) << value;
        else
            std::cout << value;
        std::cout.unsetf(std::ios::floatfield);
        if (isFloat)
            std::cout << 'f';
        std::cout << std::endl;
    }

    void printConversions(double value) {
        if (!std::isfinite(value) || value < 0.0 || value > 127.0)
            std::cout << "char: impossible" << std::endl;
        else {
            char character = static_cast<char>(value);
            if (std::isprint(static_cast<unsigned char>(character)))
                std::cout << "char: '" << character << "'" << std::endl;
            else
                std::cout << "char: Non displayable" << std::endl;
        }

        if (!std::isfinite(value)
            || value < static_cast<double>(INT_MIN)
            || value > static_cast<double>(INT_MAX))
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(value) << std::endl;

        if (std::isfinite(value)
            && (value < -static_cast<double>(std::numeric_limits<float>::max())
                || value > static_cast<double>(std::numeric_limits<float>::max())))
            std::cout << "float: impossible" << std::endl;
        else {
            std::cout << "float: ";
            printFloating(static_cast<float>(value), true);
        }
        std::cout << "double: ";
        printFloating(value, false);
    }
}

void ScalarConverter::convert(const std::string& literal) {
    double value = 0.0;

    if (literal.size() == 1
        && !std::isdigit(static_cast<unsigned char>(literal[0]))) {
        value = static_cast<double>(literal[0]);
        printConversions(value);
        return;
    }
    if (isPseudoLiteral(literal, value) || parseNumber(literal, value)) {
        if (literal.size() > 1 && literal[literal.size() - 1] == 'f'
            && !isPseudoLiteral(literal, value))
            value = static_cast<double>(static_cast<float>(value));
        printConversions(value);
        return;
    }
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}
