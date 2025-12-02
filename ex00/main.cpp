/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidrissi <sidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 10:44:28 by sidrissi          #+#    #+#             */
/*   Updated: 2025/12/02 13:06:11 by sidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// double FF ff
// 42,   2f

int	ft_check(std::string input)
{
	int	i;
	int	countv;
	int	countf;

	countv = 0;
	countf = 0;
	i = 0;
	while (input[i] == ' ')
		i++;
	i = 0;
	while (input[i])
	{
		if (input[i] == '.')
			countv++;
		else if (input[i] == 'f' || input[i] == 'F')
			countf++;
		i++;
	}

	if (countv > 1 || countf > 1)
		return (printf("-->error\n"), 1);

	i = 0;
	while (input[i] == ' ')
		i++;
	
	while (input[i])
	{
		if (!isdigit(input[i]) && input[i] != '.'
			&& input[i] != 'f' && input[i] != 'F')
		{
			int j = i;
			if (input[j] == ' ')
			{
				while (input[j] == ' ')
					j++;
			}
			if (j != input.length())
				return (std::cout << "!!error\n" , 1);
			else if (input[i] != ' ')
				return (std::cout << "!!error\n" , 1);
		}
		i++;
	}

	return (0);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	if (ft_check(av[1]))
		return ( std::cout << "enter valid input: \n",  1);
	std::cout << "continue\n";

	// should work with stringstream
}





// int	main()
// {
// 	float c  =        42.2ff              ;


// 	if (isdigit (c))
// 		std::cout << "yes \n";
// 	else
// 		std::cout << "NO \n";


// 	std::cout << c << "\n";
// }
