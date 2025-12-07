/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidrissi <sidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 13:41:05 by sidrissi          #+#    #+#             */
/*   Updated: 2025/12/07 16:10:20 by sidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
	// std::cout << "Default";

}

Serializer::Serializer(Serializer const& other)
{
	*this = other;
	// std::cout << "Copy Constructer\n"
}

Serializer &Serializer::operator=(Serializer const& other)
{
	if (this != &other)
		std::cout << "copy assignment\n";
	return (*this);
}

Serializer::~Serializer()
{
	std::cout << "Destructor\n";
}

uintptr_t Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}


Data* 		Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}


