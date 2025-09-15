/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 10:51:37 by aberenge          #+#    #+#             */
/*   Updated: 2025/09/15 12:55:36 by aberenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>

int	main(void)
{
	Base	*ptr;

	for (int i = 0; i < 10; i++)
	{
		ptr = generate();
		std::cout << "Generated object type (pointer): ";
		identify(ptr);
		std::cout << "Generated object type (reference): ";
		identify(*ptr);
		delete ptr;
		std::cout << std::endl;
	}
	std::cout << std::endl;
	ptr = new A();
	std::cout << "A instance (pointer): ";
	identify(ptr);
	std::cout << "A instance (reference): ";
	identify(*ptr);
	delete ptr;
	ptr = new B();
	std::cout << "B instance (pointer): ";
	identify(ptr);
	std::cout << "B instance (reference): ";
	identify(*ptr);
	delete ptr;
	ptr = new C();
	std::cout << "C instance (pointer): ";
	identify(ptr);
	std::cout << "C instance (reference): ";
	identify(*ptr);
	delete ptr;
	return (0);
}
