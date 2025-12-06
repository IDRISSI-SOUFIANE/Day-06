/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidrissi <sidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 10:44:24 by sidrissi          #+#    #+#             */
/*   Updated: 2025/12/06 10:54:24 by sidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ScalarConverter.hpp"

// ScalarConverter::ScalarConverter()
// {
// }

// ScalarConverter::~ScalarConverter()
// {
// }

// void	printChar(double value)
// {
// 	std::cout << "char: ";
// 	if (value != value || value < 0 || value > 127) // condition ??
// 	{
// 		std::cout << "impossible \n";
// 		return ;
// 	}

// 	char c = static_cast<char>(value); // static_cast ??
// 	if (std::isprint(c))
// 		std::cout << "'" << c << "'\n" ;
// 	else
// 		std::cout << "Non displyable\n";
// }

// void	printInt(double value)
// {
// 	std::cout << "int: ";
// 	if (value != value 
// 		|| value > std::numeric_limits<int>::max()
// 		|| value < std::numeric_limits<int>::min())
// 	{
// 		std::cout << "impossible\n";
// 		return ;
// 	}
// 	int i = static_cast<int>(value);
// 	std::cout << i << "\n";
// }

// void	printFloat(double value)
// {
// 	std::cout << "float: ";
// 	float f = static_cast<float>(value);

// 	if (f - (int)f == 0)
// 		std::cout << f << ".0f\n";
// 	else
// 		std::cout << f << "f\n";
// }

// void	printDouble(double value)
// {
// 	std::cout << "double: ";
// 	if (value - (int)value == 0)
// 		std::cout << value << ".0\n";
// 	else
// 		std::cout << value << "\n";
// }

// bool	is_Int_Overflow(std::string s)
// {
// 	std::string t = s;
// 	int	i = 0;
// 	int	neg = 0;

// 	if (t[i] == '+' || t[i] == '-')
// 	{
// 		if (t[i] == '-')
// 			neg = 1;
// 		i++;
// 	}
// 	while (t.length() > 1 && t[0] == '0')
// 		t.erase(0, 1);
	
// 	if (t.length() > 10)
// 		return (false);
// 	if (t.length() < 10)
// 		return (true);
	
// 	if (!neg && t > "2147483647")
// 		return (false);
// 	if (neg && t > "2147483648")
// 		return (false);

// 	return (true);
// }

// // bool	is_float_Overflow(std::string s)
// // {
// // 	std::istringstream	ss(s);
// // 	float	fl;
// // 	ss >> fl;
// // 	return !(ss.fail() || fl == HUGE_VALF || fl == -HUGE_VALF);
// // }

// // bool	is_Double_Overlow(std::string s)
// // {
// // 	std::istringstream	ss(s);
// // 	double	db;
// // 	ss >> db;
// // 	return !(ss.fail() || db == HUGE_VAL || db == -HUGE_VAL);
// // }
// // Float max/min as strings
// const std::string FLOAT_MAX_STR = "340282346638528859811704183484516925440.0"; // 3.4028235e38
// const std::string FLOAT_MIN_STR = "0.0"; // not negative check here, we'll handle '-'

// // Double max/min as strings
// const std::string DOUBLE_MAX_STR = "179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0"; // 1.7976931348623157e308
// const std::string DOUBLE_MIN_STR = "0.0";

// // Helper: remove leading zeros
// std::string strip_leading_zeros(const std::string &s) {
//     size_t i = 0;
//     while (i < s.length() - 1 && s[i] == '0')
//         i++;
//     return s.substr(i);
// }

// // Compare two numeric strings (assumes positive numbers, no scientific notation)
// bool string_greater(const std::string &a, const std::string &b) {
//     std::string sa = strip_leading_zeros(a);
//     std::string sb = strip_leading_zeros(b);

//     if (sa.length() > sb.length())
//         return true;
//     if (sa.length() < sb.length())
//         return false;

//     return sa > sb; // lexicographical compare for same length
// }

// // Float overflow detection
// bool isFloat_Overflow(std::string s) {
//     bool neg = false;
//     if (s[0] == '-' || s[0] == '+') {
//         if (s[0] == '-')
//             neg = true;
//         s = s.substr(1);
//     }

// 	if (!s.empty() && s[s.length() - 1] == 'f')
//  		s.resize(s.length() - 1);

//     s = strip_leading_zeros(s);

//     if (neg)
//         return string_greater(s, "340282346638528859811704183484516925440.0"); // negative max = same
//     else
//         return string_greater(s, FLOAT_MAX_STR);
// }

// // Double overflow detection
// bool isDouble_Overflow(std::string s) {
//     bool neg = false;
//     if (s[0] == '-' || s[0] == '+') {
//         if (s[0] == '-')
//             neg = true;
//         s = s.substr(1);
//     }

//     s = strip_leading_zeros(s);

//     if (neg)
//         return string_greater(s, "179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0");
//     else
//         return string_greater(s, DOUBLE_MAX_STR);
// }

// void	ScalarConverter::convert(std::string s)
// {
// 	bool	int_Overlow = false;
// 	bool	float_Overlow = false;
// 	bool	double_Overlow = false;
	
// 	if (isInt(s) && !is_Int_Overflow(s))
// 		int_Overlow = true;
// 	// if (isFloat(s))
// 	// {
// 	// 	std::string f = s.substr(0, s.length() - 1);
// 	// 	if (!is_float_Overflow(f))
// 	// 		float_Overlow = true;
// 	// }
// 	// if (isDouble(s) && !is_Double_Overlow(s))
// 	// 	double_Overlow = true;
// 	if (isFloat(s)) {
//     if (isFloat_Overflow(s))
//         float_Overlow = true;
// 	}
// 	if (isDouble(s)) {
// 		if (isDouble_Overflow(s))
// 			double_Overlow = true;
// 	}

// 	LiteralType type = detectType(s);

// 	double value = 0;
// 	switch (type)
// 	{
// 		case CHAR:
// 			value = s[0];
// 			break;
// 		case INT:
// 		{
// 			std::istringstream ss(s);
// 			int temp;
// 			ss >> temp;
// 			value = temp;
// 			break;
// 		}
// 		case FLOAT:
// 		{
// 			std::string fl = s.substr(0, s.length() - 1);
// 			std::istringstream ss(fl);
// 			float temp;
// 			ss >> temp;
// 			value = temp;
// 			break ;
// 		}
// 		case DOUBLE:
// 		{
// 			std::istringstream ss(s);
// 			double temp;
// 			ss >> temp;
// 			value = temp;
// 			break;
// 		}
// 		case SPECIAL_FLOAT:
// 		{
// 			if (s == "nanf")
// 				value = std::numeric_limits<float>::quiet_NaN();
// 			if (s == "+inff")
// 				value = std::numeric_limits<float>::infinity();
// 			if (s == "-inff")
// 				value = -std::numeric_limits<float>::infinity();
// 			break;
// 		}
// 		case SPECIAL_DOUBLE:
// 		{
// 			if (s == "nan")
// 				value = std::numeric_limits<double>::quiet_NaN();
// 			if (s == "+inf")
// 				value = std::numeric_limits<double>::infinity();
// 			if (s == "-inf")
// 				value = -std::numeric_limits<double>::infinity();
// 			break;
// 		}
// 		default:
// 			std::cout << "Invalid s\n";
// 			return ;
// 	}
// 	printChar(value);
// 	if(int_Overlow)
// 		std::cout << "int: impossible\n";
// 	else
// 		printInt(value);

// 	if(float_Overlow)
// 		std::cout << "float: impossible\n";
// 	else
// 		printFloat(value);

// 	if(double_Overlow)
// 		std::cout << "double: impossible\n";
// 	else
// 		printDouble(value);

// }


/*

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
		std::cout << "impossible\n";
		return ;
	}

	char c = static_cast<char>(value);
	if (std::isprint(c))
		std::cout << "'" << c << "'\n";
	else
		std::cout << "Non displayable\n";
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

	if (f != f)
		std::cout << "nanf\n";
	else if (f == std::numeric_limits<float>::infinity())
		std::cout << "+inff\n";
	else if (f == -std::numeric_limits<float>::infinity())
		std::cout << "-inff\n";
	else if (f - (int)f == 0)
		std::cout << f << ".0f\n";
	else
		std::cout << f << "f\n";
}

void	printDouble(double value)
{
	std::cout << "double: ";
	if (value != value)
		std::cout << "nan\n";
	else if (value == std::numeric_limits<double>::infinity())
		std::cout << "+inf\n";
	else if (value == -std::numeric_limits<double>::infinity())
		std::cout << "-inf\n";
	else if (value - (int)value == 0)
		std::cout << value << ".0\n";
	else
		std::cout << value << "\n";
}

bool	is_Int_Overflow(std::string s)
{
	std::string t = s;
	size_t i = 0;
	bool neg = false;

	if (i < t.length() && (t[i] == '+' || t[i] == '-'))
	{
		if (t[i] == '-')
			neg = true;
		i++;
	}
	
	// Strip leading zeros from the numeric part
	while (i < t.length() && t.length() > 1 && t[i] == '0')
		t.erase(i, 1);
	
	// Recalculate actual digit length (excluding sign)
	size_t digit_start = (s[0] == '+' || s[0] == '-') ? 1 : 0;
	size_t digit_len = t.length() - digit_start;
	
	if (digit_len > 10)
		return false;
	if (digit_len < 10)
		return true;
	
	// Extract just the numeric part for comparison
	std::string num_part = t.substr(digit_start);
	
	if (!neg && num_part > "2147483647")
		return false;
	if (neg && num_part > "2147483648")
		return false;

	return true;
}

const std::string FLOAT_MAX_STR = "340282346638528859811704183484516925440.0";
const std::string DOUBLE_MAX_STR = "179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0";

std::string strip_leading_zeros(const std::string &s)
{
	if (s.empty())
		return s;
	
	size_t i = 0;
	while (i < s.length() - 1 && s[i] == '0')
		i++;
	return s.substr(i);
}

bool string_greater(const std::string &a, const std::string &b)
{
	std::string sa = strip_leading_zeros(a);
	std::string sb = strip_leading_zeros(b);

	if (sa.length() > sb.length())
		return true;
	if (sa.length() < sb.length())
		return false;

	return sa > sb;
}

bool isFloat_Overflow(std::string s)
{
	if (s.empty())
		return false;
	
	if (s[0] == '-' || s[0] == '+')
		s = s.substr(1);

	if (!s.empty() && (s[s.length() - 1] == 'f' || s[s.length() - 1] == 'F'))
		s.resize(s.length() - 1);

	if (s.empty())
		return false;

	s = strip_leading_zeros(s);

	return string_greater(s, FLOAT_MAX_STR);
}

bool isDouble_Overflow(std::string s)
{
	if (s.empty())
		return false;
	
	if (s[0] == '-' || s[0] == '+')
		s = s.substr(1);

	if (s.empty())
		return false;

	s = strip_leading_zeros(s);

	return string_greater(s, DOUBLE_MAX_STR);
}

void	ScalarConverter::convert(std::string s)
{
	bool	int_Overflow = false;
	bool	float_Overflow = false;
	bool	double_Overflow = false;
	
	// Check int overflow
	if (isInt(s) && !is_Int_Overflow(s))
		int_Overflow = true;
	
	// Check float overflow for all numeric types
	if (isFloat(s))
	{
		if (isFloat_Overflow(s))
			float_Overflow = true;
	}
	else if (isInt(s) || isDouble(s))
	{
		// For int or double input, check if it would overflow float
		if (isFloat_Overflow(s))
			float_Overflow = true;
	}
	
	// Check double overflow for all numeric types
	if (isDouble(s))
	{
		if (isDouble_Overflow(s))
			double_Overflow = true;
	}
	else if (isInt(s) || isFloat(s))
	{
		// For int or float input, check if it would overflow double
		std::string temp = s;
		if (isFloat(s))
			temp = s.substr(0, s.length() - 1); // Remove 'f'
		if (isDouble_Overflow(temp))
			double_Overflow = true;
	}

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
			break;
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
			else if (s == "+inff")
				value = std::numeric_limits<float>::infinity();
			else if (s == "-inff")
				value = -std::numeric_limits<float>::infinity();
			break;
		}
		case SPECIAL_DOUBLE:
		{
			if (s == "nan")
				value = std::numeric_limits<double>::quiet_NaN();
			else if (s == "+inf")
				value = std::numeric_limits<double>::infinity();
			else if (s == "-inf")
				value = -std::numeric_limits<double>::infinity();
			break;
		}
		default:
			std::cout << "Invalid input\n";
			return;
	}
	
	printChar(value);
	
	if (int_Overflow)
		std::cout << "int: impossible\n";
	else
		printInt(value);

	if (float_Overflow)
		std::cout << "float: impossible\n";
	else
		printFloat(value);

	if (double_Overflow)
		std::cout << "double: impossible\n";
	else
		printDouble(value);
}
*/


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
	// Check for NaN
	if (value != value)
	{
		std::cout << "impossible\n";
		return;
	}
	// Check if value is within valid char range (0-127 for ASCII)
	if (value < 0 || value > 127)
	{
		std::cout << "impossible\n";
		return;
	}

	char c = static_cast<char>(value);
	if (std::isprint(c))
		std::cout << "'" << c << "'\n";
	else
		std::cout << "Non displayable\n";
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

	if (f != f)
		std::cout << "nanf\n";
	else if (f == std::numeric_limits<float>::infinity())
		std::cout << "+inff\n";
	else if (f == -std::numeric_limits<float>::infinity())
		std::cout << "-inff\n";
	else if (f - (int)f == 0)
		std::cout << f << ".0f\n";
	else
		std::cout << f << "f\n";
}

