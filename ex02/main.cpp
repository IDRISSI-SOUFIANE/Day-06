/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidrissi <sidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 09:22:10 by sidrissi          #+#    #+#             */
/*   Updated: 2025/12/10 13:50:57 by sidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*	generate(void)
{
	std::srand(std::time(0));
	int r = std::rand() % 3;
	if (r == 0)
		return (new A);
	if (r == 1)
		return (new B);
	return (new C);
}


void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A\n";	
	else if (dynamic_cast<B*>(p))
		std::cout << "B\n";
	else if (dynamic_cast<C*>(p))
		std::cout << "C\n";
	else
		std::cout << "Unknown\n";
}

void	identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A\n";
		return ;
	}
	catch (...)
	{}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B\n";
		return ;
	}
	catch (...)
	{}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C\n";
		return ;
	}
	catch (...)
	{}
}
int main()
{
	Base*	p = generate();

	std::cout << "Identif with pointer: ";
	identify(p);
	std::cout << "Identif with refernce: ";
	identify(*p);

	delete p;
}

