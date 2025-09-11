/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 15:07:32 by aberenge          #+#    #+#             */
/*   Updated: 2025/09/11 15:24:43 by aberenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void) other;
}

ScalarConverter& ScalarConverter::operator=(
	const ScalarConverter& other)
{
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter() {}


bool	ScalarConverter::isChar(const std::string& literal)
{
	if (literal.length() != 3)
		return (false);
	if (literal[0] == '\'' && literal[2] == '\'')
		return (true);
	return (false);
}

bool	ScalarConverter::isInt(const std::string& literal)
{
	if (literal.empty())
		return (false);
	size_t	start = 0;
	if (literal[0] == '+' || literal[0] == '-')
		start++;
	if (start == literal.length())
		return (false);
	for (size_t i = start; i < literal.length(); i++)
	{
		if (!std::isdigit(literal[i]))
			return (false);
	}
	return (true);
}

bool	ScalarConverter::isFloat(const std::string& literal)
{
	if (literal.length() < 2 || literal[literal.length() - 1] != 'f')
		return (false);
	std::string	without_f = literal.substr(0, literal.length() - 1);
	if (without_f.empty())
		return (false);
	size_t	start = 0;
	if (without_f[0] == '+' || without_f[0] == '-')
		start++;
	bool	has_dot = false;
	for (size_t i = start; i < without_f.length(); i++)
	{
		if (without_f[i] == '.')
		{
			if (has_dot)
				return (false);
			has_dot = true;
		}
		else if (!std::isdigit(without_f[i]))
			return (false);
	}
	return (has_dot);
}

bool	ScalarConverter::isDouble(const std::string &literal)
{
	if (literal.empty())
		return (false);

	size_t start = 0;
	if (literal[0] == '+' || literal[0] == '-')
		start = 1;

	bool hasDot = false;
	for (size_t i = start; i < literal.length(); i++)
	{
		if (literal[i] == '.')
		{
			if (hasDot)
				return (false);
			hasDot = true;
		}
		else if (!std::isdigit(literal[i]))
			return (false);
	}
	return (hasDot);
}

bool ScalarConverter::isSpecial(const std::string& literal)
{
	return (literal == "nan" || literal == "+inf"
		|| literal == "-inf" || literal == "nanf"
		|| literal == "+inff" || literal == "-inff");
}


static void printChar(double value)
{
	std::cout << "char: ";
	if (std::isnan(value) || std::isinf(value))
		std::cout << "impossible" << std::endl;
	else if (value < 0 || value > 127)
		std::cout << "impossible" << std::endl;
	else if (value < 32 || value == 127)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(value)
			<< "'" << std::endl;
}

static void printInt(double value)
{
	std::cout << "int: ";
	if (std::isnan(value) || std::isinf(value))
		std::cout << "impossible" << std::endl;
	else if (value < INT_MIN || value > INT_MAX)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(value) << std::endl;
}

static void printFloat(double value)
{
	std::cout << "float: ";
	if (std::isnan(value))
		std::cout << "nanf" << std::endl;
	else if (std::isinf(value))
	{
		if (value > 0)
			std::cout << "+inff" << std::endl;
		else
			std::cout << "-inff" << std::endl;
	}
	else
	{
		float f = static_cast<float>(value);
		std::cout << f;
		if (f == static_cast<int>(f))
			std::cout << ".0";
		std::cout << "f" << std::endl;
	}
}

static void printDouble(double value)
{
	std::cout << "double: ";
	if (std::isnan(value))
		std::cout << "nan" << std::endl;
	else if (std::isinf(value))
	{
		if (value > 0)
			std::cout << "+inf" << std::endl;
		else
			std::cout << "-inf" << std::endl;
	}
	else
	{
		std::cout << value;
		if (value == static_cast<int>(value))
			std::cout << ".0";
		std::cout << std::endl;
	}
}


void	ScalarConverter::convert(const std::string& literal)
{
	double	value;

	if (isSpecial(literal))
	{
		if (literal == "nan" || literal == "nanf")
			value = std::numeric_limits<double>::quiet_NaN();
		else if (literal == "+inf" || literal == "+inff")
			value = std::numeric_limits<double>::infinity();
		else if (literal == "-inf" || literal == "-inff")
			value = -std::numeric_limits<double>::infinity();
	}
	else if (isChar(literal))
		value = static_cast<double>(literal[1]);
	else if (isInt(literal))
		value = static_cast<double>(atoi(literal.c_str()));
	else if (isFloat(literal))
		value = static_cast<double>(atof(literal.c_str()));
	else if (isDouble(literal))
		value = atof(literal.c_str());
	else
	{
		std::cout << "Error : Invalid  literal" << std::endl;
		return ;
	}

	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);
}