void	printDouble(double value)
{
	std::cout << "double: ";
	if (value != value)
		std::cout << "nan\n";
	else if (value == std::numeric_limits<double>::infinity())
		std::cout << "+inf\n";
	else if (value == -std::numeric_limits<double>::infinity())
		std::cout << "-inf\n";
	else if (value - (int)value == 0)
		std::cout << value << ".0\n";
	else
		std::cout << value << "\n";
}

bool	is_Int_Overflow(std::string s)
{
	std::string t = s;
	size_t i = 0;
	bool neg = false;

	if (i < t.length() && (t[i] == '+' || t[i] == '-'))
	{
		if (t[i] == '-')
			neg = true;
		i++;
	}

	// Strip leading zeros from the numeric part
	while (i < t.length() && t.length() > 1 && t[i] == '0')
		t.erase(i, 1);
	
	// Recalculate actual digit length (excluding sign)
	size_t digit_start = (s[0] == '+' || s[0] == '-') ? 1 : 0;
	size_t digit_len = t.length() - digit_start;

	if (digit_len > 10)
		return false;
	if (digit_len < 10)
		return true;
	
	// Extract just the numeric part for comparison
	std::string num_part = t.substr(digit_start);

	if (!neg && num_part > "2147483647")
		return false;
	if (neg && num_part > "2147483648")
		return false;

	return true;
}

