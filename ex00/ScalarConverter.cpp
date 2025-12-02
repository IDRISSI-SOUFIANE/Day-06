/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidrissi <sidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 10:44:24 by sidrissi          #+#    #+#             */
/*   Updated: 2025/12/02 11:14:32 by sidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(std::string str) : str(str)
{}

ScalarConverter::~ScalarConverter()
{}

ScalarConverter::ScalarConverter(ScalarConverter const& other)
{
	str = other.str;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const& other)
{
	if (this != &other)
		str = other.str;
	return (*this);
}


void	ScalarConverter::convert(std::string str)
{
	
}