/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidrissi <sidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 10:44:24 by sidrissi          #+#    #+#             */
/*   Updated: 2025/12/05 09:31:05 by sidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}

void	printChar(double value)
{
	std::cout << "char: ";
	if (value != value || value < 0 || value > 127)
	{
		std::cout << "impossible: \n";
		return ;
	}

	char c = static_cast<char>(value);
	if (std::isprint(c))
		std::cout << "'" << c << "'\n" ;
	else
		std::cout << "Non displyable\n";
}

void	printInt(double value)
{
	std::cout << "int: ";
	if (value != value 
		|| value > std::numeric_limits<int>::max()
		|| value < std::numeric_limits<int>::min())
	{
		std::cout << "impossible\n";
		return ;
	}
	int i = static_cast<int>(value);
	std::cout << i << "\n";
}

void	printFloat(double value)
{
	std::cout << "float: ";
	float f = static_cast<float>(value);

	if (f - (int)f == 0)
		std::cout << f << ".0f\n";
	else
		std::cout << f << "f\n";
}

void	printDouble(double value)
{
	std::cout << "double: ";
	if (value - (int)value == 0)
		std::cout << value << ".0\n";
	else
		std::cout << value << "\n";
}

void	ScalarConverter::convert(std::string s)
{
	LiteralType type = detectType(s);

	double value = 0;
	switch (type)
	{
		case CHAR:
			value = s[0];
			break;
		case INT:
		{
			std::istringstream ss(s);
			int temp;
			ss >> temp;
			value = temp;
			break;
		}
		case FLOAT:
		{
			std::string fl = s.substr(0, s.length() - 1);
			std::istringstream ss(fl);
			float temp;
			ss >> temp;
			value = temp;
			break ;
		}
		case DOUBLE:
		{
			std::istringstream ss(s);
			double temp;
			ss >> temp;
			value = temp;
			break;
		}
		case SPECIAL_FLOAT:
		{
			if (s == "nanf")
				value = std::numeric_limits<float>::quiet_NaN();
			if (s == "+inff")
				value = std::numeric_limits<float>::infinity();
			if (s == "-inff")
				value = -std::numeric_limits<float>::infinity();
			break;
		}
		case SPECIAL_DOUBLE:
		{
			if (s == "nan")
				value = std::numeric_limits<double>::quiet_NaN();
			if (s == "+inf")
				value = std::numeric_limits<double>::infinity();
			if (s == "-inf")
				value = -std::numeric_limits<double>::infinity();
			break;
		}
		default:
			std::cout << "Invalid s\n";
			return ;
	}
	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);
}