const std::string FLOAT_MAX_STR = "340282346638528859811704183484516925440.0";
const std::string DOUBLE_MAX_STR = "179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0";

std::string strip_leading_zeros(const std::string &s)
{
	if (s.empty())
		return s;

	size_t i = 0;
	while (i < s.length() - 1 && s[i] == '0')
		i++;
	return s.substr(i);
}

bool string_greater(const std::string &a, const std::string &b)
{
	if (a.length() > b.length())
		return true;
	if (a.length() < b.length())
		return false;

	return a > b;
}

bool	isFloat_Overflow(std::string s)
{
	if (s.empty())
		return false;

	if (s[0] == '-' || s[0] == '+')
		s = s.substr(1);

	if (!s.empty() && (s[s.length() - 1] == 'f' || s[s.length() - 1] == 'F'))
		s.resize(s.length() - 1);

	if (s.empty())
		return false;

	s = strip_leading_zeros(s);

	return string_greater(s, FLOAT_MAX_STR);
}

bool isDouble_Overflow(std::string s)
{
	if (s.empty())
		return false;
	
	if (s[0] == '-' || s[0] == '+')
		s = s.substr(1);

	if (s.empty())
	{
		std::cout << "is empty\n";
		return false;
	}

	s = strip_leading_zeros(s);

	return string_greater(s, DOUBLE_MAX_STR);
}

