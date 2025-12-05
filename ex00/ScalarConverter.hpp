/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidrissi <sidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 10:44:17 by sidrissi          #+#    #+#             */
/*   Updated: 2025/12/05 16:25:08 by sidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <limits>
#include <cmath>

enum	LiteralType
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	SPECIAL_FLOAT,
	SPECIAL_DOUBLE,
	INVALID
};

LiteralType	detectType(std::string s);

class	ScalarConverter
{
	public:
		~ScalarConverter();
		ScalarConverter();
		static void	convert(std::string s);
};
bool	isInt(std::string s);
bool	isFloat(std::string s);
bool	isDouble(std::string s);
#endif