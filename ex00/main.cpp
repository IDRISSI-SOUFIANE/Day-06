/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidrissi <sidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 10:44:28 by sidrissi          #+#    #+#             */
/*   Updated: 2025/12/06 10:18:49 by sidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <sstream>

bool isSpecialFloat(std::string s)
{
	return (s == "nanf" || s == "+inff" || s == "-inff");
}

bool isSpecialDouble(std::string s)
{
	return (s == "nan" || s == "+inf" || s == "-inf");
}

bool isInt(std::string s)
{
	size_t i;

	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (i == s.length())
		return (false);
	for (; i < s.length(); i++)
	{
		if (!isdigit(s[i]))
			return (false);
	}
	return (true);
}
bool isDouble(std::string s)
{
	size_t i;
	bool dot;

	dot = false;
	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;

	if (i == s.length())
		return (false);

	for (; i < s.length(); i++)
	{
		if (s[i] == '.')
		{
			if (dot)
				return (false);
			dot = true;
		}
		else if (!std::isdigit(s[i]))
			return (false);
	}
	return (dot);
}

bool isFloat(std::string s)
{
	if (s[s.length() - 1] != 'f' && s[s.length() - 1] != 'F')
		return (false);
	std::string fl = s.substr(0, s.length() - 1);
	return isDouble(fl);
}

LiteralType detectType(std::string s)
{
	if (isSpecialFloat(s))
		return (SPECIAL_FLOAT);
	if (isSpecialDouble(s))
		return (SPECIAL_DOUBLE);
	if (s.length() == 1 && !std::isdigit(s[0]))
		return (CHAR);
	if (isInt(s))
		return (INT);
	if (isFloat(s))
		return (FLOAT);
	if (isDouble(s))
		return (DOUBLE);
	return (INVALID);
}

int main(int ac, char **av)
{
	if (ac != 2 || av[1][0] == '\0')
		return (1);

	ScalarConverter::convert(av[1]);

	return (0);
}

// if (ft_check(av[1]) == 1337)
// return ( std::cout << "enter valid input: \n",  1);

/**
 * the float take 4 bytes
 * the int take 4 bytes
 * string how many bytes reserve??
 */

/*
stataic cast how its work

and read mantissa for nan nanff nanf // how represent in memory
*/