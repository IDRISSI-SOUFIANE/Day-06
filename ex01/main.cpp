/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidrissi <sidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 12:14:34 by sidrissi          #+#    #+#             */
/*   Updated: 2025/12/10 13:29:30 by sidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
	// Create Data object
	Data d;

	// Pointer to that object
	Data* ptr = &d;

	// Serialize (pointer → integer)
	uintptr_t raw = Serializer::serialize(ptr);

	// Deserialize (integer → pointer)
	Data* restored = Serializer::deserialize(raw);

	// Show everything
	std::cout << "Original pointer : " << ptr << "\n";
	std::cout << "Serialized (raw) : " << raw << "\n";
	std::cout << "Restored pointer : " << restored << "\n\n";

	std::cout << "Restored Data:\n";
	std::cout << "  number = " << restored->id << "\n";
	std::cout << "  text   = " << restored->name << "\n";

	return 0;
}
