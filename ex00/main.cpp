/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidrissi <sidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 10:44:28 by sidrissi          #+#    #+#             */
/*   Updated: 2025/12/03 12:09:19 by sidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <sstream>

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

bool	isSpecialFloat(std::string s)
{
	return (s == "nanf" || s == "+inff" || s == "-inff");
}

bool	isSpecialDouble(std::string s)
{
	return (s == "nan" || s == "+inf" || s == "-inf");
}

LiteralType	detectType(std::string s)
{
	if (isSpecialFloat(s))
		return (SPECIAL_FLOAT);
	if (isSpecialDouble(s))
		return (SPECIAL_DOUBLE);
	if (s.length() == 1 || !std::isdigit(s[0]))
		return (CHAR);
	
	std::istringstream isINT(s);
	int	intVal;
	char c;

	// INT
	if (isINT >> intVal)
	{
		if (!(isINT >> c))
			return INT;
	}

	//  FLOAT
	if (s[s.length() - 1] == 'f')
	{
		std::string temp = s.substr(0, s.length() - 1);
		std::istringstream isFLOAT(temp);
		float fval;
		if (isFLOAT >> fval)
		{
			char leftover;
			if (!(isFLOAT >> leftover))
				return FLOAT;
		}
	}
	
	// double
	std::istringstream isDOUBLE (s);
	double dVAL;

	if (isDOUBLE >> dVAL)
	{
		char leftover;
		if (!(isDOUBLE >> leftover))
			return DOUBLE;
	}

	return (INVALID);
}

int	ft_check(std::string input)
{
	int	i = 0;
	int	countv = 0;
	int	countf = 0;
	int	countc = 0;
	int	isOneEle = 0;
	int	flagSpace = 0;

	while (input[i] == ' ')
		i++;
	i = 0;
	while (input[i])
	{
		if (input[i] == '.')
			countv++;
		else if (input[i] == 'f' || input[i] == 'F')
			countf++;
		else if (isalpha(input[i]))
			countc++;
		i++;
	}

	if (countv > 1 || countf > 1 || countc > 1)
		return (printf("-->error\n"), 1337);

	i = 0;
	if (input.length() == 1)
		return ((isOneEle = 1), printf("isOneEle\n"), 0);
	else
	{
		while (input[i])
		{
			if (!isdigit(input[i]))
			{
				int j = i;
				if (input[j] == ' ')
				{
					flagSpace = 1;
					while (input[j] == ' ')
						j++;
				}
				if (input[i] != '.' && input[i] != 'f'
					&& input[i] != 'F' && !isdigit(input[i]))
					return (std::cerr << "ERROR: \n" , 1337);
				if (flagSpace == 1 && j != input.length())
					return (std::cerr << "ERROR: \n" , 1337);
				if ((input[i] == 'f' || input[i] == 'F') && input[i+1] != '\0')
					return (std::cerr << "ERROR: \n" , 1337);
				if (input[input.length() - 1] != '.' && input[input.length() - 1] != 'f'
					&& input[input.length() - 1] != 'F' && !isdigit(input[input.length() - 1]))
					return (std::cerr << "ERROR: \n" , 1337);
			}
			i++;
		}
	}

	return (0);
}

int	main(int ac, char **av)
{
	if (ac != 2 || av[1][0] == '\0')
		return (printf("here\n"), 1);
	if (ft_check(av[1]) == 1337)
		return ( std::cout << "enter valid input: \n",  1);
	
	if (detectType(av[1]) == INVALID)
	{
		return (1337);
	}
	std::cout << "continue\n";

	// I don't know if I should work with stringstream
}




// #include <sstream>
// #include <iostream>

// int	main()
// {
	// std::string str = "123";

	// int num;
	// std::stringstream ss(str);

	// ss >> num;

	// ====================== TEST2: ================================

	// std::string str = "12 3abc";

	// int					num;
	// std::string			text;
	// std::stringstream	ss(str);

	// ss >> num ;
	// ss >> text;

	// std::cout << "num: " << num << "\n";
	// std::cout << "text: " << text << "\n";

	// ====================== TEST3: ================================

	// std::string str = "abc123";

	// int num;
	// std::string text;
	// std::stringstream ss(str);
	
	// ss >> num;
	// ss >> text ;

	// std::cout << "num: " << num << "\n";
	// std::cout << "text: " << text << "\n";
	// ====================== TEST4: ================================

// 	int t = 123;

// 	std::string text;

// 	std::stringstream ss;
// 	ss << t;

// 	ss >> text;

// 	std::cout << "num: " << text << "\n";   // prints "123"

	// ====================== TEST5: ================================
	// std::string	t = "abc";

	// int x;
	// std::stringstream ss(t);

	// ss >> x;

	// std::cout << x << std::endl;
	// ====================== TEST6: ================================



	// float t = 12.3;

	// std::string x;
	// std::stringstream ss;

	// ss << t;
	// ss >> x;

	// std::cout << x << std::endl;

// }




// int	main()
// {
// 	float c = '    ';


// 	if (isdigit (c))
// 		std::cout << "yes \n";
// 	else
// 		std::cout << "NO \n";


// 	std::cout << c << "\n";
// }
















































/*

#include <stdio.h>
#include <math.h>

int main() {
    // Positive infinities
    float  f_inf  = INFINITY;
    double d_inf  = INFINITY;

    // Negative infinities
    float  f_ninf = -INFINITY;
    double d_ninf = -INFINITY;

    // NaNs
    float  f_nan  = nanf("");
    double d_nan  = nan("");

    printf("float +inf  -> %f\n", f_inf);
    printf("double +inf -> %f\n", d_inf);

    printf("float -inf  -> %f\n", f_ninf);
    printf("double -inf -> %f\n", d_ninf);

    printf("float nanf  -> %f\n", f_nan);
    printf("double nan  -> %f\n", d_nan);

    return 0;
}
*/