void	ScalarConverter::convert(std::string s)
{
	bool	int_Overflow = false;
	bool	float_Overflow = false;
	bool	double_Overflow = false;
	
	// Check int overflow
	if (isInt(s) && !is_Int_Overflow(s))
		int_Overflow = true;

	// Check float overflow for all numeric types
	if (isFloat(s))
	{
		if (isFloat_Overflow(s))
			float_Overflow = true;
	}
	else if (isInt(s) || isDouble(s))
	{
		// For int or double input, check if it would overflow float
		if (isFloat_Overflow(s))
			float_Overflow = true;
	}

	// Check double overflow for all numeric types
	if (isDouble(s))
	{
		if (isDouble_Overflow(s))
			double_Overflow = true;
	}
	else if (isInt(s) || isFloat(s))
	{
		// For int or float input, check if it would overflow double
		std::string temp = s;
		if (isFloat(s))
			temp = s.substr(0, s.length() - 1); // Remove 'f'
		if (isDouble_Overflow(temp))
			double_Overflow = true;
	}

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
			break;
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
			else if (s == "+inff")
				value = std::numeric_limits<float>::infinity();
			else if (s == "-inff")
				value = -std::numeric_limits<float>::infinity();
			break;
		}
		case SPECIAL_DOUBLE:
		{
			if (s == "nan")
				value = std::numeric_limits<double>::quiet_NaN();
			else if (s == "+inf")
				value = std::numeric_limits<double>::infinity();
			else if (s == "-inf")
				value = -std::numeric_limits<double>::infinity();
			break;
		}
		default:
			std::cout << "Invalid input\n";
			return;
	}
	
	printChar(value);
	
	if (int_Overflow)
		std::cout << "int: impossible\n";
	else
		printInt(value);

	if (float_Overflow)
		std::cout << "float: impossible\n";
	else
		printFloat(value);

	if (double_Overflow)
		std::cout << "double: impossible\n";
	else
		printDouble(value);
}


// websserve rst
// amine mountassir| philo
// lahla