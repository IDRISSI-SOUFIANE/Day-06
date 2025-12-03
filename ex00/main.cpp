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
					return (std::cout << "^^^^^^^^^^###!!@@error\n" , 1337);
				if (flagSpace == 1 && j != input.length())
					return (std::cout << "!!@@error\n" , 1337);
				if ((input[i] == 'f' || input[i] == 'F') && input[i+1] != '\0')
					return (std::cout << ">>>###!!@@error\n" , 1337);
				if (input[input.length() - 1] != '.' && input[input.length() - 1] != 'f'
					&& input[input.length() - 1] != 'F' && !isdigit(input[input.length() - 1]))
					return (std::cout << "###!!@@error\n" , 1337);
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
	std::cout << "continue\n";

	// I don't know if I should work with stringstream
}








// int	main()
// {
// 	float c = '    ';


// 	if (isdigit (c))
// 		std::cout << "yes \n";
// 	else
// 		std::cout << "NO \n";


// 	std::cout << c << "\n";
// }
