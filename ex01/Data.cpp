/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidrissi <sidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 12:20:35 by sidrissi          #+#    #+#             */
/*   Updated: 2025/12/10 13:29:26 by sidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() : id(1337), name("unknown")
{}

Data::Data(int id, std::string name) : id(id), name(name)
{
	std::cout << "Default Constructer\n";
}

Data::~Data()
{
	std::cout << "Destructer\n";
}
