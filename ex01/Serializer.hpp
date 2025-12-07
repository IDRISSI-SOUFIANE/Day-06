/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidrissi <sidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 11:47:32 by sidrissi          #+#    #+#             */
/*   Updated: 2025/12/07 13:41:00 by sidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <cstdint>

struct	Data
{
	int	id;
	std::string name;
};

class	Serializer
{
	public:
		// orthodox:
		Serializer();
		~Serializer();
		Serializer(Serializer const& other);
		Serializer &operator=(Serializer const& other);

		static uintptr_t	serialize(Data *ptr);
		static	Data* 		deserialize(uintptr_t raw);
};



#endif
