/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidrissi <sidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 12:19:25 by sidrissi          #+#    #+#             */
/*   Updated: 2025/12/10 13:28:52 by sidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
#include <string>

struct	Data
{
	int	id;
	std::string name;
    Data();
    Data(int id, std::string name);
    ~Data(void);
};

#endif