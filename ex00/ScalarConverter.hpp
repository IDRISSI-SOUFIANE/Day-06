/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidrissi <sidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 10:44:17 by sidrissi          #+#    #+#             */
/*   Updated: 2025/12/04 10:41:48 by sidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <limits>

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
		ScalarConverter(std::string str);
		ScalarConverter(ScalarConverter const& other);
		ScalarConverter &operator=(ScalarConverter const& other);
		static void	convert(std::string s);
};

#endif